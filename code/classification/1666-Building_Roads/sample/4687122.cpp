#include <bits/stdc++.h>
 
using namespace std;
 
vector< vector<int> > cluster;
vector<bool> visited(100000, false);
 
void clus(vector< vector<int> >&adj, int node, int curr_clus) {
    if (visited[node]) {return;}
    cluster[curr_clus].push_back(node);
    visited[node] = true;
    for (int e : adj[node]) {
        if (visited[e]) {continue;}
        clus(adj, e, curr_clus);    
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector< vector<int> > adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {continue;}
        vector<int> new_clus;
        cluster.push_back(new_clus);
        clus(adj, i, cluster.size() - 1);
    }
    cout << cluster.size() - 1 << "\n";
    for (int i = 0; i < cluster.size() - 1; i++) {
        cout << cluster[i][0] << " " << cluster[i+1][0] << "\n";
    }
    return 0;
}
