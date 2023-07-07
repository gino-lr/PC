#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define II ({int a; scanf("%d", &a); a;})
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )

vector< pair<int,int> >primeDivisors;

void generate_divisors(int n)
{
    primeDivisors.clear();

    int cnt = 0 ;

    while(n % 2 == 0 ){
        n>>=1 , cnt++;
    }

    if(cnt) primeDivisors.push_back( make_pair(2,cnt) );

    int sq = sqrt(n) + 1 ;

    for( int i = 3 ; i <= sq ; i += 2 ){
        cnt = 0 ;
        while(n % i == 0 ) n /= i , cnt++ ;
        if(cnt) primeDivisors.push_back( make_pair(i,cnt) );
    }

    if(n > 1 ) primeDivisors.push_back( make_pair(n,1) ) ;
}

int n , a , b ;
ll f[42];
map<ll ,ll >m;
int main(){
    f[0] = 0 ;
    f[1] = 1 ;
    forab(i,2,40) f[i] = f[i-1] + f[i-2];
    int t = II ;
    For(cs,t){
        m.clear();
        n = II , a = II , b = II ;
        generate_divisors(a);
        forstl(it,primeDivisors) {
            m[it->first] += f[n-1]*(it->second);
        }
        generate_divisors(b);
        forstl(it,primeDivisors){
            m[it->first] += f[n]*(it->second);
        }
        forstl(it,m)
            printf("%lld %lld\n",it->first,it->second);
        puts("");
    }
}