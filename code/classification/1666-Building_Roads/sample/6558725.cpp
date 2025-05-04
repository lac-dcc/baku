#include<bits/stdc++.h>
 
using namespace std;
 
void dfs(int s, bool * visited, vector<int>*adj) {
    if (visited[s]) return;
    visited[s] = true;
    for(int i = 0; i < adj[s].size(); i++) {
        dfs(adj[s][i], visited, adj);
    }
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t = 1;
    //cin >> t;
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> adj[n + 1];
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        } 
        bool visited[n + 1];
        for(int i = 0; i < n + 1; i++) {
            visited[i] = false;
        }
        int count = 0;
        vector<pair<int, int> > edjes;
        dfs(1, visited, adj);
        for(int i = 2; i <= n; i++) {
            if(!visited[i]) {
                count++;
                dfs(i, visited, adj);
                edjes.push_back(make_pair(i-1, i));
                adj[i - 1].push_back(i);
                adj[i].push_back(i - 1);
            }
        }
        cout << count << '\n';
        for(auto x: edjes) {
            cout << x.first << ' ' << x.second << '\n';
        }
    }
    return 0;
}
