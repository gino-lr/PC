#include <bits/stdc++.h>

#define Fast fasrerIO()

using namespace std;

typedef long long ll;
void fasrerIO() {ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0) ;}

int main() {
	Fast ;
	ll a, b , c ,d , e ;
	while(cin >> a >> b >> c >> d >> e) {
		if(!a && !b && !c && !d && !e )
			break ;
		cout << a * b * c * d * d * e * e << "\n" ;
	}
	return 0 ;
}