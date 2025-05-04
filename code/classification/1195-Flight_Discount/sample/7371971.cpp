#include <bits/stdc++.h>
// #define endl "\n"
using namespace std;
#define int long long
 
const int INF = 1e17;
const int NINF = INF*(-1);
vector<int> dj(int i,int n,vector<pair<int,int>> adj[]){
    vector<int> dist(n+1,INF);
    dist[i]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,i});
    while(pq.size()){
        auto x = pq.top();
        int node = x.second;
        int cost = x.first;
        pq.pop();
        if(dist[node] < cost) continue;
        for(auto it:adj[node]){
            int to = it.first;
            int wt = it.second;
            if(dist[node] + wt < dist[to]){
                dist[to] = dist[node] + wt;
                pq.push({dist[to],to});
            }
        }
    }
    return dist;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n+1];
	vector<pair<int,int>> rev_adj[n+1];
	for(int i=0;i<m;i++){
	    int u,v,wt;
	    cin>>u>>v>>wt;
	    adj[u].push_back({v,wt});
	    rev_adj[v].push_back({u,wt});
	}
	vector<int> mincost = dj(1,n,adj);
	vector<int> mincost_rev = dj(n,n,rev_adj);
	int ans = INF;
	for(int i=1;i<=n;i++){
	    for(auto it:adj[i]){
	        int to = i;
	        int from = it.first;
	        int c = it.second;
	        if(mincost[to] == INF || mincost_rev[from] == INF) continue;
	        
	        ans = min(ans,mincost[to] + c/2 + mincost_rev[from]);
	    }
	}
	cout<<(ans == INF ? -1 : ans)<<endl;
}
 
 
 
