#include<bits/stdc++.h>
using namespace std;
 
const int  N = 100000;
 
vector<int> adj[N + 1];
int vis[N + 1];
 
void dfs(int u) {
    if(vis[u] == 1) return;
    vis[u] = 1;
    for(int v: adj[u]) {
        dfs(v);
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int city = -1;
    vector<pair<int, int>> roads;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            dfs(i);
            if(city != -1) {
                roads.push_back({city, i});
            }
            city = i;
        }
    }
    cout << roads.size() << "\n";
    for(auto it: roads) {
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}
