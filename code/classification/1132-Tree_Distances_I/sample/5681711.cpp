// https://cses.fi/problemset/task/1132
// Tree Distances I
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int N = 2 * 1e5 + 1;
vector<int> adj[N], dp(N), ans(N);
 
void fastIO() {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL);
}
 
void dfs(int node, int par) {
 
	dp[node] = 0;
	for(auto &nbr : adj[node]) {
		if(nbr == par) continue;
 
		dfs(nbr, node);
		dp[node] = max(dp[node], 1 + dp[nbr]);
	}
}
 
void dfs2(int node, int par) {
 
	ans[node] = dp[node];
	int t1 = dp[node];
	vector<int> pre, suf;
	for(auto &nbr : adj[node]) {
		if(nbr == par) continue;
 
		pre.push_back(dp[nbr]);
		suf.push_back(dp[nbr]);
	}
 
	int sz = pre.size();
	for(int i = 1; i < sz; i++) {
		pre[i] = max(pre[i], pre[i - 1]);
	}
	for(int i = sz - 2; i >= 0; i--) {
		suf[i] = max(suf[i], suf[i + 1]);
	}
 
	int i = 0;
	for(auto &nbr : adj[node]) {
		if(nbr == par) continue;
 
		int l = 0, r = 0;
		int t2 = dp[nbr];
		bool fl = false;
		if(i - 1 >= 0) {
			l = pre[i - 1];
			fl = true;
		}
		if(i + 1 < sz) {
			r = suf[i + 1];
			fl = true;
		}
 
		dp[node] = fl ? 1 + max(l, r) : 0;
		if(par != 0) {
			dp[node] = max(dp[node], 1 + dp[par]);
		}
		dp[nbr] = max(dp[nbr], 1 + dp[node]);
 
		dfs2(nbr, node);
 
		dp[node] = t1;
		dp[nbr] = t2;
		i++;
	}
}
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    fastIO();
 
    int n;
    cin >> n;
 
    for(int i = 0; i < n - 1; i++) {
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
 
    dfs(1, 0);
    dfs2(1, 0);
 
    for(int i = 1; i <= n; i++) {
    	cout << ans[i] << ' '; 
    }
    
    return 0;
}
