#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
 
int treedistance(const vector<vector<int>>& adj, vector<int>& xs, int s) {
    assert(adj.size() == xs.size());
    queue<int> qs;
    int n = adj.size(), curr = 0, p, u = 0, d;
    vector<int> ds(n);
    vector<bool> seen(n);
    seen[s] = true;
    qs.push(s);
    while (!qs.empty()) {
        p = qs.front();
        qs.pop();
        if (curr <= ds[p]) curr = ds[p], u = p;
        if (xs[p] < ds[p]) xs[p] = ds[p];
        d = ds[p]+1;
        for (auto& j: adj[p]) {
            if (seen[j] || d <= ds[j]) continue;
            seen[j] = true;
            qs.push(j);
            ds[j] = d;
            qs.push(j);
        }
    }
    return u;
}
pair<int,int> treediameter(const vector<vector<int>>& adj, vector<int>& xs, int s) {
    int u = treedistance(adj,xs,s);
    int v = treedistance(adj,xs,u);
    return {u,v};
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> xs(n);
    for (int i = 1 , u, v; i < n; ++i) {
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto p = treediameter(adj,xs,0);
    cout << xs[p.second];
    return 0;
}
