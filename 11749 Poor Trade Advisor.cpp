#include <bits/stdc++.h>

using namespace std;

vector<pair<int,long long int>> L[510];
int V[510];
int x, y;
long long int B;
int cont;

void dfs(int x){
    V[x] = 1;
    for(int i = 0; i < (int)L[x].size(); i++){
        int u = L[x][i].first;
        int target = L[x][i].second;
        if(V[u] == 0 && target == B){
            cont++;
            dfs(u);
        }
    }
}

int main(){
    int a, b;
    long long int P;
    int ans;
    while(true){
        for(int i = 0; i < 510; i++){
            L[i].clear();
        }
        memset(V, 0, sizeof V);
        B = -9999999999999; 
        ans = -1;
        scanf("%d %d", &x, &y);
        if(x == 0 && y == 0){
            break;
        }
        for(int i = 0; i < y; i++){
            scanf("%d %d %lld", &a, &b, &P);
            L[a].push_back({b,P});
            L[b].push_back({a,P});
            B = max(B, P);
        }
        for(int i = 1; i <= x; i++){
            if(V[i] == 0){
                cont = 0;
                dfs(i);
                ans = max(ans, cont);
            }
        }
        printf("%d\n", ans + 1);
    }
}