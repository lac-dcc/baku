//#define KPR_111
 
 
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin>>n>>m;
 
    vector<vector<pair<int,int>>> adj(n+1);
    vector<long long> dis(n+1,1e18);
 
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
 
    dis[1]=0;
 
	priority_queue<pair<long long,long long>, 
	vector<pair<long long,long long>>, 
	greater<pair<long long,long long>> > pq;
 
 
    pq.push({0,1});
 
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
 
        long long d=it.first;
        long long u=it.second;
 
        if(dis[u] < d) continue;
 
        for(auto nit: adj[u] ){
 
            long long wt=nit.second;
            long long v=nit.first;
 
            if(wt+d>=dis[v])continue;
 
            else{
                dis[v]=wt+d;
                pq.push({dis[v],v});
            }
        }
    }
 
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}
