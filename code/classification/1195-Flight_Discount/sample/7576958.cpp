#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <numeric>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <climits>
 
using namespace std;
 
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
 
typedef long long ll;
typedef pair<int, ll> pii;
 
int const N = 1e5 + 7;
int const M = 2e5 + 7;
 
int n, m;
 
vector<ll> dijkstra(int start, vector<pii> g[]) {
    vector<ll> d(n + 1, 1e18);
    d[start] = 0;
 
    set<pair<ll, int>> st;
    st.insert({0, start});
 
    while (st.size()) {
        int v = st.begin()->second;
        st.erase(st.begin());
        for (auto elem: g[v]) {
            int to = elem.first;
            ll w = elem.second;
            
            if (d[to] > w + d[v]) {
                st.erase({d[to], to});
                d[to] = w + d[v];
                st.insert({d[to], to});
            }
        }
    }
    return d;
}
 
void solve() {
    vector<pii> g1[N];
    vector<pii> gn[N];
    
    cin >> n >> m;
 
    map<pii, int> mp;
 
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
 
        g1[a].pb({b, c});
        gn[b].pb({a, c});
 
        mp[{a, b}] = c;
        // mp[{b, a}] = c;
    }
 
 
    vector<ll> d1 = dijkstra(1, g1);
    vector<ll> dn = dijkstra(n, gn);
 
    ll res = 1e18;
 
    for (auto it: mp) {
        int from = it.first.first;
        int to = it.first.second;
        ll w = it.second;
 
        res = min(res, d1[from] + w / 2 + dn[to]);
    }
    cout << res << "\n";
}
 
int main() { 
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
 
