#include <bits/stdc++.h>
using namespace std;
 
typedef struct _Node {
    int node;
    long long distance;
} Node;
 
struct NodeComp {
    bool operator() (const Node &n1, const Node &n2) {
        return n1.distance > n2.distance;
    }
};
 
struct Edge {
    int u, v, w;
};
 
typedef vector<vector<Node>> WGraph;
typedef priority_queue<Node, vector<Node>, NodeComp> PQ;
 
void djikstra(WGraph& graph, PQ& nodes, vector<long long>& distances) {
    while(!nodes.empty()) {
        auto node = nodes.top();
        nodes.pop();
        
        if(distances[node.node] == -1) {
            distances[node.node] = node.distance;
        } else {
            continue;
        }
 
        for(auto i:graph[node.node]) {
            nodes.push({i.node, node.distance + i.distance});
        }
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    WGraph graph1(n+1);
    WGraph graph2(n+1);
    vector<Edge> edges;
 
    for(int i=1;i<=m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph1[a].push_back(Node{b, c});
        graph2[b].push_back(Node{a, c});
        edges.push_back(Edge{a, b, c});
    }
    PQ nodes;
    vector<long long> distances1(n+1, -1);
    vector<long long> distances2(n+1, -1);
    nodes.push(Node{1, 0});
    djikstra(graph1, nodes, distances1);
    nodes.push(Node{n, 0});
    djikstra(graph2, nodes, distances2);
 
    long long mi = distances1[n];
    for(auto edge:edges) {
        if(distances1[edge.u] != -1 && distances2[edge.v] != -1)
            mi = min(mi, distances1[edge.u] + edge.w/2 + distances2[edge.v]);
    }
 
    cout << mi << " ";
    cout << "\n";
}
 
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // int T;
    // cin >> T;
    // while(T--)
        solve();
    return 0;
}
