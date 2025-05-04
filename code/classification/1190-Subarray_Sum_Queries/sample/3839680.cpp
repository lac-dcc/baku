/*
 
"It's a slow process,
but quitting won't speed it up"
 
*/
 
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define cld complex<ld>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vld vector<ld>
#define vvld vector<vector<ld>>
#define vpll vector<pll>
#define vcld vector<cld>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define eb emplace_back
#define PI acos(-1)
#define endl "\n"
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()
#define rev(p) reverse(p.begin(),p.end());
#define mset(a,val) memset(a,val,sizeof(a));
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define popcount(x) __builtin_popcountll(x)
#define sz(x) ((ll)x.size())
#define FOR(i,a,b)  for(ll i=a;i<=b;i++)
#define FORR(i,a,b)  for(ll i=a;i>=b;i--)
 
const ll N = 2e5 + 5;
 
const ll M = 1000000007;
 
const ll MM = 998244353;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
 
ll begtime = clock();
#define end_routine() cerr << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void __print(const complex<long double> &x) {cerr << '{'; __print(x.real()); cerr << ','; __print(x.imag()); cerr << '}';}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
 
 
template<typename T, typename F>
void chmax( T &a, F b) {
  if (b > a)a = b;
}
 
template<typename T, typename F>
void chmin( T &a, F b) {
  if (b < a)a = b;
}
 
 
ll powM(ll a, ll b, ll m)
{
  if (a <= 0)return 0;
  a %= m;
 
  ll ans = 1LL;
  while (b)
  {
    if (b & 1)ans = ans * a % m;
    //ans = mulmod(ans, a, m);
    a = a * a % m;
    //a = mulmod(a, a, m);
    b >>= 1;
  }
 
  return ans;
}
 
 
 
ll poww(ll a, ll b)
{
  if (b < 0)return 0;
  ll ans = 1;
  while (b)
  {
    if (b & 1)ans = ans * a;
    a = a * a;
    b >>= 1;
  }
 
  return ans;
 
}
 
 
 
void OJ() {
 
 
#ifndef ONLINE_JUDGE
 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
 
#endif
 
}
 
struct gen {
  ll sum, pr, sf, res;
};
 
 
vl a;
vector<gen> sg;
 
void combine(ll x) {
  sg[x].sum = sg[2 * x].sum + sg[2 * x + 1].sum;
  sg[x].pr = max(sg[2 * x].pr, sg[2 * x].sum + sg[2 * x + 1].pr);
  sg[x].sf = max(sg[2 * x + 1].sf, sg[2 * x + 1].sum + sg[2 * x].sf);
 
  sg[x].res = max({sg[2 * x].res, sg[2 * x + 1].res, sg[2 * x].sf + sg[2 * x + 1].pr});
 
}
 
void build(ll x, ll lx, ll rx) {
  if (lx == rx) {
    sg[x].sum = a[lx];
    sg[x].pr = sg[x].sf = sg[x].res = max(a[lx], 0ll);
    return;
  }
  ll mx = (lx + rx) / 2;
  build(2 * x, lx, mx);
  build(2 * x + 1, mx + 1, rx);
  combine(x);
}
 
void update(ll x, ll lx, ll rx, ll idx, ll v) {
  if (lx == rx) {
    sg[x].sum = v;
    sg[x].pr = sg[x].sf = sg[x].res = max(0ll, v);
    return;
  }
  ll mx = (lx + rx) / 2;
  if (idx <= mx) {
    update(2 * x, lx, mx, idx, v);
  } else {
    update(2 * x + 1, mx + 1, rx, idx, v);
  }
  combine(x);
}
 
 
 
ll calc(ll x, ll lx, ll rx, ll l, ll r) {
 
  if (lx >= l && rx <= r)return sg[x].res;
 
  if (lx > r || rx < l)return -1e15;
 
  ll mx = (lx + rx) / 2;
 
 
  return max(calc(2 * x, lx, mx, l, r), calc(2 * x + 1, mx + 1, rx, l, r));
 
}
 
int main() {
 
  IOS;
 
  OJ();
 
 
  ll n, q;
  cin >> n >> q;
 
  a.assign(4 * n, 0);
  sg.assign(4 * n, {0, 0, 0, 0});
 
  FOR(i, 0, n - 1)cin >> a[i];
 
  build(1, 0, n - 1);
 
  while (q--) {
    ll k, x; cin >> k >> x;
    k--;
    update(1, 0, n - 1, k, x);
    cout << calc(1, 0, n - 1, 0, n - 1) << endl;
  }
 
 
  return 0;
 
 
}
 
