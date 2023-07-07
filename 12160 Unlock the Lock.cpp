#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k = 0;
    int L, U, R;
    int RV[20];
    while (scanf("%d %d %d", &L, &U, &R) == 3)
    {
        if (!L && !U && !R)
            break;
        int i, tmp;
        
        for (i = 0; i < R; i++)
            scanf("%d", &RV[i]);
        
        short dinamico[10000] = {};
        
        queue<int> cola;
        dinamico[L] = 1;
        cola.push(L);
        
        while (!cola.empty())
        {
            if (dinamico[U])
                break;
            L = cola.front(), cola.pop();
            for (i = 0; i < R; i++)
            {
                tmp = L + RV[i];
                if (tmp >= 10000)
                    tmp -= 10000;
                
                if (dinamico[tmp] == 0)
                {
                    dinamico[tmp] = dinamico[L] + 1;
                    cola.push(tmp);
                }
            }
        }
        printf("Case %d: ", ++k);
        if (dinamico[U])
            printf("%d\n", dinamico[U] - 1);
        else
            puts("Permanently Locked");
    }
    return 0;
}