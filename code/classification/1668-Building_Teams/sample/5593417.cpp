#include<bits/stdc++.h>
 
using namespace std;
 
const int mxN = 1e5 + 1;
 
vector<int> g[mxN];
int vis[mxN] , team[mxN];
 
void dfs(int u,int t){
    for(auto v: g[u]){
        if(team[v] && vis[v] && t==team[v]){
            cout<< "IMPOSSIBLE";
            exit(0);
        }
 
        if(vis[v] || team[v]) continue;
 
        vis[v] = 1;
        team[v] = t%2 + 1;
        dfs(v,team[v]);
 
    }
}
 
int main(){
    int n,m;
 
    cin>> n >> m;
 
    for(int i=0;i<m;i++){
        int u,v;
        cin>> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    for(int i=1;i<=n;i++){
        if(!vis[i]){        //vis[i] = 0
            team[i] = 1;
            vis[i] = 1;
            dfs(i,1);
        }
    }
 
    for(int i=1;i<=n;i++){
        cout<< team[i] << " ";
    }
 
    return 0;
}
 
/*
5 5
1 2
1 5
2 3
3 4
4 2
*/