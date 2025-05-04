#include <bits/stdc++.h>
using namespace std;
 
void _print() { cerr << "]" << endl; }
template<typename T, typename... V>
void _print(T t, V... v) { cerr << t; if (sizeof...(v)) cerr << ", "; _print(v...); }
 
#define dbg(x...) cerr << "[" << #x << "]: ["; _print(x)
#define endl '\n'
#define ll long long
#define sz(x) int(x.size())
 
#define ii pair<int, int>
#define ff first
#define ss second
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> g[n + 1];
    for (int i = 0; i < n - 1; ++i) {
        int v, u; cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    vector<int> dist;
    auto bfs = [&](int v) {
        dist.assign(n + 1, -1);
        queue<int> qu;
        qu.push(v);
        dist[v] = 0;
        while (sz(qu)) {
            v = qu.front();
            qu.pop();
            for (int &u : g[v]) {
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    qu.push(u);
                }
            }
        }
    }; 
    bfs(1);
    int c = 1, mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > mx) {
            mx = dist[i];
            c = i;
        }
    }
    bfs(c);
    cout << *max_element(dist.begin(), dist.end()) << endl;
    return 0;
}


