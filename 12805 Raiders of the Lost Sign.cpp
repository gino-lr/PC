// Gino Liza

#include <bits/stdc++.h>

using namespace std;

int primos[66] = {2};
bitset<317 / 2 + 1> es_primo;

void criba()
{
    es_primo.set();

    for (int i = 3; i * i <= 317; i += 2)
        if (es_primo[i / 2])
            for (int j = i * i; j <= 317; j += 2 * i)
                es_primo[j / 2] = false;

    for (int i = 1, j = 3; j <= 317; j += 2)
        if (es_primo[j / 2])
            primos[i++] = j;
}

int sec(int n) { return n * n; }

int casos, caso;
int n;

int main()
{
    criba();

    cin >> casos;

    for (caso = 1; caso <= casos; caso++)
    {
        cin >> n;

        bool ans = true;

        for (int i = 0; i < 66 && sec(primos[i]) <= n; i++)
        {
            while (n % primos[i] == 0)
            {
                n /= primos[i];
                if (primos[i] % 4 == 1)
                    ans = !ans;
            }
        }

        if (n > 1 && n % 4 == 1)
            ans = !ans;

        printf("%c\n", ans ? '+' : '-');
    }

    return 0;
}
