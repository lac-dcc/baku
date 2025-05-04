#include <bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define vll vector<ll>
#define pb push_back
 
ll f[200005], n ;
vll ch[200005] ;
 
void duyet(ll u) {
	for(ll v : ch[u]) {
		duyet(v) ;
		f[u] += f[v] + 1 ;
	}
}
 
int main() {
	cin >> n ;
	for(ll i = 2; i <= n; i ++) {
		ll x ; cin >> x ;
		ch[x].pb(i) ;
	}
	duyet(1) ;
	for(ll i = 1; i <= n; i ++) cout << f[i] << " " ;
}
