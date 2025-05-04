#include<bits/stdc++.h>
using namespace std;
 
#define maxn 100005
vector<int> adj[maxn];
int par[maxn];
int vis[maxn]={};
int st=-1,en=-1;
 
int dfs(int u,int p){
    vis[u] = 1;
    par[u] = p;
    for(int v:adj[u]){
        if(v==p) continue;
        if(vis[v]){
            en = u;
            st = v;
            return 1;
        }
        if(!vis[v]){
            if(dfs(v,u)) return 1;
        }
    }
    return 0;
}
 
int check(int n){
    for(int i=0;i<n;i++){
        if(!vis[i])
            if(dfs(i,-1)) return 1;
    }
    return 0;
}
 
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans;
    if(check(n)){
        int tmp = en;
        ans.push_back(en);
        while(tmp!=st){
            ans.push_back(par[tmp]);
            tmp = par[tmp];
        }
        ans.push_back(en);
        cout<<ans.size()<<'\n';
        for(int c:ans){
            cout<<c<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
