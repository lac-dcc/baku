#include <bits/stdc++.h>
#include <string.h>
#include <inttypes.h>
#define ll long long
#define vl vector<ll>
#define pll pair<ll,ll>
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define debug(x) cout<<#x<<" "<<x<<'\n';
#define tm template<typename dt>
#define cb(x) __builtin_popcountll(x)
#define tz(x) __builtin_ctzll(x)
using namespace std;
tm dt max_t(dt a,dt b){return (a>b)?a:b;}
tm dt min_t(dt a,dt b){return (a>b)?b:a;}
tm void swap(dt &a,dt &b){dt t=a;a=b;b=t;}
tm void swapx(dt &a,dt &b){a^=b;b^=a;a^=b;}
tm dt abs_t(dt a){return (a<0)?-a:a;}
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int expoMod(int a,int b,int m){int res = 1;a = a % m;while(b>0){ if(b&1)res = (res * a) % m;a = (a * a) % m;b >>= 1;}return res;}
int expo(int a,int b){int res = 1;while(b>0){ if(b>0)res = res * a;a = a * a;b >>= 1;}return res;}
int minvprime(int a,int b){ return expoMod(a,b-2,b); }
int mod_add(int a,int b,int m){a = a % m;b = b % m;return (((a + b) % m) + m) % m;}
int mod_mul(int a,int b,int m){a = a % m;b = b % m;return (((a * b) % m) + m) % m;}
int mod_sub(int a,int b,int m){a = a % m;b = b % m;return (((a - b) % m) + m) % m;}
int mod_div(int a,int b,int m){a = a % m;b = b % m;return (mod_mul(a, minvprime(b, m), m) + m) % m;}
tm dt gcd(dt a, dt b) {
    if (!a || !b)return a | b;unsigned shift = __builtin_ctz(a | b);a >>= __builtin_ctz(a);
    do {b >>= __builtin_ctz(b);if (a > b)swapx<dt>(a, b);b -= a;}while (b);
    return a << shift;
}
//__TEMPLATE___________________________________________________________________________________________________________________//
const int iinf = INT_MAX;
const ll inf = LLONG_MAX;
const int mod = 1e9 + 7;
const int mxN = 1e5 + 10;
vector<pll> adj[mxN];
vector<ll> d(mxN,inf);
vector<int> p(mxN,-1);
 
void Dijkstra(){
	d[1] = 0;
	set<pll> q;
	q.insert(make_pair(0,1));
	while(!q.empty()){
		ll dist = q.begin()->fi;
		ll u = q.begin()->se;
		q.erase(q.begin());
		for(auto e: adj[u]){
			if(d[e.fi] > e.se + d[u]){
				q.erase(make_pair(d[e.fi],e.fi));
				d[e.fi] = e.se + d[u];
				q.insert(make_pair(d[e.fi],e.fi));
			}
		}
	}
}
 
int main(){
	fio;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
 
	int n,m;
	ll v,c,u;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> u >> v >> c;
		adj[u].pb(make_pair(v,c));
	}
	Dijkstra();
	for(int i=1;i<=n;i++)cout << d[i] << '\n';
	return 0;
}
