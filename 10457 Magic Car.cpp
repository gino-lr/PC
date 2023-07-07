#include <bits/stdc++.h>

using namespace std;

struct estr
{
    int x, y, v;
    estr(int a = 0, int b = 0, int c = 0) : x(a), y(b), v(c) {}
    bool operator<(const estr &a) const
    {
        return v < a.v;
    }
};

estr D[10005];

int p[1005], r[1005];

int encdp(int x)
{
    return p[x] == x ? x : (p[x] = encdp(p[x]));
}

int joint(int x, int y)
{
    x = encdp(x), y = encdp(y);
    if (x == y)
        return 0;
    if (r[x] > r[y])
        r[x] += r[y], p[y] = x;
    else
        r[y] += r[x], p[x] = y;
    return 1;
}

int kruscal(int n, int m, estr D[], int st, int ed, int &max_aris)
{
    for (int i = 0; i <= n; i++)
        p[i] = i, r[i] = 1;
    for (int i = 0; i < m; i++)
    {
        if (joint(D[i].x, D[i].y))
        {
            if (encdp(st) == encdp(ed))
            {
                max_aris = D[i].v;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n, m, x, y, w;
    int a, b, q;
    while (scanf("%d %d", &n, &m) == 2 && n + m)
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &x, &y, &w);
            D[i] = estr(x, y, w);
        }
        sort(D, D + m);
        scanf("%d %d", &a, &b);
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d %d", &x, &y);
            int ret = 0x3f3f3f3f, arisMax;
            for (int i = 0; i < m; i++)
            {
                if (kruscal(n, m - i, D + i, x, y, arisMax))
                    ret = min(ret, arisMax - D[i].v);
                else
                    break;
            }
            printf("%d\n", a + b + ret);
        }
    }
    return 0;
}