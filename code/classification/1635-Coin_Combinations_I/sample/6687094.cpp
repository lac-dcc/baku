#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
 
using namespace std;
constexpr char nl = '\n';
const int N = 2e6 + 5;
const int MOD = 1e9 + 7;
 
long long dp[N];
 
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for(auto &i : v) {
    cin >> i;
    dp[i] = 1;
  }
 
  for(int i = 1; i <= x; ++i) {
    for(int j = (int)v.size()-1; j >= 0; --j) {
      if(i-v[j] > 0) {
        dp[i] += dp[i-v[j]];
        dp[i] %= MOD;
      }
    }
  }
 
  cout << dp[x] << nl;
 
  return 0;
}
