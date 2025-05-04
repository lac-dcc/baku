#include<bits/stdc++.h>
using namespace std;
 
int n,m;
 
const int maxN=1e5+5;
vector<int> adj[maxN];
vector<bool>visited(maxN,false);
 
void dfs(int src){
    
    visited[src]=true;
    
    for(auto nbr:adj[src]){
        
        if(!visited[nbr]){
            dfs(nbr);
        }
        
    }
    
}
 
int main(){
    
    cin>>n>>m;
    
    int x,y;
    
    for(int i=1;i<=m;i++){
        
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        
    }
    
    vector<int> res;
    
    
    for(int i=1;i<=n;i++){
        
        if(!visited[i]){
            dfs(i);
            res.push_back(i);
        }
        
    }
    
    cout<<size(res)-1<<endl;
    
    for(int i=1;i<res.size();i++){
        cout<<res[0]<<" "<<res[i]<<endl;
    }
    
    
    
    
}
