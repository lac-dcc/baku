#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           200005
#define  pb           push_back
#define  int          long long
#define  PII          pair<pair<int,int> ,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;
 
int dp[MX], n;
vector<PII> v;
 
int call(int pos)
{
   if (pos >= n) return 0;
   if (dp[pos] != -1) return dp[pos];
 
   PII p = {{v[pos].ff.ss, 1e10}, 1e10};
   int nxt = upper_bound(all(v), p) - v.begin();
 
   int r1 = v[pos].ss + call(nxt);
   int r2 = call(pos + 1);
 
   return dp[pos] = max(r1, r2);
}
void Solve(int tc)
{
   memset(dp, -1, sizeof(dp));
   cin >> n;
   rep(i, 1, n) {
      int a, b, p;
      cin >> a >> b >> p;
      v.pb({{a, b}, p});
   }
   sort(all(v));
   cout << call(0);
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
 
   int T = 1;
   //cin >> T;
 
   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }
 
   return 0;
}
