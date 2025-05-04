#include<bits/stdc++.h>
using namespace std;
 
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<int, int>;
 
#define F first
#define S second
 
vvi g;
int indp[200200];
int outdp[200200];
 
vector<pi> storemax[200200];
 
void dfs1(int u, int p)
{
	indp[u] = 0;
 
	int res = 0;
	int max1 = 0, node1 = 0, max2 = 0, node2 = 0;
 
	for (auto v : g[u])
	{
		if (v != p)
		{
			dfs1(v, u);
			int curr = 1 + indp[v];
			res = max(res, curr);
			if (curr > max1)
			{
				max2 = max1;
				node2 = node1;
				max1 = curr;
				node1 = v;
			}
			else if (curr == max1 || curr >= max2)
			{
				max2 = curr;
				node2 = v;
			}
		}
	}
	storemax[u].push_back({max1, node1});
	storemax[u].push_back({max2, node2});
 
	indp[u] = res;
	return;
}
 
void dfs2(int u, int v)
{
	if (v == 0)
	{
		outdp[u] = 0;
	}
	else
	{
		int curr = storemax[v][0].F;
		if (storemax[v][0].S == u)
		{
			curr = storemax[v][1].F;
		}
		outdp[u] = 1 + max(outdp[v], curr);
	}
	for (auto ch : g[u])
	{
		if (ch != v)
		{
			dfs2(ch, u);
		}
	}
	return;
}
 
void solve()
{
	int n;
	cin >> n;
 
	memset(indp, -1, sizeof(indp));
	memset(outdp, -1, sizeof(outdp));
 
	for (int i = 0; i < 200200; i++)
	{
		storemax[i] = vector<pi>(0);
	}
 
	g = vvi(n + 1, vi(0));
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
 
	dfs1(1, 0);
	dfs2(1, 0);
 
	for (int i = 1; i <= n; i++)
	{
		cout << max(indp[i], outdp[i]) << " ";
	}
	cout << endl;
 
	return;
}
 
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	solve();
	return 0;
}
