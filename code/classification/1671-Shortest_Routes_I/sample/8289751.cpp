/* by hungwbuif */
 
#include <bits/stdc++.h>
 
#define int long long
#define ii pair<int, int>
 
#define fi first
#define se second
using namespace std;
 
const int MAXN = 1001; 
const int N = 1e5 + 5;
const int MN = 1e6 + 5;
const int MOD = 1e9 + 7;
const int MAX_N = 1005;
 
int dis[N];
bool vis[N];
vector<ii> adj[N];
int n, m;
 
void solve() {
    for (int i = 2; i <= n; i++) dis[i] = LLONG_MAX;;
    
    dis[1] = 0;
    
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, 1});
    
    while (!q.empty()) {
        int v = q.top().se;
        q.pop();
        
        if (vis[v]) continue;
        
        vis[v] = true;
        
        for (auto u : adj[v]) {
            int x = u.fi;
            int y = u.se;
            
            if (dis[v] + y < dis[x]) {
                dis[x] = dis[v] + y;
                q.push({dis[x], x});
            }
        }
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    t = 1;
    
    while (t--) {
        cin >> n >> m;
        
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            
            adj[a].push_back({b, c});
        }
        
        solve();
        
        for (int i = 1; i <= n; i++) cout << dis[i] << " ";
    }
}
