#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main(){
    int n,m;
    cin >> n >> m;
    
    vector<tuple<int,int,int>> edges;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
 
    vector<int>distance(n+1,1e18);
    vector<int>parent(n+1,-1);
    
    int node = -1;
    for(int i=1;i<=n;i++){
        node = -1;
        for(auto [u,v,w] : edges){
          if(distance[u]+w < distance[v]){
            distance[v] = distance[u]+w;
            parent[v] = u;
            node = v;
          }
        }
    }
    
    if(node == -1){
        cout <<"NO\n";
        return 0;
    }
 
    for(int i=1; i<n; i++){
        node = parent[node];
    }
  
    cout <<"YES\n";
    vector<int> result;
    for(int v = node;; v = parent[v]){
       result.push_back(v);
       if(v == node and result.size() > 1) break;
    }
 
    reverse(result.begin(),result.end());
    for(auto itr : result) { cout << itr <<" "; }
    return 0;
}
