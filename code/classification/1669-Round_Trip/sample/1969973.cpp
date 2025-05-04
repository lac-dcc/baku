#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
 
using namespace std;
 
vector<set<int>> a;
vector<int> visited;
vector<int> prevv;
 
void dfs(int u) {
    visited[u] = true;
    for(int v : a[u]) {
        if (v == prevv[u]) continue;
        if (!visited[v]) {
            //cout << "Going from " << u << " to " << v << "\n";
            prevv[v] = u;
            dfs(v);
        } else if (visited[v]) {
            //cout << "Cycle found at " << u << " --> " << v << "\n";
            prevv[v] = u;
            list<int> path;
            int start = v;
            path.push_front(v);
            int curr = u;
            while(curr != start) {
                path.push_front(curr);
                curr = prevv[curr];
            }
            path.push_front(curr);
 
            cout << (int)path.size() << "\n";
            for(auto e : path) {
                cout << e << ' ';
            }
            exit(0);
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0); 
    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    visited.resize(n + 1, false);
    prevv.resize(n + 1, -1);
 
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        a[u].insert(v);
        a[v].insert(u);
    }
 
    for(int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
 
    cout << "IMPOSSIBLE";
    return 0;
}
