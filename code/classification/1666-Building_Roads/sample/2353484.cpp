#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define sz(x) (int)(x).size()
// #define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
  
const int M = 1000000007;
const char nl = '\n';
 
map<int, vector<int>> g ;
vector<int>vis ;
 
int par(int n) {
	while (vis[n] >=0 ) n= vis[n] ;
	return n ;
}
 
void unio(int u, int v) {
	if (vis[u]>vis[v]) {
		vis[v] += vis[u] ;
		vis[u] = v; 
	}
	else {
		vis[u] += vis[v] ;
		vis[v] = u; 
	}
}
 
void solve() {
	int n , m; 
	cin >> n>>m; 
	vis.resize(n+1, -1) ;
	for (int i=0 ; i< m; i++) {
		int x, y; cin >> x >> y ;
		int u  =par(x);
		int v =par(y) ;
		if(u!=v) unio(u,v) ;
	}
	vis[0] = INT_MAX; 
	// for (auto x :vis) cout << x << " ";
	// 	cout << nl; 
	int count =0 ;
	for (auto x : vis) count += x<0 ? 1 : 0;
	cout << count-1 << nl ;
	int prev =-1 ;
	for (int i=1 ; i<=n; i++){
		if (vis[i]<0) {
			if (prev != -1) cout << prev << " " << i << nl;
			prev = i;
		}
	}
 
 
	
}
 
	
 
int main(){
 #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 #endif
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int t; 
  t=1 ; // t=1 ;
 // cin >> t;
 
 while (t--) {
 	solve(); 
 }
 
}
