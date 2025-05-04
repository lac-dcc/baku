#include <bits/stdc++.h>
using namespace std;
 
#define F first
#define S second
#define B begin()
#define E end()
#define PB push_back
#define ar array
#define sz size()
#define FOR(i,a,b) for (int i = a; i < b; i++)
 
typedef long long ll;
typedef unordered_set<int> sti;
typedef unordered_map<int,int> mpi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pi;
 
const int MOD = 1e9+7, mxN = 1e5;
int n, m, p[mxN+1];
vector<vector<int>> adj_l(mxN + 1);
bool vis[mxN];
vector<int> ans;
void dfs(int i, int par) {
    if (vis[i]) {
        unordered_set<int> seen;
        ans.push_back(i);
        seen.insert(i);
        while (!seen.count(par)) {
            ans.push_back(par);
            seen.insert(par);
            par = p[par];
        }
        ans.push_back(i);
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i]+1 << ' ';
        }
        exit(0);
    }
    vis[i] = true;
    p[i] = par;
    for (int adj : adj_l[i]) {
        if (adj == par) continue;
        dfs(adj, i);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
        int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b, a--, b--;
        adj_l[a].push_back(b);
        adj_l[b].push_back(a);
    }
    for (int i = 0; i < n; i ++) {
        if (vis[i] or !adj_l[i].size()) continue;
        memset(p, 0, sizeof p);
        // memset(vis, false, sizeof vis);
        dfs(i, -1);
    }
    cout << "IMPOSSIBLE";
}
