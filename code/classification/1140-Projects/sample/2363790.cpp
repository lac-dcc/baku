#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = size_t;
 
using ll = long long;
template <typename T>
using Vec = std::vector<T>;
 
template <typename T>
using o_set = std::set<T>;
 
template <typename T>
using u_set = std::unordered_set<T>;
 
template <typename K, typename V>
using u_map = std::unordered_map<K, V>;
 
template <typename K, typename V>
using o_map = std::map<K, V>;
 
using namespace std;
 
int main()
{
 
  i64 n, tmp;
  cin >> n;
  i64 a, b, c;
  o_map<pair<i64, i64>, i64> costs;
  auto &dp = costs;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b >> c;
    auto &c_ref = costs[{a, b}];
    c_ref = max(c_ref, c);
  }
  vector<pair<i64, i64>> schedule;
  schedule.reserve(costs.size());
  vector<i64> table;
  table.reserve(costs.size());
  for (auto &x : costs)
  {
    schedule.push_back(x.first);
    table.push_back(x.second);
  }
  int sz = table.size();
  table.back() = costs.rbegin()->second;
  for (int i = sz - 2; i >= 0; i--)
  {
    auto &elem = schedule[i];
    auto &cst = table[i];
    // auto [elem, cst] = *it;
    auto ub = lower_bound(schedule.begin() + i, schedule.end(),
                          make_pair(elem.second + 1, elem.second + 1));
    auto ind = distance(schedule.begin(), ub);
    // auto ub = dp.lower_bound({elem.second + 1, elem.second + 1});
    if (ub != schedule.end())
    {
      cst = max(table[ind] + cst, table[i + 1]);
    }
    else
    {
      cst = max(cst, table[i + 1]);
    }
  }
  i64 max_ = 0;
  for (auto x : table)
  {
    max_ = max(max_, x);
  }
  cout << max_ << '\n';
}