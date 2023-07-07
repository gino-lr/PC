// Joel Challco
// Emanuel Galdos
// Gino Liza
// Missael Rodriguez

#include <bits/stdc++.h>

using namespace std;

#define For(i, a, b) for (int i = a; i <= b; i++)
#define maxN 100005

string palabra, ans;
int k;
map<string, int> indice;

void chck()
{
    int n = palabra.length(), _incide;
    For(i, 1, n - 1)
    {
        swap(palabra[i - 1], palabra[i]);
        _incide = indice[palabra];
        if (_incide > 0 && _incide < k)
        {
            ans = palabra;
            k = _incide;
            if (k == 1)
                return;
        }
        swap(palabra[i - 1], palabra[i]);
    }
    string temp;
    For(i, 0, n - 1)
    {
        temp = palabra;
        temp.erase(temp.begin() + i);
        _incide = indice[temp];
        if (_incide > 0 && _incide < k)
        {
            ans = temp;
            k = _incide;
            if (k == 1)
                return;
        }
    }
    For(i, 0, n)
    {
        temp = palabra;
        temp.insert(temp.begin() + i, 'a');
        for (temp[i] = 'a'; temp[i] <= 'z'; temp[i]++)
        {
            _incide = indice[temp];
            if (_incide > 0 && _incide < k)
            {
                ans = temp;
                k = _incide;
                if (k == 1)
                    return;
            }
        }
    }
    For(i, 0, n - 1)
    {
        char ch = palabra[i];
        for (palabra[i] = 'a'; palabra[i] <= 'z'; palabra[i]++)
        {
            _incide = indice[palabra];
            if (_incide > 0 && _incide < k)
            {
                ans = palabra;
                k = _incide;
                if (k == 1)
                    return;
            }
        }
        palabra[i] = ch;
    }
}

main()
{
    int n;
    char s[100];
    scanf("%d", &n);
    getchar();
    For(i, 1, n)
    {
        scanf("%s", &s);
        indice[s] = i;
    }
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        cin >> palabra;
        cout << palabra;
        if (indice[palabra])
            puts(" is correct");
        else
        {
            k = maxN;
            chck();
            if (k < maxN)
            {
                printf(" is a misspelling of ");
                cout << ans << endl;
            }
            else
                puts(" is unknown");
        }
    }
}