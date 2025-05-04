// Problem: Building Teams
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1668
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include "bits/stdc++.h"
 
using namespace std;
 
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) "AiNi BaoBei"
#endif
 
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int p) { return (unsigned int)rng() % p; }
//ll randi64(ll p) { return (unsigned ll)rng() % p; }
ll randi64(ll p) {  
    return static_cast<unsigned long long>(rng()) % p; // Corrected cast  
} 

#define pb push_back
#define eb emplace_back
#define ins insert
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rev(a) std::reverse(all(a))
#define sz(a) int(a.size())
#define each(x, a) for (auto& x : a)
 
// credit: William Lin
#define FOR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define FOR1(e) FOR(_, 0, e, 1)
#define FOR2(i, e) FOR(i, 0, e, 1)
#define FOR3(i, b, e) FOR(i, b, e, 1)
#define FOR4(i, b, e, s) FOR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define FORC(...) GET5(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)
#define loop(...) FORC(__VA_ARGS__)(__VA_ARGS__)
 
constexpr int inf = 1E9 + 5;
constexpr ll INF = 1E18;
constexpr int mod = 1000000007; // 998244353
const ld pi = acos((ld)-1);
const char nl = '\n';
const double EPS = 1E-6;
 
void write(bool result, string end = "\n") { cout << (result ? "YES" : "NO") << end; }
template <typename T> bool ckmax(T &a, T b) { return a < b ? a = b, true : false; }
template <typename T> bool ckmin(T &a, T b) { return a > b ? a = b, true : false; }
 
/* stuff you should look for 
    * check for int overflow
    * check for time complexity (make sure not to TLE)
    * special case (n = 1)
    * make sure to initialize everything (array)
    * don't be lazy, write out your thought and code it out
*/
 
const int N = 100010;
int n, m;
vector<int> adj[N];
bool vis[N];
int id[N];
 
inline void add(int u, int v) {
    --u, --v;
    adj[u].pb(v);
    adj[v].pb(u);
}
 
inline void dep(int u, int mark = 0) {
    vis[u] = true;
    id[u] = mark;
    each(v, adj[u]) {
        if (vis[v]) {
            if (id[u] == id[v]) {
                cout << "IMPOSSIBLE" << nl; exit(0);
            }
        } else {
            dep(v, mark^1);
        }
    }
}
 
int main() 
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    cin >> n >> m;
    memset(id, -1, sizeof id);
    loop(m) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    loop(i, n) if (!vis[i]) dep(i);
    loop(i, n) cout << id[i]+1 << " ";
}
