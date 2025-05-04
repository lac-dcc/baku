#include <bits/stdc++.h>
 
using ll = long long;
using namespace std;
 
ll nums[20];
ll N, K;
ll cnt = 0;
 
void dfs(ll num, int index, int primes) {
  for (int i = index; i < K; i++) {
    cnt += ((primes % 2) * 2 - 1) * (num / nums[i]);
    dfs(num / nums[i], i + 1, primes + 1);
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  for (int i = 0; i < K; i++) cin >> nums[i];
  dfs(N, 0, 1);
  cout << cnt << "\n";
}