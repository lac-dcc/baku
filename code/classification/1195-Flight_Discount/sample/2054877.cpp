/**
 * Created by prayutsu
 * at 9:59 PM on April 26, 2021.
 */
 
#include <bits/stdc++.h>
 
using namespace std;
 
// 
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll long long
using namespace __gnu_pbds;
#define pir pair< ll, ll >
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define vt vector<ll>
#define ve vector
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007ll
#define sortf(v) sort(v.begin(), v.end())
#define all(c) (c).begin(), (c).end()
#define in read
#define setp(precision, double_number) fixed << setprecision(precision) << double_number
 
#define sz(x) (ll)(x).size()
#define fr(i, a, b, s) for (ll i=(a); (s)>0 ? (i)<(b) : (i)>(b); (i)+=(s))
#define fr1(e) fr(i, 0ll, e, 1ll)
#define fr2(i, e) fr(i, 0ll, e, 1ll)
#define fr3(i, b, e) fr(i, b, e, 1ll)
#define fr4(i, b, e, s) fr(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define frc(...) GET5(__VA_ARGS__, fr4, fr3, fr2, fr1)
#define FOR(...) frc(__VA_ARGS__)(__VA_ARGS__)
#define repc(i, a, b, c) for (ll i=(a); i<=(b); i+=c)
#define perc(i, a, b, c) for (ll i=(a); i>=(b); i+=c)
#define rep(i, a, b) repc(i, a, b, 1)
#define per(i, a, b) perc(i, a, b, -1)
#define rep0(i, b) rep(i, 0, b)
 
#define debi(x, i) cout<<#x<<" in "<< #i << ' ' << (i) <<" = "<<(x)<<"\n";
#define debsi(x, i) cout<<#x<<" in "<< #i << ' ' << (i) << " = "<<(x)<<" ";
#define deb(x) cout<<#x<<" = "<<(x)<<'\n';
#define case(count) cout<<"Case #"<<(count)<<": ";
#define show(a) for(int i=0; i<(a).size(); i++) cout<<(a)[i]<<' '; cout<<'\n';
#define each(x, a) for (auto& (x): (a))
#define fill(a, b) memset(a, b, sizeof(a))
 
const ll maxn = 200005;
ll fac[maxn];
 
void factorial() {
    fac[0] = 1ll;
    for (ll i = 1ll; i < maxn; i++) fac[i] = (fac[i - 1] * i) % mod;
}
 
ll power(ll x, ll y, ll p) {
    ll res = 1ull;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
ll modInverse(ll n, ll p) { return power(n, p - 2, p); }
 
ll nCrModPFermat(ll n, ll r, ll p) {
    if (r == 0) return 1ll;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
 
ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}
 
template<class A>
void read(ve<A> &x);
 
template<class A, size_t S>
void read(array<A, S> &x);
 
template<class T>
void read(T &x) {
    cin >> x;
}
 
void read(double &d) {
    string t;
    read(t);
    d = stod(t);
}
 
void read(long double &d) {
    string t;
    read(t);
    d = stold(t);
}
 
template<class H, class... T>
void read(H &h, T &... t) {
    read(h);
    read(t...);
}
 
template<class A>
void read(ve<A> &x) {
    each(a, x)read(a);
}
 
template<class A, size_t S>
void read(array<A, S> &x) {
    each(a, x)read(a);
}
 
string to_string(char c) {
    return string(1, c);
}
 
string to_string(ve<bool> v) {
    string res;
    FOR(sz(v))res += char('0' + v[i]);
    return res;
}
 
/** Use %mod to evaluate large powers %mod */
long long fastpow(long long a, long long b) {
    long long res = 1ll;
    while (b > 0ll) {
        if (b & 1ll)
            res = res * a;
        a = a * a;
        b >>= 1ll;
    }
    return res;
}
 
ll n, m; // Number of nodes and edges respectively.
const ll inf = 1e18 + 5;
// Second element in pair is cost and first is node.
ve<ve<pir>> adj1, adj2; // Don't forget to resize adjacency list.
vt dis, dis2;
 
void dijkstra(ll s, vt &mind, ve<ve<pir>> &adj) {
    mind.assign(n + 1, inf);
    mind[s] = 0ll;
    priority_queue<pir, vector<pir >, greater<>> q;
    q.push({0ll, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != mind[v]) continue;
 
        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;
            if (mind[v] + len < mind[to]) {
                mind[to] = mind[v] + len;
                q.push({mind[to], to});
            }
        }
    }
}
 
ll ans = LONG_LONG_MAX;
ve<bool> vis;
 
void dfs(ll v) {
    vis[v] = true;
    for(pir edge: adj1[v]) {
        ll u = edge.fi, len = edge.se;
        ans = min(ans, dis[v] + (len/2ll) + dis2[u]);
        if (!vis[u]) {
            dfs(u);
        }
    }
}
 
void solve() {
    in(n, m);
    adj1.resize(n+1);
    adj2.resize(n+1);
    vis.resize(n+1, false);
    rep0(i, m-1) {
        ll a, b, c;
        in(a, b, c);
        adj1[a].pb(mp(b, c));
        adj2[b].pb(mp(a, c));
    }
    dijkstra(1, dis, adj1);
    dijkstra(n, dis2, adj2);
    dfs(1);
    cout<<ans;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
#ifndef ONLINE_JUDGE
    freopen("/home/prayutsu/inputs.txt", "r", stdin);
    freopen("/home/prayutsu/outputs.txt", "w", stdout);
    freopen("/home/prayutsu/errors.txt", "w", stderr);
#endif
    solve();
}
