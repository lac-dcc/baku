#include <bits/stdc++.h>
#include <vector>
 
using namespace std;
 
vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent;
int cycleStart, cycleEnd;
 
bool dfs(int node, int par) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            parent[neighbor] = node;
            if (dfs(neighbor, node))
                return true;
        } else if (neighbor != par) {
            cycleStart = neighbor;
            cycleEnd = node;
            return true;
        }
    }
    return false;
}
 
void findCycle(int n) {
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);
    cycleStart = -1;
 
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && dfs(i, -1))
            break;
    }
 
    if (cycleStart == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycleStart);
        for (int v = cycleEnd; v != cycleStart; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycleStart);
 
     //   cout << "Cycle found: ";
     cout<<cycle.size()<<"\n";
        reverse(cycle.begin(),cycle.end());
     
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    }
}
 
int main() {
    int n, m;
    cin >> n >> m; // Number of nodes and edges
 
    graph.resize(n + 1);
 
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    findCycle(n);
 
    return 0;
}
