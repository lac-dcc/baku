/**
 * @created     : 19 Sep 2023
 * @handle      : @LuchoBazz
 */
 
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef ONLINE_JUDGE
// Reference: https://codeforces.com/blog/entry/96344
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#endif
 
#define endl '\n'
#define _ << ' ' <<
#define PB push_back
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ms(arr, value) memset(arr, value, sizeof(arr))
#define infinity while (1)
#define unreachable assert(false && "Unreachable");
 
#define overload4(a, b, c, d, e, ...) e
#define for1(a) for (int i = 0; i < int(a); ++i)
#define for2(i, a) for (int i = 0; i < int(a); ++i)
#define for3(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define for4(i, a, b, c) for (int i = int(a); i <= int(b); i += int(c))
#define rof1(a) for (int i = int(a) - 1; i >= 0; --i)
#define rof2(i, a) for (int i = int(a) - 1; i >= 0; --i)
#define rof3(i, a, b) for (int i = int(b); i >= int(a); --i)
#define rof4(i, a, b, c) for (int i = int(b); i >= int(a); i -= int(c))
#define forn(...) overload4(__VA_ARGS__, for4, for3, for2, for1)(__VA_ARGS__)
#define rof(...) overload4(__VA_ARGS__, rof4, rof3, rof2, rof1)(__VA_ARGS__)
 
const string ALPHA = "abcdefghijklmnopqrstuvwxyz";
const string YES = "YES";
const string NO = "NO";
 
const int d4x[4] = {0, -1, 1, 0};
const int d4y[4] = {-1, 0, 0, 1};
const int d8x[8] = {-1, 0, -1, 1, -1, 1, 0, 1};
const int d8y[8] = {-1, -1, 0, -1, 1, 0, 1, 1};
 
template <class T, class S> inline bool xmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S> inline bool xmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}
 
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto const &i : v)
    os << i << " ";
  os << "\n";
  return os;
}
 
template <typename T> istream &operator>>(istream &is, vector<T> &v) {
  for (int i = 0; i < (int)v.size(); ++i)
    is >> v[i];
  return is;
}
 
template <typename T, typename Sequence = vector<T>, typename Compare = less<T>>
using template_heap = priority_queue<T, Sequence, Compare>;
template <typename T> using max_heap = template_heap<T>;
template <typename T> using min_heap = template_heap<T, vector<T>, greater<T>>;
 
#define pop_heap(heap)                                                         \
  heap.top();                                                                  \
  heap.pop();
 
template <typename T> T get_min(set<T> &st) {
  assert(!st.empty());
  return *st.begin();
}
 
template <typename T> T get_max(set<T> &st) {
  assert(!st.empty());
  return *st.rbegin();
}
 
template <typename T> T erase_min(set<T> &st) {
  assert(!st.empty());
  T to_return = get_min(st);
  st.erase(st.begin());
  return to_return;
}
 
template <typename T> T erase_max(set<T> &st) {
  assert(!st.empty());
  T to_return = get_max(st);
  st.erase(--st.end());
  return to_return;
}
 
#define merge_set(big, small) big.insert(small.begin(), small.end());
#define has_key(it, key) (it.find(key) != it.end())
 
using int64 = long long;
using i16 = short;
using f64 = long double;
 
#ifdef DEBUG
#include "../debug.h"
#else
#define debug(...) 42
#endif
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  int n, m;
  cin >> n >> m;
  vector<int64> A(n), B(m);
 
  multiset<int64> ms;
  for (int64 &x : A) {
    cin >> x;
    ms.insert(x);
  }
  for (int64 &x : B)
    cin >> x;
 
  auto find_best = [&](int64 target) -> int64 {
    auto it = ms.lower_bound(target);
    if (it == ms.end()) {
      --it;
      return *it <= target ? *it : -1;
    } else if (it == ms.begin()) {
      return *it <= target ? *it : -1;
    }
    int64 high = *it;
    --it;
    int64 low = *it;
    if (high == target)
      return high;
    return low <= target ? low : -1;
  };
 
  vector<pair<int64, int>> sorted(m);
 
  forn(i, m) sorted[i] = {B[i], i};
 
  vector<int64> ans(m, -1);
 
  forn(i, m) {
    pair<int64, int> pr = sorted[i];
 
    if (ms.empty()) {
      continue;
    }
 
    int64 best = find_best(pr.first);
    if (best <= pr.first) {
      ans[pr.second] = best;
      if (has_key(ms, best))
        ms.erase(ms.find(best));
    }
  }
 
  forn(i, m) cout << ans[i] << endl;
 
  return 0;
}
