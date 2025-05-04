#include<bits/stdc++.h>
#define int long long
using namespace std;
 
void IOS()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
 
const int MX = 100005;
vector<int> adj[MX];
 
void dfs(int u, vector<int> *adj, vector<bool> &vis)
{
	vis[u] = true;
	for (int x : adj[u])
	{
		if (!vis[x])
			dfs(x, adj, vis);
	}
}
 
void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	vector<bool> vis(n + 1, false);
	vector<pair<int, int>> roads;
	int ct = 0, last = -1;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			dfs(i, adj, vis);
			ct++;
			if (ct > 1)
				roads.push_back({last, i});
			last = i;
		}
	}
 
	cout << roads.size() << endl;
	for (auto p : roads)
		cout << p.first << " " << p.second << endl;
	cout << endl;
}
 
int32_t main()
{
	IOS();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
