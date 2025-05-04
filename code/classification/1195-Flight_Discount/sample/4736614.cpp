#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp>     //required
//#include <ranges>
 
 
using namespace std;
using namespace __gnu_pbds;              // required
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
#ifdef LOCAL
#include "debug.hpp"
#define _print(x) __print(x); printf("\n");
#endif
#ifndef LOCAL
#define debug(...) 1
#define debug_itr(start, end) 1
#define __print(...) 1
#define _print(...) 1
#endif
using inti = int;
#define int long long
#define ll int
#define rep(i, l, r) for(int (i) = l ; (i) < (r) ; ++(i))
#define repi(i, r, l) for(int (i) = r ; (i) >= (l) ; --(i))
#define lp(i, n) rep(i,0,n)
#define lpi(i, n) repi(i, (n) - 1 , 0)
#define IOS                           \
                ios_base::sync_with_stdio(false); \
                cin.tie(0);                       \
                cout.tie(0);
#define vr vector
#define pii pair<int,int>
#define F first
#define S second
#define vi vr<int>
#define vvi vr<vi>
#define vii vr<pii>
#define all(v) (v).begin(),(v).end()
#define ld long double
#define ppi = pair<pii, pii>
int const MOD = 998244353;
int const MAX_N = 1e5;
int const INF = 1e18;
int tmp, tmp1, tmp2;
#define endl "\n"
int cse;
const double E = 9e-7;
 
void init() {
//    memset(dp, -1, sizeof dp);
}
 
 
void dij(int n, vr<ll> &dis, vr<pair<ll, ll>> adj[], int s) {
    priority_queue<pair<ll, ll>> q;
    vr<bool> vis(n + 1, false);
    rep(i, 0, n + 1) dis[i] = INF;
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (vis[a])
            continue;
        vis[a] = true;
        for (auto [b, w]: adj[a]) {
            if (dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
                q.push({-dis[b], b});
            }
        }
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vr<pii > adj1[n + 5];
    vr<pii > adj2[n + 5];
    vr<pair<pii, int> > roads(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> tmp >> tmp1 >> tmp2;
        roads[i] = {{tmp, tmp1}, tmp2};
        adj1[tmp].emplace_back(tmp1, tmp2);
        adj2[tmp1].emplace_back(tmp, tmp2);
    }
    vr<ll> dis1(n + 1);
    vr<int> dis2(n + 1);
    dij(n, dis1, adj1, 1);
    dij(n, dis2, adj2, n);
    int ans = INF;
    for (int i = 1; i <= m; i++) {
        auto [f, c] = roads[i];
        auto [a, b] = f;
        ans = min({ans, dis1[a] + c / 2 + dis2[b]});
    }
    cout << ans << endl;
}
 
inti main() {
//    IOS;
    int cntT = 1;
//    cin >> cntT;
//    heavyTest();
    init();
    for (cse = 1; cse <= cntT; cse++) {
        solve();
    }
}
