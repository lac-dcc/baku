/**
 *    Author : Tanbin_Hasan
 *    Created : 25.09.2021 15:50:50
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int TotalWay(vector<int> &coin, int tar) {
  // sort(coin.begin(), coin.end());
  vector<int> val(tar + 1);
  val[0] = 1;
  for (int i = 1; i < tar + 1; ++i) {
    for (auto &c : coin) {
      if (i - c < 0) continue;
      val[i] = (val[i] + val[i - c]) % 1000000007;
    }
  }
  return val[tar];
}
 
int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, target;
  cin >> n >> target;
  vector<int> coin(n);
  for (auto &i : coin) {
    cin >> i;
  }
  cout << TotalWay(coin, target);
  return 0;
}