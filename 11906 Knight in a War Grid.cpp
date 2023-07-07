#include <bits/stdc++.h>

using namespace std;

int G[105][105];
bool V[105][105];
pair<int, int> BFS(int, int, int, int);

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int test, r, c, m, n, w, x, y, t;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        cin >> r >> c >> m >> n;
        cin >> w;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                G[i][j] = 0;
                V[i][j] = false;
            }
        }
        while (w--)
        {
            cin >> x >> y;
            G[x][y] = -1;
        }
        pair<int, int> ans = BFS(r, c, m, n);
        cout << "Case " << t << ": " << ans.first << " " << ans.second << "\n";
    }
    return 0;
}
pair<int, int> BFS(int r, int c, int m, int n)
{
    int dr[8] = {m, m, -m, -m, n, -n, n, -n};
    int dc[8] = {n, -n, n, -n, m, m, -m, -m};
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    V[0][0] = true;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        set<pair<int, int>> adj;
        for (int k = 0; k < 8; k++)
        {
            int i = dr[k] + p.first;
            int j = dc[k] + p.second;
            if (i >= 0 && j >= 0 && i < r && j < c && G[i][j] != -1)
                adj.insert(make_pair(i, j));
        }
        for (auto idx : adj)
        {
            G[idx.first][idx.second]++;
            if (!V[idx.first][idx.second])
            {
                V[idx.first][idx.second] = true;
                q.push(make_pair(idx.first, idx.second));
            }
        }
    }
    int par, impar;
    par = impar = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if ((G[i][j] != -1 && G[i][j] != 0) || (i == 0 && j == 0))
            {
                if (G[i][j] & 1)
                    impar++;
                else
                    par++;
            }
        }
    }
    return make_pair(par, impar);
}