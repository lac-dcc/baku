#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define int long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define inf 1e17
 
 
int vis[100005];
int dis1[100005],dis2[100005];
void dij(int s, int dis[], vector<pair<int, int>>adj[]){
    priority_queue<pair<int, int>> q;
    rep(i,100005)dis[i+1]=inf;
    dis[s]=0;
    q.push({0,s});
    memset(vis,0,sizeof vis);
    while(!q.empty()){
        int x = q.top().ss; q.pop();
        if (vis[x])continue;
        vis[x]=1;
        for (auto [y,z]: adj[x]){
            if (dis[x]+z<dis[y]){
                dis[y]=dis[x]+z;
                q.push({-dis[y],y});
            }
        }
    }
}
 
 
 
 
int32_t main(){
    fast
    int t=1;
    // cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
    vector<pair<int, int>>adj1[n+1], adj2[n+1];
    vector<tuple<int,int,int>>e;
    rep(i,m){
        int x, y, z;cin>>x>>y>>z;
        e.pb({x,y,z});
        adj1[x].pb({y,z});
        adj2[y].pb({x,z});
    }
    dij(1,dis1,adj1);
    dij(n,dis2,adj2);
    int ans=inf;
    for(auto [x,y,z]:e){
        ans=min(ans, dis1[x]+ dis2[y]+ z/2);
    }
    cout<<ans<<endl;
    }
    return 0;
}