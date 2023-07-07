#include <bits/stdc++.h>

using namespace std;

#define INF 10005
int D[INF], V[INF];
vector<int> g[INF];

void dfs(int u) {
	V[u] = 1;
	for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (V[v]) continue;
		D[v] = D[u]+1;
		dfs(v);
	}
}
int diam_arb(int n) {
    memset(V, 0, sizeof(V));
    D[1] = 0, dfs(1);
    
    int p = (int)(max_element(D + 1, D + n + 1) - D);
    memset(V, 0, sizeof(V));
    D[p] = 0, dfs(p);
    return *(max_element(D + 1, D + n + 1));
}
int main() {
    int test, n, m, x;
    scanf("%d", &test);
    while(test--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &m);
            g[i].clear();
            for (int j = 0; j < m; j++) {
                scanf("%d", &x);
                g[i].push_back(x);
            }
        }
        printf("%d\n", (2 * n - 2) - diam_arb(n));
    }
    return 0;
}