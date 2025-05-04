#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
 
#define int long long int
 
const vector<int> dx = {0, 0, -1, 1};
const vector<int> dy = {1, -1, 0, 0};
 
const int INF = 1e17;
 
int n, m, q;
vector<vector<int>> dist;
 
void floydWarshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
 
void solve() {
    cin >> n >> m >> q;
 
    dist = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
 
    for (int i = 0; i <= n; i++) {
        dist[i][i] = 0;
    }
 
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
 
        dist[u][v] = dist[v][u] = min(dist[u][v], w);
    }
 
    floydWarshall();
 
    while (q--) {
        int u, v;
        cin >> u >> v;
 
        if (dist[u][v] == INF) {
            cout << -1 << "\n";
        } else {
            cout << dist[u][v] << "\n";
        }
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    solve();
 
    return 0;
}
