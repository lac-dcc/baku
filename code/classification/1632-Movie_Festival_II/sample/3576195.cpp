// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;
 
// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
struct Interval
{
  int left;
  int right;
};
 
void solve()
{
  int n, k;
  cin >> n >> k;
 
  vector<Interval> intervals;
  for (int i = 0; i < n; i++)
  {
    int left, right;
    cin >> left >> right;
    intervals.push_back({left, right});
  }
 
  auto cmp = [](Interval &interval1, Interval &interval2)
  {
    return interval1.right < interval2.right;
  };
 
  sort(intervals.begin(), intervals.end(), cmp);
 
  multiset<int> ms;
  for (int i = 0; i < k; i++)
  {
    ms.insert(0);
  }
 
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    auto interval = intervals[i];
    auto it = ms.upper_bound(interval.left);
    if(it == ms.begin()){
      continue;
    }
 
    ms.erase(prev(it));
    ms.insert(interval.right);
    ans++;
  }
 
  cout << ans;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  solve();
}
