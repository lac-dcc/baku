#include <iostream>
#include <vector>
#include <limits>
#include <queue>
 
using namespace std;
 
struct Node {
    long long dist;
    int id;
    Node(int id, long long dist) : id(id), dist(dist) {}
};
 
struct Comparator {
    bool operator()(const Node& lhs, Node& rhs) const {
        return lhs.dist > rhs.dist; // this is min heap
    }
};
 
vector<long long> calcDist(int startNode, vector< vector< Node > >& graph) {
    vector<long long> distance(graph.size(), numeric_limits<long>::max());
    priority_queue< Node, vector<Node>, Comparator > pq;
 
    distance[startNode] = 0;
    pq.push({0, startNode});
 
    while( !pq.empty() ) {
 
        auto [dist, node] = pq.top();
        pq.pop();
 
        if (distance[node] < dist) continue;
 
        for (auto &[weight, nextNode] : graph[node])
            if (distance[nextNode] > dist + weight) {
                distance[nextNode] = dist + weight;
                pq.push({nextNode, distance[nextNode]});
            }
 
    }
    return distance;
}
 
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    vector< vector< Node > > graph(1e5);
 
    int n, m;
    long long d;
 
    cin >> n >> m;
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b >> d;
        graph[--a].emplace_back(--b, d);
    }
 
    auto getDistances = calcDist(0, graph);
 
    for (int i = 0; i < n; i++)
        cout << getDistances[i] << " ";
 
    return 0;
}
