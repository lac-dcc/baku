#include <bits/stdc++.h>
using namespace std;
#define pb push_back
 
int n,m;
const int N=1e5+5;
vector<bool> vis(N,0);
void dfs(int i,vector<int> adj[]){
    vis[i]=true;
    for(auto pr:adj[i]){
        if(!vis[pr]){
            dfs(pr,adj);
        }
    }
}
 
int main(){
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    int ct=0,fg=0;
    vector<int> ans;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            ct++;
            dfs(i,adj);
            if(fg){
                ans.pb(i);
            }
            else fg=1;
        }
    }
    
    cout<<ct-1<<endl;
    for(auto pr:ans){
        cout<<1<<" "<<pr<<endl;
    }
 
    return 0;
}
