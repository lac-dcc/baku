#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1000000007;
const double PI = 3.14159265358979323846;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fo(i ,n) for(ll i = 0 ; i < n ; i++)
#define mp make_pair
#define all(x) x.begin() , x.end()
#define ff first
#define ss second
#define pb push_back
#define vi vector<ll>
#ifndef ONLINE_JUDGE
  #include "debug.h"
#else
#define deb(...)
#endif
 
 
 
 
const int maxn = 200005;
ll n;
vector<ll>adj[maxn];
bool vis[maxn];
vector<int>dist;
 
 
void dfs(int node,int length){
    vis[node]=1;
    dist[node]=length;
    for(auto j:adj[node]){
        if(!vis[j]){
            dfs(j,length+1);
        }
    }
}
ll dp[maxn][3];
// dp[i][1] = Distance of Node i from node 1 (the one that we found)
// dp[i][2] = Distance of Node i from node 2
 
void dfs2(int node,int type,int leng){
    vis[node]=1;
    dp[node][type]=leng;
    for(auto j:adj[node]){
        if(!vis[j]){
            dfs2(j,type,leng+1);
        }
    }
}
 
void solve() {
    dist.resize(maxn);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    if(n==1){
        cout << 0 << endl;
        return;
    }
    dfs(1,0);
    ll leng = -1;
    ll node;
    for(int i=1;i<=n;i++){
        if(dist[i] > leng){
            leng = dist[i];
            node=i;
        }
    }
    memset(vis,false,sizeof(vis));
    dist.clear();
    dfs(node,0);
    ll ans=0;
    ll node2;
    for(int i=1;i<=n;i++){
        if(dist[i] > ans){
            node2 = i;
            ans = dist[i];
        }
    }
    //cout << node << ' ' << node2 << endl;
    memset(vis,false,sizeof(vis));
    dfs2(node,1,0);
    memset(vis,false,sizeof(vis));
    dfs2(node2,2,0);
 
 
    for(int i=1;i<=n;i++){
        cout << max(dp[i][1],dp[i][2]) << ' ';
    }
    cout << endl;
 
}
 
 
int32_t main(){
    FAST;
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
