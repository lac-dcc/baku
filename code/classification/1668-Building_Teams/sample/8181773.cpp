//......
 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ra(a) a.begin(),a.end()
#define endl "\n"
#define pb push_back
#define no cout<<"No"<<endl
#define No cout<<"NO"<<endl
#define yes cout<<"Yes"<<endl
#define Yes cout<<"YES"<<endl
#define mod 1000000007
#define inf LLONG_MAX
#define what_is(x) cout<<#x<<": "<<x<<endl;
 
const int N = 1e5+3;
bool color[N];
bool visited[N];
 
void dfs(vector<int>G[], int v, bool col)
{
    visited[v] = true;
    color[v] = col;
    for(int c:G[v]){
        if(visited[c]) continue;
        dfs(G, c, !col);
    }
}
 
void solve()
{
    int n,m; cin>>n>>m;
    vector<int>G[n];
    vector<pair<int,int>>edge;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        x--; y--;
        G[x].pb(y);
        G[y].pb(x);
        edge.pb({x,y});
    }
    memset(color, 0, sizeof(color));
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        dfs(G, i, 0);
    }
    for(auto pr:edge){
        if(color[pr.first]==color[pr.second]){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    for(int i=0;i<n;i++) cout<<color[i]+1<<" "; cout<<endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        // cout<<"Case #"<<i+1<<": \n";
        solve();
    }
}
/*
 
*/
