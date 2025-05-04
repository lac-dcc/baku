#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
 
const int N=100001;
const int inf=1e18;
 
vector<pair<int,int>> adj[N];
vector<pair<int,int>> adj1[N];
vector<tuple<int,int,int>> edges;
int dis[N];
int n, m;
 
void dijkstra(int src, vector<pair<int,int>> adjj[]){
	for (int i=1; i<=n; ++i)
		dis[i]=inf;
	dis[src]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,src});
	while(!q.empty()){
		pair<int,int> p=q.top(); q.pop();
		int v=p.second;
		if(p.first>dis[v])
			continue;
		for (auto u:adjj[v]){
			int d=u.second;
			int c=u.first;
			if(dis[v]+d<dis[c]){
				dis[c]=dis[v]+d;
				q.push({dis[c],c});
			}
		}
	}
}
 
int32_t main(){
	cin >> n >> m;
	for (int i=0; i<m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u,v,w});
		adj[u].push_back({v,w});
		adj1[v].push_back({u,w});
	}
	int a[N], b[N];
	dijkstra(1,adj);
	for (int i=0; i<N; ++i)
		a[i]=dis[i];
	dijkstra(n, adj1);
	for (int i=0; i<N; ++i)
		b[i]=dis[i];
	int ans=1e18;
	for (auto [u, v, w] : edges){
		ans=min(ans,a[u]+b[v]+w/2);
	}
	cout << ans << "\n";
}