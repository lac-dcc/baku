#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define ii pair<int,int>
 
const int N = 1e5 + 5, M = 3e5 + 50, LOG = 21, mod = 1000000007, INF = 1e8;
priority_queue<pair<ll, int>> pq;
bool vis[N];
vector<pair<int, ll>> adj[N];
ll n, m, ans[N];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    pq.push({0, 1});
    while (pq.size()) {
        auto u = pq.top();
        pq.pop();
        if (vis[u.S]) continue;
        vis[u.S] = true;
        ans[u.S] = -u.F;
        for (auto v : adj[u.S]) {
            pq.push({u.F - v.S, v.F});
        }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
 
    return 0;
}
