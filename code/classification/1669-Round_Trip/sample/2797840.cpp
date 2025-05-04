#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define se second
#define fi first
 
typedef map<int, int> mi;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
 
vi adj[400005];
int vis[400005] = {0}, par[400005] = {0};
int node, node1, flag = 0, f = 0;
 
void dfs(int n, int p) {
    vis[n] = 1;
    par[n] = p;
 
    for(auto child:adj[n]) {
        if(f) return;
        if(!vis[child]) {
            dfs(child, n);
        }
        else {
            if(child != p) {
                node = child;
                node1 = n;
                flag = 1;
                f = 1;
                return;
            }
        }
    }
 
    if(f) return;
}
 
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n, m;
    cin >> n >> m;
 
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
 
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    for(int i=1; i<=n; i++) {
        if(!vis[i]) 
            dfs(i, -1);
    }
 
    if(!flag) {
        cout << "IMPOSSIBLE";
    }
    else {
        vi v;
        v.pb(node);
        int pare = par[node1];
        while(pare != par[node]) {
            v.pb(node1);
            node1 = par[node1];
            pare = par[node1];
        }
        v.pb(node);
        cout << v.size() << '\n';
        for(auto i:v) {
            cout << i << ' ';
        }
    }
 
    return 0;
}
