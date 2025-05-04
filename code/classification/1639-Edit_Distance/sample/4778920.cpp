#include <bits/stdc++.h>
 
#define _USE_MATH_DEFINES
#define MULTITEST !true
 
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf ll(1e9)
#define INF ll(1e18)
#define all(a) a.begin(), a.end()
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<pii> vp;
 
void solve() {
  string a, b;
  cin >> a >> b;
  vector<vi> dp(5010, vi(5010, INF));
  for (int i = 0; i <= b.size(); i++) dp[0][i] = i;
  for (int i = 0; i <= a.size(); i++) dp[i][0] = i;
  for (int i = 1; i <= a.size(); i++)
    for (int j = 1; j <= b.size(); j++)
      dp[i][j] = min({dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]),
                      dp[i - 1][j] + 1, 
                      dp[i][j - 1] + 1});
  cout << dp[a.size()][b.size()] << "\n";
}
 
int main() {
  speed
  int t = 1;
  if (MULTITEST) cin >> t;
  while (t--) {
    solve();
  }
}