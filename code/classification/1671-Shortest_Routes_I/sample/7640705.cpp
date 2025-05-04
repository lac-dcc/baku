#include <iostream>
#include <vector>
#include <queue>
#include <limits>
 
using namespace std;
 
struct Edge {
    int to, cost;
};
 
const long long INF = numeric_limits<long long>::max();
 
void dijkstra(int n, vector<vector<Edge>>& graph, vector<long long>& distances) {
    distances[1] = 0; // Syrjälä is the starting city
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1}); // {distance, city}
 
    while (!pq.empty()) {
        long long distance = pq.top().first;
        int city = pq.top().second;
        pq.pop();
 
        if (distance > distances[city]) {
            continue; // Skip if we already found a shorter path
        }
 
        for (const Edge& edge : graph[city]) {
            long long new_distance = distances[city] + edge.cost;
            if (new_distance < distances[edge.to]) {
                distances[edge.to] = new_distance;
                pq.push({new_distance, edge.to});
            }
        }
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<Edge>> graph(n + 1); // 1-based index
    vector<long long> distances(n + 1, INF);
 
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph [a].push_back({b, c});
    }
 
    dijkstra(n, graph, distances);
 
    for (int i = 1; i <= n; ++i) {
        cout << distances[i] << " ";
    }
 
    cout << endl;
 
    return 0;
}
