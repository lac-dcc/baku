#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define inf (1LL<<60)
#define siz 500000
using namespace std;
 
void init() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
 
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);
	cout.precision(8);
}
 
vector<int> adj[siz];
int dp[siz], ht[siz];
 
int dfs(int u, int p) {
	ht[u] = 0;
	for(int v : adj[u]) 
		if(v != p) 
			ht[u] = max(ht[u], 1+dfs(v, u));
	return ht[u];
}
 
void dist(int u, int p, int par_ans) {
	vector<int> pref, suff;
	for(int v: adj[u])
		if(v != p)
			pref.pb(ht[v]), 
			suff.pb(ht[v]);
 
	for(int i = 1; i < pref.size(); i++)
		pref[i] = max(pref[i], pref[i-1]);
	for(int i = (int)suff.size()-2; i >= 0; i--)
		suff[i] = max(suff[i], suff[i+1]);
 
	int curr = 0; 
	for(int v: adj[u]) {
		if(v != p) {
			int op1 = (curr == 0) ? INT_MIN : pref[curr - 1];
            int op2 = (curr == (int)suff.size() - 1) ? INT_MIN : suff[curr + 1];
            int partial_ans = 1 + max(par_ans, max(op1,op2));
 
            dist(v, u, partial_ans);
            curr ++;
		}
	}
 
	dp[u] = 1 + max(par_ans, (pref.empty() ? -1: pref.back()));
}
 
int main(void) {
	init();
	int n, u, v; 
	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}	
	dfs(1, 0);
	dist(1, 0, -1);
	for(int i = 1; i <= n; i++)
		cout << dp[i] << " ";
	return 0;
}
