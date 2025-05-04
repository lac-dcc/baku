#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<int> al[n + 1];
    vector<bool> visited(n + 1, 0);
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
 
    function<void(int)> dfs = [&](int i) {
        visited[i] = 1;
        for (int v : al[i]) if (!visited[v]) dfs(v);
    };
 
    vector<int> roads;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            roads.push_back(i);
        }
    }
    cout << roads.size() - 1 << "\n";
    for (int i = 0; i < (int)roads.size() - 1; i++) {
        cout << roads[i] << " " << roads[i+1] << "\n";
    }
}
