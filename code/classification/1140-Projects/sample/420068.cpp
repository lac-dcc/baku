// #pragma GCC optimize("O3", "unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
 
typedef long long int ll;
#define endl '\n'
#define ld long double
#define all(a) a.begin(),a.end()
#define int long long
#define pb push_back
#define pii pair <int, int>
#define ff first
#define ss second
#define sz(v) (int)v.size() 
#define UB upper_bound
#define LB lower_bound
#define OST tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
 
const int INF = 1e15 + 0;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const int N = 2e5 + 5;
 
int dp[N], n;
vector <pair <pii, int> > v;
 
int go(int i) {
  if(i == n) return 0;
  int &x = dp[i];
  if(x != -1) return x;
  
  pair <pii, int> p = {{v[i].ff.ss, INF}, INF};
  int nxt = upper_bound(all(v), p) - v.begin();
  int a = v[i].ss + go(nxt);
  int b = go(i+1);
  return (x = max(a, b));
}
 
void solve() {
   memset(dp, -1, sizeof(dp));
   cin >> n;
   for(int i = 1; i <= n; i++) {
     int l, r, p;
     cin >> l >> r >> p;
     v.pb({{l,r}, p});
   }
   sort(all(v));
   cout << go(0) << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif
    int t = 1; // cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}    