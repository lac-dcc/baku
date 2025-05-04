#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
using namespace std;
 
#define endl "\n"
#define int long long int
#define f(i,x,n)        for(int i=x; i<n; i++)
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define ff first
#define s second
 
void addEdge(vector<int>adj[], int u, int v, bool bidir = true) {
	adj[u].push_back(v);
	if (bidir == true)
		adj[v].push_back(u);
}
 
void dfs(vector<int>adj[], int s, vi &vis) {
	vis[s] = 1;
 
	for (auto child : adj[s]) {
		if (!vis[child]) {
			dfs(adj, child, vis);
		}
	}
}
 
void solve() {
	int n; cin >> n;
	vi a(n); f(i, 0, n) cin >> a[i];
 
	int maxso = INT_MIN, maxs = 0;
	for (int i = 0; i < n; i++) {
		maxs += a[i];
		maxso = max(maxs, maxso);
		maxs = ((maxs < 0) ? 0 : maxs);
	}
 
	cout << maxso << endl;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	// int T;
	// cin >> T;
	// // cin.ignore(); must be there when using getline(cin, s)
	// while (T--)
	// {
	solve();
	// }
	return 0;
}
 
 
// if (wt[i].ff + wt[end].ff > nsum || wt[end].s == 1) {
// 	end--;
// }
// else if (wt[start].s == 1) {
// 	start++;
// }
// else if ((nsum - (wt[i].ff + wt[start].ff)) < (nsum - (wt[i].ff + wt[end].ff))) {
// 	end--;
// }
// else if ((nsum - (wt[i].ff + wt[start].ff)) > (nsum - (wt[i].ff + wt[end].ff))) {
// 	start++;
// }
// else if ((nsum - (wt[i].ff + wt[start].ff)) == (nsum - (wt[i].ff + wt[end].ff))) {
// 	break;
// }
 
 
// if ((start == end || (wt[start].ff == wt[end].ff)) && ((wt[i].ff + wt[start].ff) <= nsum)) {
// 	wt[i].s = 1;
// 	wt[start].s = 1;
// 	// cout << wt[i].ff << " " << wt[start].ff << endl;
 
// 	count++;
// }
// else {
// 	if (wt[start].s == 1 || wt[start].s == 0) {
// 		count++;
// 		wt[i].s = 1;
 
// 		continue;
// 	}
// 	// cout << wt[i].ff << " " << wt[start].ff << endl;
 
// 	wt[i].s = 1;
// 	wt[start].s = 1;
 
// 	count += 2;
// }