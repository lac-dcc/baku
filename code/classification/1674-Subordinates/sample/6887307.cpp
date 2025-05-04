#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
void dfs(int s, vector<int> &subOrds, vector<bool> &vis, vector<vector<int> > &adj)
{
	vis[s] = true;
 
	for (auto nb: adj[s])
	{
		if (!vis[nb])
		{
			dfs(nb, subOrds, vis, adj);
			subOrds[s] += subOrds[nb] + 1;
		}
	}
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<vector<int> > adj(n);
 
	for (int i = 1; i < n; ++i)
	{
		int parent; cin >> parent;
		adj[parent - 1].push_back(i);
	}
	vector<bool> vis(n);
	vector<int> subOrds(n);
	dfs(0, subOrds, vis, adj);
	for (auto so : subOrds)
		cout << so << ' ';
}
