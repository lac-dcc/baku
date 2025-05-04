#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
 
vector<vector<int>> adj;
vector<int> visited;
vector<int> path;
 
vector<int> DFS(int node, int parent) {
    path.push_back(node);
    if (visited[node]) {
        auto it = find(path.begin(), path.end(), node);
        vector<int> cycle(it, path.end());
        return cycle;
    }
    visited[node] = 1;
 
    for (int child : adj[node]) {
        if (child == parent || child == node) continue;
        vector<int> e = DFS(child, node);
        if (!e.empty()) return e;
    }
    path.pop_back();
    return vector<int>();
}
 
int main() {
    int n, x;
    cin >> n >> x;
 
    adj.resize(n + 1);
    visited.assign(n + 1, 0);
 
    for (int i = 0; i < x; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            vector<int> t = DFS(i, 0);
            if (!t.empty()) {
                cout << t.size() << endl;
                for (int node : t) {
                    cout << node << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
