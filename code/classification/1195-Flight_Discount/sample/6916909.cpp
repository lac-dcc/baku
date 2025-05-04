#include "bits/stdc++.h"
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
template <typename T> istream& operator >> (istream& in, vector<T>& v) { for (auto &it:v) in >> it; return in; }
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (auto &it:v) os << it << " "; return os; }
template <typename T1, typename T2> istream& operator >> (istream& in, pair<T1,T2>& p) { cin >> p.first >> p.second; return in; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p) { cout << p.first << " " << p.second; return os; }
template <typename T1, typename T2> void maxn(T1& a, T2 b) { a = max(a,b); }
template <typename T1, typename T2> void maxx(T1& a, T2 b) { a = max(a,b); }
 
#define int long long int
#define ll int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define sz(v) (int)v.size()
#define deb(x) cout<<#x<<"="<<x<<"\n";
#define pii pair<int,int> 
 
const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
int n,m;
vector<vector<pii>> graph;
vector<vector<pii>> graph2;
vector<int> vis;
 
void dijkstra(int src,vector<int> &dist)
{
    dist[src]=0;
    set<pii> st;
    st.insert({0,src});
    while(!st.empty())
    {
        int node=(*st.begin()).ss;
        st.erase(st.begin());
        if(vis[node]) continue;
        vis[node]=1;
        for(auto it:graph[node])
        {
            if(vis[it.ff]) continue;
            if(it.ss+dist[node]<dist[it.ff])
            {
                dist[it.ff]=it.ss+dist[node];
                st.insert({dist[it.ff],it.ff});
            }
        }
    }
}
 
void dijkstra2(int src,vector<int> &dist)
{
    dist[src]=0;
    set<pii> st;
    st.insert({0,src});
    while(!st.empty())
    {
        int node=(*st.begin()).ss;
        st.erase(st.begin());
        if(vis[node]) continue;
        vis[node]=1;
        for(auto it:graph2[node])
        {
            if(vis[it.ff]) continue;
            if(it.ss+dist[node]<dist[it.ff])
            {
                dist[it.ff]=it.ss+dist[node];
                st.insert({dist[it.ff],it.ff});
            }
        }
    }
}
 
void solve()
{
    cin>>n>>m;
    graph.resize(n+1); graph2.resize(n+1); vis.resize(n+1);
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w; cin>>u>>v>>w;
        graph[u].pb({v,w});
        graph2[v].pb({u,w});
        edges.pb({u,v,w});
    }
    vector<int> distfromsrc(n+1,1e16),distfrmtar(n+1,1e16);
    dijkstra(1,distfromsrc);
    vis.clear(); vis.resize(n+1);
    dijkstra2(n,distfrmtar);
    int ans=min(distfromsrc[n],distfrmtar[0]);
    // for(int i=1;i<=n;i++)
    // {
    //     // deb(i);
    //     for(auto it:graph[i])
    //     {
    //         int val1=distfromsrc[i]+distfrmtar[it.ff]+it.ss/2;
    //         ans=min({ans,val1});
    //     }
    // }
    for(int i=0;i<sz(edges);i++)
    {
        int val=distfromsrc[edges[i][0]]+distfrmtar[edges[i][1]]+edges[i][2]/2;
        ans=min(ans,val);
    }
    cout<<ans<<endl;
}
 
int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    int tc=1;
    // cin>>tc;
    while(tc--) solve();
    return 0;
}
