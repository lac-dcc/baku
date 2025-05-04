#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> mp;
vector<int> vis;
vector<int> dist;
int n, node;
int dia;
 
void diameter(int s, int d)
{
	if(vis[s]) return;
	vis[s] = 1;
	dist[s] = max(dist[s], d);
	if(d > dia) 
	{
		dia = d;
		node = s;
	}
	for(auto x : mp[s])
	{
		diameter(x, d+1);
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	cin >> n;
	mp.clear();
	for(int i=1; i<n; i++)
	{
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	dist.assign(n+1, -1);
	dia = 0;
	vis.assign(n+1, 0);
	diameter(1, 0);
	dia = 0;
	vis.assign(n+1, 0);
	diameter(node, 0);
	dia = 0;
	vis.assign(n+1, 0);
	diameter(node, 0);
	for(int i=1; i<=n; i++) cout << dist[i] << " ";
	return 0;
}
