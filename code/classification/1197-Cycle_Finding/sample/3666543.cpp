#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<bool, bool> pbb;
 
vector<vector<pll>> G;
vector<bool> visited, circle;
vector<ll> dp, route;
 
void dfs(ll v, ll p)
{
	visited[v] = true;
	for (ll i = 0; i < G[v].size(); i++)
	{
		ll u = G[v][i].first, w = G[v][i].second;
		if (u == p)
		{
			if (w < dp[v])
			{
				dp[v] = w;
				route[v] = u;
			}
		}
		if (!visited[u])
			dfs(u, p);
		if (dp[u] + w < dp[v])
		{
			dp[v] = dp[u] + w;
			route[v] = u;
		}
	}
}
 
bool comp(pll val1, pll val2)
{
	return val1.second < val2.second;
}
 
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	G.resize(n + 1), visited.resize(n + 1, false), circle.resize(n + 1, false);
	for (ll i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({ b, c });
	}
 
	for (ll i = 1; i <= n; i++)
		sort(G[i].begin(), G[i].end(), comp);
 
	bool ok = false;
	for (ll i = 1; i <= n && !ok; i++)
	{
		visited.clear();
		visited.resize(n + 1, false);
		dp.clear();
		dp.resize(n + 1, 1e18);
		route.clear();
		route.resize(n + 1, -1);
		dfs(i, i);
		if (dp[i]<0)
		{
			cout << "YES" << "\n";
			ll curr = i;
			while (route[curr]!=i)
			{
				cout << curr << " ";
				curr = route[curr];
			}
			cout << curr << " " << i;
			ok = true;
		}
	}
 
	if (!ok)
		cout << "NO";
	return 0;
}
