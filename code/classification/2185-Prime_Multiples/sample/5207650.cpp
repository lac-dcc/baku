#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
 
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
 
using safe_set = std::unordered_set<ll, custom_hash>;
 
template <typename T> using safe_map = std::unordered_map<ll, T>;
 
template <typename T> T read() {
  T t;
  std::cin >> t;
  return t;
}
 
template <typename T> std::vector<T> read_vec(int n) {
  std::vector<T> vec(n);
  for (auto &ele : vec)
    std::cin >> ele;
  return vec;
}
 
template <typename T> auto read_matrix(int m, int n) {
  std::vector<std::vector<T>> vec(m, std::vector<T>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> vec[i][j];
    }
  }
  return vec;
}
 
auto solve(ll n, std::vector<ll> const &primes) {
  auto const sz = primes.size();
  ll sum = 0;
  for (ll i = 1; i < (1 << sz); ++i) {
    std::bitset<32> bs(i);
    ll res = n;
    for (ll j = 0; j < sz; ++j) {
      if (bs[j]) {
        res = res / primes[j];
      }
    }
    if (bs.count() % 2) {
      sum += res;
    } else {
      sum -= res;
    }
  }
  std::cout << sum << std::endl;
}
 
int main() {
  auto const n = read<ll>();
  auto const k = read<ll>();
  auto const nums = read_vec<ll>(k);
  solve(n, nums);
}