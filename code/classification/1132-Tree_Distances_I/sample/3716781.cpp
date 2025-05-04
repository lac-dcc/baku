#include <bits/stdc++.h>
 
using namespace std;
#ifdef lol
const int dbg = 1;
#else
const int dbg = 0;
#endif
#define fin(i, s, n) for(auto i = s; i < n; ++i)
#define fine(i, s, n) for(auto i = s; i <= n; ++i)
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define all(x) (x).begin(),(x).end()
#define chkmin(a, b) a = min(a,b)
#define chkmax(a, b) a = max(a,b)
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
const int maxn = 2e5+5;
vii g[maxn];
int ans[maxn];
int calcdfs(int u, int p) {
    for (auto &e : g[u]) if(e.x!=p&&e.x!=-1) e.y = calcdfs(e.x, u);
    partial_sort(g[u].begin(), g[u].begin() + 2, g[u].end(),[](const ii& a, const ii& b) { return a.y > b.y; });
    return g[u][0].y + 1;
}
 
void ansdfs(int u, int p,int v) {
    ans[u] = max(g[u][0].y, v);
    int A = ans[u]+1, other = max(g[u][1].y,v)+1;
    for (auto &e : g[u]) if(e.x!=p&&e.x!=-1) ansdfs(e.first,u,ans[u] == e.y ? other : A);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    fin(i,0,n) g[i].eb(-1,0);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a,--b;
        g[a].eb(b,0),g[b].eb(a,0);
    }
    calcdfs(0,0);
    ansdfs(0,0,0);
    ans[0] = g[0][0].y;
    cout << ans[0];
    for(int i = 1; i < n; ++i) cout << ' ' << ans[i];
    return 0;
}
