//BFS-Breadth First Search
 
#include <bits/stdc++.h>
using namespace std;
    const int mxN=3e5 + 20;
    vector<int>adj[mxN];
    bool vis[mxN];
    
    void dfs(int s){
        vis[s]=1;
        for(auto i:adj[s]){
            if(vis[i]) continue;
            
            vis[i]=1;
            dfs(i);
        }
    }
    
 
int main()
{
    long long int n,m,u,v,c=0;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> vec;
    
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        
        dfs(i);
        vec.push_back(i);
        c++;
    }
 
    cout<<c-1<<"\n";
    for(int i=0;i<vec.size()-1;i++){
        cout<<vec[i]<<" "<<vec[i+1]<<"\n";
    }
    
 
    return 0;
}
 
