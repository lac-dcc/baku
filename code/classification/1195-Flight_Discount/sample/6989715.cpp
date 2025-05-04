#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
 
 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
 
        int n,m;
        cin>>n>>m;
 
        vector<pair<long long,long long>> adj[n+1];
 
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
        }
 
        priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<tuple<long long,int,int>>> pq;
        long long dist[n+1][2];
        bool vis[n+1][2];
 
        for(int i=0;i<2;i++){
            for(int j=0;j<=n;j++){
                // vis[j] = 0;
                dist[j][i] = 1e18;
                vis[j][i] = 0;
            }
        }
 
        dist[1][0] = 0;
        dist[1][1] = 0;
 
       
 
    
 
        pq.push({0,1,0});
        // vis[1][0] = 1;
 
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
 
            long long d, node, flag;
            tie(d,node,flag) = temp;
 
            if(d>dist[n][0] || d>dist[n][1]){
                break;
            }
 
            if(vis[node][flag]){
                continue;
            }
 
            vis[node][flag] = 1;
 
            for(auto it : adj[node]){
                int neigh = it.first;
                int weight = it.second;
 
                if(dist[neigh][1]>dist[node][1]+weight && flag==1 ){
                    dist[neigh][1] = dist[node][1]+weight;
                    pq.push({dist[neigh][1],neigh,1});
                    
                    // vis[neigh][flag] = 1;
                }
 
 
 
                if(dist[neigh][1]>(dist[node][0]+weight/2) && flag==0){
                    dist[neigh][1] = dist[node][0] + weight/2;
                    pq.push({dist[neigh][1],neigh,1});
                    // vis[neigh][flag] = 1;
                    
                }
 
                if(dist[neigh][0]>dist[node][0]+weight && flag==0 ){
                    dist[neigh][0] = dist[node][0] + weight;
                    pq.push({dist[neigh][0],neigh,0});
                    // vis[neigh][flag] = 1;
                }
 
                // vis[neigh] = 1;
 
 
            }
 
        }
 
 
        cout<<dist[n][1]<<endl;
 
 
 
 
        
    
 
    return 0;
}
