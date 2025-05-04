#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#define oo 1000000000000
#define ll long long
#define pii pair<long long, long long>
#define ull unsigned long long
#define st first
#define nd second
#define file "test"
using namespace std;
const long long N = 2e5 + 5;
 
ll n, m, q;
vector <pii> d[503];
ll stp[501][501];
bool visited[600];
void dijkstra(ll start)
{
	priority_queue <pii, vector <pii>, greater<pii>> q;
	q.push({0,start});
	while (q.size())
	{
		ll w = q.top().st, u = q.top().nd;
		q.pop();
		if (visited[u]) continue;
		visited[u] = true;
		stp[u][start] = w;
		for (pii v:d[u])
		if (!visited[v.st])
			q.push({w+v.nd,v.st});
	}
}
ll cross[501][501];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen(file".inp","r",stdin);
		freopen(file".out","w",stdout);
	#endif
	for (int i=1;i<=500;i++)
		for (int j=1;j<=500;j++)
			stp[i][j] = oo;
	cin >> n >> m >> q;
	for (int i=1;i<=m;i++)
	{
		ll u, v, z;
		cin >> u >> v >> z;
		stp[u][v] = stp[v][u] = min(z,stp[u][v]);
		cross[u][v] = cross[v][u] = true;
	}
	for (int i=1;i<=n;i++)
		stp[i][i] = 0;
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			{
				if (cross[i][k] && cross[j][k])
				{
					stp[i][j] = min(stp[i][k] + stp[j][k], stp[i][j]);
					cross [i][j] = true;
				}
			}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (stp[i][j] == oo)
					stp[i][j] = -1;
	while (q--)
	{
		ll u, v;
		cin >> u >> v;
		cout << stp[u][v] << '\n';
	}
	return 0;
}	
