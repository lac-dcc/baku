#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
//( Experimental Template (x1.2.2) (cf/cebolinha)
// x1.2.2 - Added loads of const& to the output functions so they're faster
#pragma GCC optimize("Ofast")
#pragma GCC target("fma")
 
template<typename T> using V = vector<T>;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
 
// This is commented because it doesn't coexist with "#define int long long"
// order_of_key(x) (amount of elements less than x)
// find_by_order(n) (nth element of set)
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T> using OS = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(v) (int)v.size()
#define loop(ii, n) for (int ii = 0; ii < (n); ++ii)
#define xloop(ii, l, r) for (int ii = (l); ii <= (r); ++ii)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define cond(c, t, f) ((c) ? (t) : (f))
#define mem(a, b) memset(a, (b), sizeof(a))
#define inbounds(x, l, r) ((l) <= (x) && (x) <= (r))
#define ff first
#define ss second
#define nemo ><>
#define L1(res...) [&](auto x){ return res; }
#define L2(res...) [&](auto x, auto y){ return res; }
 
template <typename T, typename U> inline void miq(T& a, U b){if (a > b) a = b;}
template <typename T, typename U> inline void maq(T& a, U b){if (a < b) a = b;}
 
template <typename T> istream &operator>>(istream &is, vector<T> &v) {
  for (auto &a : v) is >> a; return is; }
template <typename T> ostream &operator<<(ostream &os, vector<T> const& v) {
  loop(i, sz(v)) os << cond(i," ","") << v[i]; return os; }
template <typename T> ostream &operator<<(ostream &os, set<T> const& s) {
  for (auto it = s.begin(); it != s.end(); it++) os << cond(it != s.begin()," ","") << *it; return os; }
 
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
 
template <typename... A> void in(A &...a) { ((cin >> a), ...); }
template <typename... A> void out(A const&... a) { ((cout << a << " "), ...); cout << endl; }
template <typename... A> void print(A const&... a) { ((cout << a), ...); }
#define var(x) "[", #x, " ", x, "] "
template <typename... A> void db(A const&... a) { ((cout << (a)), ...); cout << endl; }
template<typename T>
using minPQ  = priority_queue<T, V<T>, greater<T>>;
//)
 
signed main(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    loop(i, n - 1){
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int start = 0;
    queue<int> q; q.push(0);
    vector<bool> vis(n);
    while(!q.empty()){
        start = q.front(); q.pop();
        vis[start] = true;
        for(auto u : adj[start]){
            if(vis[u]) continue;
            q.push(u);
        }
    }
    int ans = 0;
    queue<ii> qq; qq.push(make_pair(start, 0));
    vis.assign(n, false);
    while(!qq.empty()){
        auto [now, dist] = qq.front(); qq.pop();
        vis[now] = true;
        ans = dist;
        for(auto u : adj[now]){
            if(vis[u]) continue;
            qq.push(make_pair(u, dist + 1));
        }
    }
    cout << ans << "\n";
}
