#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define file "test"
using namespace std;
const ll N = 1e5 + 5; 
const ll MOD = 1e9 + 7;
 
ll n, m, p[N], tv[N];
vector <int> g[N];
 
void bfs(int i) {
    p[i] = 1;
    queue <int> qu;
    bool ok = true;
    qu.push(i);
    while (!qu.empty() && ok) {
        int u = qu.front();
        qu.pop();
        for (int j : g[u]) 
            if (!p[j]) {
                qu.push(j);
                p[j] = 1;
                tv[j] = u;
                if (j == 1) {
                    ok = false;
                    break;
                }
            }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen(file".inp","r",stdin); freopen(file".out","w",stdout);
    #endif
    
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    bfs(n);
 
    if (!tv[1]) cout << "IMPOSSIBLE";
    else {
        vector <int> a;
        int i = 1;
        while (i != 0) {
            a.push_back(i);
            i = tv[i];
        }
        cout << a.size() << '\n';
        for (int i : a) cout << i << ' ';
    }
}
