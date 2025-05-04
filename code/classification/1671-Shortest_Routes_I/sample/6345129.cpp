#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
int n,m;
vector<vector<pair<int,int>>>g;
vector<int>dist;
 
signed main(){
	cin>>n>>m;
	
	g.resize(n+1);
	dist.resize(n+1);
	
	for(int i = 1; i <= n ; i++){
		dist[i] = 1e18;
	}
	
	for(int i = 0 ; i < m ; i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		g[u].push_back({v,wt});
	}
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	dist[1] = 0;
	pq.push({dist[1],1});
	
	while(!pq.empty()){
		auto node = pq.top();
		pq.pop();
		
		if(dist[node.second] < node.first)continue;
		
		for(auto it : g[node.second]){
			if(dist[it.first] > dist[node.second]+it.second){
				dist[it.first] = dist[node.second]+it.second;
				pq.push({dist[it.first],it.first});
			}
		}
	}
	
	for(int i = 1 ; i <= n ; i++){
		cout << dist[i] << " ";
	}
	return 0;
}
