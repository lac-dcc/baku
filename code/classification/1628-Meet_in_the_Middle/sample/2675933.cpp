#include "bits/stdc++.h"
 
using namespace std;
 
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  long long x;
  cin >> n >> x;
  long long v[n];
  for (auto& a : v) {
    cin >> a;
  }
  vector<long long> left, right;
  for (int i = 0; i < 1 << (n / 2); ++i) {
    long long sum = 0;
    for (int j = 0; j < n / 2; ++j) {
      if (i & (1 << j)) {
        sum += v[j];
      }
    }
    left.push_back(sum);
  }
  sort(left.begin(),  left.end());
  for (int i = 0; i < 1 << (n + 1) / 2; ++i) {
    long long sum = 0;
    for (int j = 0; j < (n + 1) / 2; ++j) {
      if (i & (1 << j)) {
        sum += v[j + n / 2];
      }
    }
    right.push_back(sum);
  }
  sort(right.begin(),  right.end());
  long long ans = 0;
  for (auto& val : left) {
    auto range = equal_range(right.begin(), right.end(), x - val);
    ans += (long long)(range.second - range.first);
  }
  cout << ans;
}
