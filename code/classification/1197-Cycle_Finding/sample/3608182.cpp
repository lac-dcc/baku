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
 
const int maxn = 2505;
struct edge{
    int u,v,c;
} a[5050];
 
int d[maxn], n, m, neg, trace[maxn], ans[maxn], dem = 0 ;
//
void bellman_ford(int u) {
    for(int i=0; i<n; ++i) {
        d[i] = -100000 * i ;
    }
    for(int i=0; i<n; ++i) {
        neg = -1 ;
        for(int j=0; j<m; ++j) {
            auto &[u,v,c] = a[j];
            if (d[v] > d[u] + c) {
                d[v] = d[u] + c;
                trace[v] = u ;
                neg = v ;
            }
        }
    }
}
//
void solve() {
    cin >> n>> m;
    for(int i=0; i<m; ++i) {
        auto &[u,v,c] = a[i];
        cin >> u>> v>> c;
    }
 
    bellman_ford(1) ;
    if ( neg == -1) {
        cout << "NO" ;
        return;
    }
    cout << "YES"<< ed ;
    for(int i=0; i<n; ++i) neg = trace[neg];
    for(int x =neg; ; x = trace[x]) {
        ans[dem++]= x ;
        if (x==neg && dem > 1) break;
    }
    for(int i=dem-1; i>=0; --i) cout << ans[i] << ' '  ;
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
