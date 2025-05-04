#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
 
 
void dijkstra(int src, vector<vector<pair<int, ll>>> &adj, vector<ll> &dis){
    
    // initialization O(V)
    for(int i = 0; i<dis.size(); i++){
        dis[i] = 1e15;
    }
    dis[src] = 0;
 
 
    // make heap O(V)
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push(make_pair(0,src));
    
    while(!pq.empty()){
 
        int u = pq.top().second; 
        ll du = pq.top().first;
        pq.pop();
 
        if(du > dis[u]) continue; // already visited;
 
        // relax
        for(int i = 0; i<adj[u].size(); i++){
            int v = adj[u][i].first;
            ll w = adj[u][i].second;
 
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push(make_pair(dis[v],v));
            }
        }
    }
}
 
 
int main()
{
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int n, m, u, v;
    ll weight;
    cin >> n >> m;
    
    vector<vector<pair<int, ll>>> adj(n+1), adj2(n+1);
    vector<ll> dis(n+1), dis2(n+1);
    vector<pair<ll, pair<int,int>>> edges;
    
 
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> weight;
        edges.push_back(make_pair(weight, make_pair(u,v)));
        adj[u].push_back(make_pair(v,weight));
        adj2[v].push_back(make_pair(u,weight));
    }
 
    dijkstra(1,adj,dis);
    dijkstra(n,adj2,dis2);
 
    ll cost = 1e15;
    for(int i = 0; i<edges.size(); i++){
        u = edges[i].second.first;
        v = edges[i].second.second;
        weight = edges[i].first;
        cost = min(cost, dis[u] + weight/2 + dis2[v]);
    }
    cout<<cost<<endl;
 
 
    
 
    
 
    
    
    
    return 0;
}
