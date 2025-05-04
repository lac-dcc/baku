#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll M = 1e9 + 7;
 
//----------Template Above----------
 
vector<ll> ways(1e6+6, -1);
 
ll numberOfWays (ll sum, vector<ll> &coins) {
  ll i, n = coins.size();
  if(sum == 0)
    return 1;
  else if(sum < 0)
    return 0;
  if(ways[sum] == -1) {
    ways[sum] = 0;
    for (i = 0; i < n; i++) {
      if (coins[i] <= sum) {
        ways[sum] = (ways[sum]%M +  numberOfWays(sum - coins[i], coins)%M)%M;
      }
    }
  }
  return ways[sum];
}
 
void solve () {
  ll i, n, sum;
  cin >> n >> sum;
  vector<ll> coins(n);
  for (i = 0; i < n; i++) {
    cin >> coins[i];
  }
  cout << numberOfWays(sum, coins);
}
 
//---------- Main() Below ----------
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  ll t = 1;
  // cin >> t;
  while(t--)
    solve();
  return 0;
}
