#include <bits/stdc++.h>
 
 
using namespace std;
 
 
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
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
/*******  All Required define Pre-Processors and typedef Constants *******/
#define mem(a, b) memset(a, (b), sizeof(a))
#define rep(i, k) for (int i = 0; i < k; i++)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define INF 1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define LLINF 1e14
#define sz(a) int(a.size())
#define ff first
#define ss second
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vp;
typedef vector<vp> vvp;
 
 
void solve(){
   ll n;
   cin >> n;
   ll t;
 
   ll temp = 0, ans = -1000000000, Max = -1000000000;
 
   for (ll i = 0; i < n; i++) {
      cin >> t;
      Max = max(Max, t);
      if (temp + t >= 0) temp += t;
      else {
         temp = 0;
      }
      ans = max(ans, temp);
   }
   ans = max(ans, temp);
   if (Max < 0) ans = Max;
   cout << ans << '\n';
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
 
   solve();
   
   
    return 0;    
}
 
 
