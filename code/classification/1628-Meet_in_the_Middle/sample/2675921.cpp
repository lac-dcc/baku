#include "bits/stdc++.h"
 
using namespace std;
 
struct custom_hash {
  static uint64_t split_mix_64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t r = std::chrono::steady_clock::now().time_since_epoch().count();
    return split_mix_64(x + r);
  }
};
 
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
