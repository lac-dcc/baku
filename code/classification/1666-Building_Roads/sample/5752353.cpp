#include<bits/stdc++.h>
using namespace std;
vector<int>components;
const int maxi = 1e5 + 10;
void dfs(int node, vector<int> visited, vector<int>adj[]) {
    visited[node] = 1;
    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(it, visited, adj);
        }
    }
}
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>adj[maxi];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //int visited[n+1] = {0};
    vector<int> visited(n + 1, 0);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj);
            count++;
            components.push_back(i);
 
        }
    }
    cout << count - 1 << endl;
    for (int i = 1; i < (int)components.size(); i++) {
        cout << components[i - 1] << " " << components[i] << endl;
    }
}
 
signed main() {
  
 
    int tc = 1;
    // cin>>tc;
    while (tc--) {
        solve();
    }
    return 0;
 
}
