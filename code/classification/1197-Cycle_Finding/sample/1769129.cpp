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
 
int n, m;
vector<int> dist;
vector<int> relaxant;
vector<vector<int>> graph;
 
void bellmanFordNegativeCycle() {
    int x = -1;
 
    for (int i = 1; i <= n; i++) {
        x = -1;
        for (auto edge : graph) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
 
            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                relaxant[v] = u;
                x = v;
            }
        }
    }
 
    if (x == -1) {
        cout << "NO\n";
    } else {
        for (int i = 1; i <= n; i++) {
            x = relaxant[x];
        }
 
        vector<int> path;
        int v = x;
 
        do {
            path.push_back(x);
            x = relaxant[x];
        } while (x != v);
 
        path.push_back(x);
 
        reverse(path.begin(), path.end());
 
        cout << "YES\n";
        for (auto p : path) {
            cout << p << " ";
        }
        cout << "\n";
    }
}
 
void solve() {
    cin >> n >> m;
 
    dist = vector<int>(n + 1, 0);
    relaxant = vector<int>(n + 1, -1);
    graph = vector<vector<int>>(m);
 
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
 
        graph[i] = {u, v, w};
    }
 
    bellmanFordNegativeCycle();
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    solve();
 
    return 0;
}
