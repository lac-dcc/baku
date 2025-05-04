#include <bits/stdc++.h>
 
using namespace std;
 
#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define REP1(i, n)  for (int i = 1; (i) <= (n); (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)
 
using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    REP(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    auto far = [&](int s) {
        int t = s;
        vector<int> dist(n, -1);
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
 
            if (dist[u] > dist[t]) t = u;
 
            for (int v : adj[u]) if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        return pii{t, dist[t]};
    };
 
    cout << far(far(0).first).second << '\n';
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
}
