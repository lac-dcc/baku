#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pi  pair<int,int>
#define pii pair<int,pair<int,int>>
#define fi first
#define se second
#define heapu(t) priority_queue<t>
#define heapd(t) priority_queue<t, vector<t>, greater<t>>
 
const int N = 1e5 + 5;
const int oo = 1e18;
int dist[N][3],n,m,dep;
vector<pi> adj[N];
 
void dijkstra(){
	for(int i=2;i<=n;i++) 
		for(int j=0;j<2;j++) dist[i][j] = oo;
	heapd(pii) q;
	q.push({0,{1,0}});
 
	while(!q.empty()){
		int u = q.top().se.fi;
		int sl = q.top().se.se;
		int dis = q.top().fi; q.pop(); 
		//cout << 1;
		if(dis != dist[u][sl]) continue;
		
		for(auto x:adj[u]){
			if(dist[x.fi][sl] > dis + x.se){
				dist[x.fi][sl] = dis + x.se;
				q.push({dist[x.fi][sl],{x.fi,sl}});
			}
			if(sl==0 && dist[x.fi][sl+1] > dis+x.se/2){
				dist[x.fi][sl+1] = dis + x.se/2;
				q.push({dist[x.fi][sl+1],{x.fi,sl+1}});
			}
		}
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(false);
 
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u,v,w; cin  >> u >> v >> w;
		adj[u].push_back({v,w});
	}		
	dijkstra();
	cout << dist[n][1];
}   
