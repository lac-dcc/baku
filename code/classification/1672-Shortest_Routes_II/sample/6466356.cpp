#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const long long maxn = 505, INF = 1e17+9;
vector<pair<long long, long long>> adj[maxn];
bool visited[maxn];
int n, m, q;
void clear_visited(){
    for(int i = 0; i <= n; i++){
        visited[i] = false;
    }
}
long long dist[maxn][maxn];
void inp(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++){
        adj[i].clear();
    }
    for(int i = 1; i <= m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
}
void solve(){
 
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int a, b;
    for(int i = 1; i <= q; i++){
        cin >> a >> b;
        if(dist[a][b] == INF){
            cout << -1 << "\n";
            continue;
        }
        cout << dist[a][b] << "\n";
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	solve();
}
