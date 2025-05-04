#include<bits/stdc++.h>
using namespace std;
 
int loop=INT_MIN;
 
bool dfs(unordered_map<int,vector<int>> &adj,vector<int> &parent,vector<bool> &visited,int u,int par){
    // cout<<u<<" "<<par<<endl;
    visited[u]=true;
    parent[u]=par;
    for(int &v : adj[u]){
        if(!visited[v]){
            if(dfs(adj,parent,visited,v,u))
            return true;
        }
        else if(v!=par){
            loop=v;
            parent[loop]=u;
            return true;
        }
    }
    return false;
}
 
int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int>> adj;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    vector<int> parent(n+1,-1);
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(parent[i]==-1){
            if(dfs(adj, parent,visited,i,-1)){
               break;
            }
        }
    }
 
    if(loop==INT_MIN){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
 
    int i=loop;
    vector<int> ans;
    ans.push_back(i);
    while(parent[loop]!=i){
        ans.push_back(parent[loop]);
        loop=parent[loop];
    }
    ans.push_back(i);
    cout<<ans.size()<<endl;
    for(int &i : ans){
        cout<<i<<" ";
    }
}
