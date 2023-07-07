#include <bits/stdc++.h>

#define INF 1000000000

using namespace std;
int tc, N, K, ans;
int g[80][80];
int dp[80][80][7];
bool used[80][80][7];

inline bool enRango(int x, int y)
{
    return x > 0 && y > 0 && x <= N && y <= N;
}

int arriba_abajo(int i, int j, int k)
{

    if (used[i][j][k])
        return dp[i][j][k];
    used[i][j][k] = true;
    dp[i][j][k] = -INF;
    int sum;
    int negs;
    int ans, jj;

    if (i == 1)
    {
        sum = 0;
        negs = k;
        for (jj = j; jj > 0; --jj)
        {
            if (g[i][jj] < 0)
                --negs;
            if (negs < 0)
                return dp[i][j][k] = -INF;
            sum += g[i][jj];
        }
        dp[i][j][k] = sum;
    }
    else
    {
        sum = 0;
        negs = k;
        for (jj = j; jj <= N; ++jj)
        {
            if (g[i][jj] < 0)
                --negs;
            if (negs < 0)
                break;
            sum += g[i][jj];
            ans = arriba_abajo(i - 1, jj, negs);
            if (ans != INF)
            {
                dp[i][j][k] = max(dp[i][j][k], ans + sum);
            }
        }
        sum = 0;
        negs = k;
        for (jj = j; jj > 0; --jj)
        {
            if (g[i][jj] < 0)
                --negs;
            if (negs < 0)
                break;
            sum += g[i][jj];
            ans = arriba_abajo(i - 1, jj, negs);
            if (ans != INF)
            {
                dp[i][j][k] = max(dp[i][j][k], ans + sum);
            }
        }
    }
    return dp[i][j][k];
}

int i, j, k, mx;

int main()
{
    while (cin >> N >> K, N || K)
    {
        for (i = 0; i < 80; ++i)
            for (j = 0; j < 80; ++j)
                for (k = 0; k < 7; ++k)
                    dp[i][j][k] = -INF;

        for (i = 1; i <= N; ++i)
            for (j = 1; j <= N; ++j)
                cin >> g[i][j];

        memset(used, 0, sizeof used);
        dp[1][1][g[1][1] < 0] = g[1][1];
        used[1][1][g[1][1] < 0] = true;

        mx = max(-INF, arriba_abajo(N, N, K));
        cout << "Case " << ++tc << ": ";
        if (mx < -INF / 2)
            cout << "impossible" << endl;
        else
            cout << mx << endl;
    }
}