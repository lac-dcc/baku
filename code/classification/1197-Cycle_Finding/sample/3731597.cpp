#include <bits/stdc++.h>
using namespace std;
#define lli long long int
 
struct Edge {
    int from, to, cost;
};
 
const int MAX_SIZE = 2501;
int n, m, a, b, c;
vector<Edge> edges;
lli distances[MAX_SIZE];
map<int, int> prevs;
bool hasNegativeCycle = false;
int cycleStart = -1;
 
void bellmanFord() {
    memset(distances, 0, n + 1);
    for (int i = 0; i < n; ++i) {
        bool updated = false;
        for (auto e : edges) {
            if (distances[e.from] + e.cost < distances[e.to]) {
                distances[e.to] = distances[e.from] + e.cost;
                prevs[e.to] = e.from;
                updated = true;
                if (i == n - 1) {
                    // has negative cycle
                    hasNegativeCycle = true;
                    cycleStart = e.to;
                }
            }
        }
        if (!updated) break;
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        Edge e;
        e.from = a;
        e.to = b;
        e.cost = c;
        edges.push_back(e);
    }
    bellmanFord();
    if (hasNegativeCycle) {
        cout << "YES" << endl;
        vector<int> path;
        for (int i = 1; i <= n; ++i) {
            cycleStart = prevs[cycleStart];
        }
        int cur = cycleStart;
        while (true) {
            path.push_back(cur);
            if (cur == cycleStart && path.size() > 1) break;
            cur = prevs[cur];
        }
        reverse(path.begin(), path.end());
        for (auto i : path) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
 
int main() {
    cin.tie(0);
    solve();
}
