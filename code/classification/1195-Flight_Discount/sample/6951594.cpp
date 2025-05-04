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
 
 
 
 
 
 
 
 
 
 
 
// #include<bits/stdc++.h>
// using namespace std;
 
 
// typedef long long ll;
// ll INF = 1e17;
 
 
// int vis[100005];
 
 
// void Dijk(int s, vector<ll> &dist, vector<vector<pair<int,int>>> &g){
//     priority_queue<int, vector<int>, greater<int>> pq;
//     pq.push(s);
//     dist[s] = 0;
 
//     memset(vis, 0, sizeof(vis));
 
//     while (!pq.empty())
//     {
//         int u = pq.top(); pq.pop();
 
//         if(vis[u]){continue;}
//         vis[u] = 1;
 
//         for(auto [v,wt]: g[u]){
//             if(dist[u] != INF && dist[u]+wt < dist[v]){
//                 dist[v] = dist[u]+wt;
//                 pq.push(v);
//             }
//         }
//     }
    
// }
 
 
 
 
 
 
// void func(){
//     int n,m;
//     cin>>n>>m;
 
//     vector < vector < pair<int, int> > > g1(n+1);
//     vector < vector < pair<int, int> > > g2(n+1);
//     vector<vector<int>> edges;
 
//     for (int i = 0; i < m; i++)
//     {
//         int a, b, w;
//         cin>>a>>b>>w;
 
//         g1[a].push_back({b,w});
//         g2[b].push_back({a,w});
//         edges.push_back({a,b,w});
//     }
 
//     vector<ll> d1(n+1, INF), d2(n+1, INF);
 
//     Dijk(1, d1, g1);
//     Dijk(n, d2, g2);
 
    
//     ll ans = INF;
//     for(auto vec: edges){
//         int u = vec[0], v = vec[1], wt = vec[2];
 
//         ans = min(ans, d1[u]+d2[v]+wt/2);
//     }
 
//     cout<<ans;
 
    
  
 
// }
 
 
 
 
// int main(){
//     func();    
// }
