#include "bits/stdc++.h"
 
using namespace std;
 
using ld = long double;
using ll = long long;
using ull = unsigned long long;
 
#if defined(ONPC)
#include "bits/debug.h"
#endif
 
using T = array<ll, 2>;
const ll INF = 1e17;
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<vector<T>> adj(n);
    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({c, b});
    }
    priority_queue<T, vector<T>, greater<T>>  pq;
 
    vector<ll> dist(n, INF);
    dist[0] = 0;
    pq.push({0, 0});
 
    while (!pq.empty()) {
        T u = pq.top();
        pq.pop();
        if (u[0] > dist[u[1]]) continue;
        for (T v : adj[u[1]]) {
            if (u[0] + v[0] < dist[v[1]]) {
                dist[v[1]] = u[0] + v[0];
                pq.push({dist[v[1]], v[1]});
            }
        }
    }
 
    for (ll &x : dist) {
        cout << x << ' ';
    }
    cout << "\n";
}
