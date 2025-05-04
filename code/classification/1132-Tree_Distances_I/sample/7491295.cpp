#include <bits/stdc++.h>
 
using namespace std;
 
#define INF (ll)1e9
#define MX (int)2e5 + 5
#define ll long long int
#define MOD (ll)(1e8)
#define PRIME 13
#define N (int)(2e5+5)
#define M (int)(1e9+7)
 
void dfs(int p,int u,vector<int> adj[],vector<vector<int>> &d){
    int w=p;
    for(auto v:adj[u]) if(v!=p){
        dfs(u,v,adj,d);
        if(d[0][u]<1+d[0][v]){
            d[0][u]=1+d[0][v];
            w=v;
        }
    }
    d[1][u]=w;
    for(auto v:adj[u]) if(v!=p&&v!=w){
        if(d[2][u]<1+d[0][v]){
            d[2][u]=1+d[0][v];
        }
    }
    return;
}
 
void dfs2(int p,int u,vector<int> adj[],vector<vector<int>> &d){
    if(p!=0){
        if(u==d[1][p]){
            d[3][u]=1+max(d[3][p],d[2][p]);
        }else{
            d[3][u]=1+max(d[3][p],d[0][p]);
        }
    }
    for(auto v:adj[u]) if(v!=p) dfs2(u,v,adj,d);
    return;
}
 
void solve();
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}
 
void solve()
{
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=2;i<=n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> d(4,vector<int>(n+1,0));
    dfs(0,1,adj,d);
    dfs2(0,1,adj,d);
    for(int i=1;i<=n;i++) cout<<max(d[0][i],d[3][i])<<" ";
    cout<<"\n";
    return;
}
