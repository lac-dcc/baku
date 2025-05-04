#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll long long
#define ull unsigned long long
#define ed '\n'
#define pb push_back
#define ii pair<ll,ll>
#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define rep(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
 
using namespace __gnu_pbds;
using namespace std;
 
const int maxn = 1e5, inf = 1e18;
int n, m;
vector<ii> g1[maxn + 10], g2[maxn+10] ;
 
void dijkstra(int u, vector<int> &d, vector<ii> g[]) {
    d[u] = 0  ;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0,u}) ;
 
    while(q.size()) {
        int u = q.top().second;
        int dis = q.top().first;
        q.pop() ;
 
        if (dis != d[u]) continue;
 
        for(ii &v: g[u]) {
            int to = v.first;
            int len = v.second ;
 
            if (d[to] > dis + len) {
                d[to] = dis + len;
                q.push({d[to], to}) ;
            }
        }
    }
}
//
void solve() {
    cin >> n >> m;
    while(m--) {
        int u,v,c;
        cin >> u>> v>> c;
        g1[u].pb({v,c}) ;
        g2[v].pb({u,c}) ;
    }
 
    vector<int> d1(n+1, inf), d2(n+1, inf)  ;
    dijkstra(1, d1, g1) ;
    dijkstra(n, d2, g2) ;
 
    int ans = LLONG_MAX ;
    for(int i=1; i<n; ++i) {
        for(ii &x : g1[i]) {
            ans = min(ans, d1[i] + d2[x.first] + x.second/2) ;
        }
    }
    cout << ans ;
}
//
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("cf.inp", "r")) {
        freopen("cf.inp", "r", stdin);
        //freopen("cf.inp", "w", stdout);
    }
    //return 0 ;
    solve() ;
    return 0;
}
