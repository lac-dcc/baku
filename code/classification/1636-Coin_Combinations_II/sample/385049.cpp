#include<bits/stdc++.h>
#define sz(x) (int)(x).size()
#define trav(x, a) for (auto& x: a)
#define st first
#define nd second
#define pii pair<int,int>
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;
const int mod = 1e9 + 7;
int dp[1000005], a[102], n;
 
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(0); cout << fixed << setprecision(10);
  int x; cin >> n >> x;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = a[i]; j <= x; j++) {
      dp[j] += dp[j-a[i]];
      if (dp[j] >= mod)
        dp[j] -= mod;
    }
  }
  cout << dp[x] << endl;
}