#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
#define fast_io()                 \
    ios::sync_with_stdio(0);      \
    cin.tie(0)
 
int n, m, q;
vector<vector<pair<int, int>>> graph;
vector<vector<ll>> dist;
 
void solve()
{
    cin>>n>>m>>q;
    graph.resize(n+1); dist.assign(n+1, vector<ll> (n+1, 1e12));
    for(int i = 0; i<m; i++) {
        ll a, b, c;
        cin>>a>>b>>c;
        dist[a][b] = dist[b][a] = min(c, dist[a][b]);
    }
    for(int i = 1; i<=n; i++) dist[i][i] = 0;
    for(int k = 1; k<=n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j<=n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    while(q--) {
        int a, b;
        cin>>a>>b;
        if(dist[a][b] == 1e12) cout<<-1<<endl;
        else cout<<dist[a][b]<<endl;
    }
}
 
int main()
{
    fast_io();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t = 1;
    while(t--)
    {
        //cout<<"Case #"<<(T-t)<<": ";
        solve();
    }
    return 0;
}
