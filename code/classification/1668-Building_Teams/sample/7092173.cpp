#include<bits/stdc++.h>
using namespace std;
 
void dfs( vector<vector<int>>&adj, int u,vector<bool>&vis){
    if(vis[u])return ;
    vis[u]=true;
    for(auto it:adj[u]){
        if(!vis[it]){
           dfs(adj,it,vis);
        }
        
    }
}
int main(){
    int n,m;
    cin>>n>>m;
 
    vector<vector<int>>adj(n+1);
 
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>ans(n+1);
    queue<pair<int,int>>q;
    vector<bool>vis(n+1,false);
    vector<bool>vis1(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vis1[i]){
            q.push({i,1});
            ans[i]=1;
            vis[i]=true;
            dfs(adj,i,vis1);
        }
    }
    q.push({1,1});
    ans[1]=1;
    vis[1]=true;
    bool flag=true;
    while(!q.empty()){
        int u=q.front().first;
        int col=q.front().second;
        q.pop();
 
        for(auto it:adj[u]){
            if(vis[it]){
                if(ans[it]==col){
                    flag=false;
                    break;
                }
            }
            else{
                if(col==2){
                    ans[it]=1;
                    vis[it]=true;
                    q.push({it,1});
                }
                if(col==1){
                    ans[it]=2;
                    vis[it]=true;
                    q.push({it,2});
                }
 
            }
        }
 
 
    }
    if(flag){
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
 
    }
    else{
        cout<<"IMPOSSIBLE";
    }
}
