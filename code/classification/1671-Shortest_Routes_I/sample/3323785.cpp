#include <bits/stdc++.h>
 
using namespace std;
 
#define M 1000000007
 
int main() {
    int64_t n, m;
    cin >> n >> m;
    vector<pair<int64_t,int64_t>> graph[n+1];
    for (int i = 0; i < m; i++) {
        int64_t u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    //int64_t distances[n+1] = {0};
    vector<int64_t> distances(n + 1, 0);
    //bool visited[n+1] = {0};
    vector<bool> visited(n + 1, 0);
    visited[1] = true;
    priority_queue<pair<int64_t,int64_t>> queue;
    for (auto p : graph[1]) {
        queue.push({-p.second, p.first});
    }
 
    while (!queue.empty()) {
        auto p = queue.top();
        queue.pop();
        if (visited[p.second]) continue;
        visited[p.second] = true;
        distances[p.second] = -p.first;
        for (auto q : graph[p.second]) {
            if (visited[q.first]) continue;
            queue.push({p.first - q.second, q.first});
        }
    }
 
    for (int i = 1; i < n+1; i++) cout << distances[i] << " ";
}
