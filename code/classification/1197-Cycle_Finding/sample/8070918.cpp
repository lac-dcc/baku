/*                  __      __
                   /\ \    /\ \
 _____      __     \_\ \   \_\ \  __  __  __  __  __    ___    ____
/\ '__`\  /'__`\   /'_` \  /'_` \/\ \/\ \/\ \/\ \/\ \  /'___\ /',__\
\ \ \L\ \/\ \L\.\_/\ \L\ \/\ \L\ \ \ \_\ \ \ \_/ \_/ \/\ \__//\__, `\
 \ \ ,__/\ \__/.\_\ \___,_\ \___,_\ \____/\ \___x___/'\ \____\/\____/
  \ \ \/  \/__/\/_/\/__,_ /\/__,_ /\/___/  \/__//__/   \/____/\/___/
   \ \_\                 ____________________
    \/_/                /nowl/
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
#define ull unsigned long long
#define ll long long
#define ld double
#define yes {cout << "YES"; return;}
#define no {cout << "NO"; return;}
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using pii = pair<int,int>;
constexpr int mod = 1e9 + 7;
constexpr ll oo = 1e18;
constexpr ld eps = 1e-9;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
#define fi first
#define se second
#define name "pad"
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define For(i, l, r) for(int i = (l); i <= (r); ++i)
#define Ford(i, r, l) for(int i = (r); i >= (l); --i)
#define FindId(x, v) lower_bound(all(v), x) - (v).begin() + 1
 
template<typename T> bool maximize(T &a, T b) { return a < b && (a = b, true); }
template<typename T> bool minimize(T &a, T b) { return a > b && (a = b, true); }
template<typename T> void compress(vector<T> &v) { sort(all(v)); v.resize(unique(all(v)) - v.begin()); }
 
const int N = 2505;
vector<pii> adj[N];
int n, m;
int d[N], trace[N], cnt[N];
bool inQueue[N];
 
int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    freopen(name".inp", "r", stdin);
//    freopen(name".out", "w", stdout);
 
    cin >> n >> m;
    For(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
 
    memset(d, 63, (n + 1) * sizeof(int));
    int node = -1;
    For(i, 1, n) if(d[i] == inf) {
        d[i] = 0;
        queue<int> q; q.push(i); inQueue[i] = true;
        while(!q.empty()) {
            int u = q.front(); q.pop(); inQueue[u] = false;
            if(++cnt[u] > n) {
                node = u; break;
            }
            for(auto [v, w] : adj[u]) if(minimize(d[v], d[u] + w)) {
                trace[v] = u;
                if(!inQueue[v]) q.push(v);
            }
        }
        if(node != -1) break;
    }
 
    if(node == -1) return cout << "NO", 0;
    cout << "YES" << '\n';
    For(i, 1, n) node = trace[node];
 
    vector<int> res;
 
    res.push_back(node);
    int tmp = trace[node];
    while(tmp != node) res.push_back(tmp), tmp = trace[tmp];
    res.push_back(node);
 
    reverse(all(res));
    for(int x : res) cout << x << ' ';
 
    return 0;
}
