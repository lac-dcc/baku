#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define io() ios_base::sync_with_stdio(!cin.tie(0));
#define dbg(...)
#endif 
 
const int X = 1e6, mod = 1e9 + 7;
int dp[X + 1], c[100];
void solve () {
   int n, x;
   cin >> n >> x;
   for (int i = 0; i < n; i++) cin >> c[i];
   dp[0] = 1;
   for (int i = 0; i < x; i++) {
      for (int j = 0; j < n; j++) {
         if (dp[i] != 0 && i + c[j] <= x) {
            dp[i + c[j]] = (dp[i + c[j]] + dp[i]) % mod;
         }
      }
   }
   cout << dp[x] << '\n';
}
 
int main() {
   io();
   int t = 1;
   // cin >> t;
   while (t--) {
      solve ();
   }   
   return 0;
}
