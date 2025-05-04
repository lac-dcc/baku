#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void dfs(int i, vector<vector<int>> &adj,vector<bool> &vis,int n){
    for(auto adjacentNode : adj[i]){
        if(!vis[adjacentNode]){
            vis[adjacentNode] = true;
            dfs(adjacentNode,adj,vis,n);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n,m;
cin>>n>>m;
vector<vector<int>> adj(n+1);
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> component;
    vector<bool> vis(n+1,false);
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            vis[i] =true;
            component.push_back(i);
            dfs(i,adj,vis,n);
        }
    }
    if(component.size() == 1){
        cout<<"0\n";
    }
    else{
        if(m == 1){
        cout<<component.size()-1<<"\n";
        
        }
        else {
            cout<<component.size()-1<<"\n";
        }
        for(int i = 0;i<component.size()-1;i++){
            cout<<component[i]<<" "<<component[i+1]<<"\n";
        }
        
    }
 
return 0;
}
