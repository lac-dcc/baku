#include <bits/stdc++.h>
#include <iostream>
#define int long long
using namespace std;
vector<vector<pair<int,int>>> graph;
vector<vector<pair<int,int>>> graphb;
 
vector<bool> vis;
const int INF=1e15;
struct Node{
	int first;
	int second;
	int maxSoFar;
	bool operator<(Node a)const{
		return (((first-maxSoFar)+maxSoFar/2))<=(((a.first-a.maxSoFar)+a.maxSoFar/2));
	}
};
void solve(){
	int n,m;
	cin>>n>>m;
	vector<bool> vis;
	vis.resize(n+1);
	fill(vis.begin(),vis.end(),false);
	graph.resize(n+1);
	graphb.resize(n+1);
	int mm=m;
	vector<pair<int,pair<int,int>>> edges;
	while(mm--){
		int a,b,c;
		cin>>a>>b>>c;
		graph[a].push_back({b,c});
		graphb[b].push_back({a,c});
		edges.push_back({c,{a,b}});
	}
	int dist[n+1];
	int distb[n+1];
	
	multiset<pair<int,int>> set;
	set.insert({0,1});
	while(set.size()>0){
		auto it=*set.begin();
		set.erase(set.begin());
		if(vis[it.second]){
			continue;
		}
		vis[it.second]=true;
		dist[it.second]=it.first;
		for(auto i:graph[it.second]){
			if(!vis[i.first]){
				set.insert({it.first+i.second,i.first});
			}
		}
	}
	fill(vis.begin(),vis.end(),false);
	set.clear();
	set.insert({0,n});
	while(set.size()>0){
		auto it=*set.begin();
		set.erase(set.begin());
		if(vis[it.second]){
			continue;
		}
		vis[it.second]=true;
		distb[it.second]=it.first;
		for(auto i:graphb[it.second]){
			if(!vis[i.first]){
				set.insert({it.first+i.second,i.first});
			}
		}
	}
	int ans=1e15;
	for(auto i:edges){
		ans=min(ans,i.first/2+dist[i.second.first]+distb[i.second.second]);
	}
	cout<<ans<<" ";
}
signed main() {
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
}
