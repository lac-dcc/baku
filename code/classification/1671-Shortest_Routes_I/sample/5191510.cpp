#include <bits/stdc++.h>
#define int long long
#define sd second
#define ft first
 
using namespace std;
const int N = 100005;
int n, m, d[N];
vector<pair<int, int>> adj[N];
 
void dij() {
    for(int i = 2; i <= n; ++i)
        d[i] = 1e15;
    priority_queue<pair<int, int>> pq;
    d[1] = 0;
    pq.push({0, 1});
    while(pq.size()) {
        int u = pq.top().sd;
        int du = -pq.top().ft;
        pq.pop();
        if(du != d[u])
            continue;
        for(auto v : adj[u])
            if(d[v.ft] > du + v.sd) {
                d[v.ft] = du + v.sd;
                pq.push({-d[v.ft], v.ft});
            }
    }
    for(int i = 1; i <= n; ++i)
        cout << d[i] << " ";
}
 
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
    dij();
}
 
#undef int
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
 
    int tc = 1;
    // cin >> tc;
    while(tc--)
        solve();
 
    return 0;
}
