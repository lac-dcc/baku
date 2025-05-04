#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
constexpr int maxn = 1e5;
 
int parent[maxn + 1] = { 0 };
 
vector <int> output;
bool finished = false;
int dfs(const vector<vector<int>>&adj, int pos)
{
    for (int i : adj[pos])
    {
        if (finished) break;
 
        if (i == parent[pos]) continue;
 
        if (parent[i] != 0) {
            // Found a cycle
            output.emplace_back(i);
            output.emplace_back(pos);
            finished = true;
            return 1;
        } 
 
        parent[i] = pos;
 
        if (dfs(adj, i) != -1)
        {
            output.emplace_back(pos);
            if (output[0] == pos) return -1;
            return 1;
        }
    }
    return -1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
 
 
    vector <vector <int>> adj(n + 1);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
 
    for (int i = 1; i <= n; i++)
    {
        if (finished) break;
        if (parent[i] != 0) continue;
        parent[i] = i;
        dfs(adj, i);
    }
 
    
 
    if (output.size() == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    cout << output.size() << "\n";
    for (int i : output) cout << i << " ";
    cout << "\n";
}
