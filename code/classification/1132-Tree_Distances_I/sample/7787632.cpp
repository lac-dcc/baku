#include <bits/stdc++.h>
 
using namespace std;
 
#define SIZE(x) (int)x.size()
#define forn(i,n) for(int i=0;i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
typedef vector<int> vi;
const int MAXN = 2e5;
 
vi adj[MAXN];
int down[MAXN], ans[MAXN];
 
int dfs1(int u, int p=-1) {
	down[u] = 0;
	for(int v:adj[u]) if(v!=p) down[u] = max(down[u], dfs1(v,u)+1);
	return down[u];
}
 
void dfs2(int u, int p=-1, int up=0) {
	ans[u] = max(down[u], up);
	int sz = SIZE(adj[u]);
	if(sz==0) return;
	vi suffix(sz);
	suffix[sz-1] = -1;
	dforn(i,sz-1) {
	    int v = adj[u][i+1];
        if (v!=p) suffix[i] = max(suffix[i+1], down[v]);
        else suffix[i] = suffix[i+1];
	}
	int prefix = -1;
	forn(i,sz) {
		int v = adj[u][i];
		if (v!=p) {
			dfs2(v,u,max({up+1, prefix+2, suffix[i]+2}));
			prefix = max(prefix, down[v]);
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n; cin >> n;
 
    forn(i,n-1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
	dfs1(0);
	dfs2(0);
 
	forn(i,n) cout << ans[i] << ' ';
	
	return 0;
}
