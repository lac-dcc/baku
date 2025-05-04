#include<bits/stdc++.h>
using namespace std;
// O(nm)
typedef long long ll;
const ll INF = 1e15;
 
// Adjacency matrix
vector<vector<ll>> floyd_warshall(vector<vector<ll>> &adj) {
    int n = adj.size();
    // nodes are numbered 0..n
    vector<vector<ll>> dist(n,vector<ll>(n));
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (u == v) {
                dist[u][v] = 0;
            } else if (adj[u][v] != 0) {
                dist[u][v] = adj[u][v];
            } else {
                dist[u][v] = INF;
            }
        }
    }
 
    for (int k = 0; k < n; k++) { // intermediate node
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                dist[u][v] = min(dist[u][v], dist[u][k]+dist[k][v]);
            }
        }
    }
    return dist;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<vector<ll>> adj(n,vector<ll>(n,0));
    
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (adj[a][b]==0) {
            adj[a][b] = c;
        }
        adj[a][b] = min(adj[a][b],c);
        if (adj[b][a]==0) {
            adj[b][a] = c;
        }
        adj[b][a] = min(adj[b][a],c);
    }
    auto dist = floyd_warshall(adj);
 
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << ((dist[a][b] < INF)? dist[a][b]: -1) << '\n';
    }
    return 0;
}
