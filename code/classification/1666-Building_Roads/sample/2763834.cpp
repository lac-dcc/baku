#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define nl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sof(v) (int)v.size()
 
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v) {
    for(const T &val: v)
        cout << val << ' ';
    return os;
}
 
int current_case;
 
const int N = 1e5 + 7;
bool vis[N];
vector<int> adj[N];
 
void dfs(int u) {
    vis[u] = true;
    for(int &v: adj[u]) {
        if(!vis[v])
            dfs(v);
    }
}
 
void run_case() {
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(1);
    vector<pair<int,int>> ans;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            ans.push_back({1, i});
            dfs(i);
        }
    }
 
    cout << sof(ans) << nl;
    for(auto &p: ans)
        cout << p.first << ' ' << p.second << nl;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 
    int test_cases = 1;
    for (current_case = 1; current_case <= test_cases; current_case++)
        run_case();
}