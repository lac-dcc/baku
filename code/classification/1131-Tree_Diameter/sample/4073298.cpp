#include <bits/stdc++.h>
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define sqr(a) (1LL * (a) * (a))
using namespace std;
 
#ifdef LOCAL
#include <bug.h>
#else
#define mt(...)
#endif
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// up to ULLONG_MAX = 2^64 - 1
// use: rng()
 
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
 
int powmod(ll a, ll n, int mod = 1000000007) {
    a %= mod; int res = 1;
    while (n) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod; n /= 2;
    }
    return res;
}
 
// https://cses.fi/problemset/task/1131
//-----------------------------------------------------------------------//
const int N = 2e5;
vector<int> g[N + 1];
int max_depth, max_node;
void dfs(int u, int prev, int d) {
    if (g[u].size() == 1 && g[u].back() == prev) {
        if (max_depth < d) {
            max_depth = d;
            max_node = u;
        }
        return;
    }
    for (int &v : g[u]) {
        if (v != prev) {
            dfs(v, u, d + 1);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int t = 1; t <= n - 1; ++t) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1, 0, 0);
    dfs(max_node, 0, 0);
    cout << max_depth << '\n';
    return 0;
}
