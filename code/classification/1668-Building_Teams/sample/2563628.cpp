#include<bits/stdc++.h>
using namespace std;
 
#define INF (1LL<<61)
#define pb push_back
#define int long long
int n,m;
 
vector<int> adj[100005];
int vis[100005];
int team[100005];
 
bool dfs(int v) {
    vis[v]=1;
    for(auto u: adj[v]) {
        if(vis[u]!=1) {
            team[u]=team[v]^1;
            if(dfs(u)) return true;
        } else {
            if(team[v]^team[u]!=1) return true;
        }
    }
 
    return false;
}
 
signed main() {
    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
 
    bool flag=true;
    for(int i=0;i<n;i++) {
        if(vis[i]!=1) {
            team[i]=0;
            if(dfs(i)) {
                flag=false;
                break;
            }
        }
    }
 
    if(flag) {
        for(int i=0;i<n;i++) {
            cout<<team[i]+1<<" ";
        }
    } else {
        cout<<"IMPOSSIBLE"<<endl;
    }
 
    return 0;
}
