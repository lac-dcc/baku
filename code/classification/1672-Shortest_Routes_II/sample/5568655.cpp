#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
#define ln '\n'
 
const ll INF = 1e18;
 
 
void solve(){
    int n, m, q; cin >> n >> m >> q;
    ll dist[n+1][n+1];
    ll u, v, w;
 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dist[i][j] = INF;
        }
    }
 
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
 
    for (int i = 0; i < m; i++){
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
 
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
 
    while (q--){
        cin >> u >> v;
        cout << ((dist[u][v] >= INF && dist[v][u] >= INF) ? -1
                : min(dist[u][v], dist[v][u])) << ln;
    }
}
 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
    // int T; cin >> T;
    // while (T--){
    //     solve();
    // }
 
    solve();
 
 
 
 
    return 0;
}
 
 
 
 
 
 
 
 
