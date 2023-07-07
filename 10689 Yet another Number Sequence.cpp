// Joel Challco
// Emanuel Galdos
// Gino Liza
// Missael Rodriguez

#include <bits/stdc++.h>

using namespace std;

long long mod = 0;

struct M
{
    long long a[2][2];
    M()
    {
        memset(a, 0, sizeof a);
    }
    void init()
    {
        a[0][0] = 1, a[0][1] = 1;
        a[1][0] = 1, a[1][1] = 0;        
    }

    M operator*(M temp)
    {
        M res;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                res.a[i][j] = 0;
                for (int k = 0; k < 2; k++)
                {
                    res.a[i][j] = (res.a[i][j] + (temp.a[i][k] * a[k][j])) % mod;
                }
            }
        }
        return res;
    }
};

M pot(M mat, long long n)
{
    if (n == 1)
        return mat;

    M res = pot(mat, n / 2);
    res = res * res;
    if ((n % 2) == 1)
        res = res * mat;

    return res;
}

M pot_M(M mat, long long n)
{
    M res = pot(mat, n);
    return res;
}

int main()
{
    long long n, t;
    struct M mat;

    scanf("%lld", &t);
    mat.init();
    while (t--)
    {
        long long x, y, n, m;
        scanf("%lld %lld %lld %lld", &x, &y, &n, &m);
        mod = powl(10, m);

        if (n <= 1)
        {
            if (n == 0)
                printf("%lld\n", x % mod);
            else
                printf("%lld\n", y % mod);
            continue;
        }

        M res = pot(mat, n - 1);
        printf("%lld\n", ((res.a[0][0] * y) % mod + (res.a[0][1] * x) % mod) % mod);
    }
    return 0;
}