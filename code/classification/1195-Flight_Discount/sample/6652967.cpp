#include<bits/stdc++.h>
using namespace std;
 
typedef pair<long long,int> pii;
void solve(){
    int n,m; cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<int>vis(n+1);
    vector<long long>dist1(n+1,1e18);
    dist1[1]=0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,1});
    while (!pq.empty())
    {
        long long wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
 
        if(vis[node]==1){
            continue;
        }
        vis[node]=1;
 
        for(auto it:adj[node]){
            int v =it.first;
            int w = it.second;
            if(vis[v]==0){
                if(dist1[node]!=1e18 && dist1[node]+w<dist1[v]){
                    dist1[v]=dist1[node]+w;
                }
                pq.push({wt+w,v});
            }
        }
 
    }
    
    vector<pair<int,int>>adj2[n+1];
    for (int i = 1; i <= n; i++)
    {
        for(auto it:adj[i]){
            int u = it.first;
            int v =i;
            int w = it.second;
            adj2[u].push_back({v,w});
        }
    }
    vector<long long>dist2(n+1,1e18);
    vector<int>vis2(n+1,0);
    dist2[n]=0;
    pq.push({0,n});
    while (!pq.empty())
    {
        long long wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
 
        if(vis2[node]==1){
            continue;
        }
        vis2[node]=1;
 
        for(auto it:adj2[node]){
            int v =it.first;
            int w = it.second;
            if(vis2[v]==0){
                if(dist2[node]!=1e18 && dist2[node]+w<dist2[v]){
                    dist2[v]=dist2[node]+w;
                }
                pq.push({wt+w,v});
            }
        }
 
    }
 
    //we got dist1 and dist2;
 
    long long ans = 1e18;
    for(int i = 1;i<=n;i++){
        long long d = dist1[i];
        if(d!=1e18){
            for(auto it:adj[i]){
                int a = it.first;
                int w = it.second;
                if(dist2[a]!=1e18){
                    ans= min(ans,dist1[i]+w/2+dist2[a]);
                }
            }
        }
    }   
 
    cout<<ans<<endl;
 
 
    
 
    
    
}
 
 
int main() 
{
 solve();
}
