#include <bits/stdc++.h>
 
using namespace std;
 
long long x;
vector<int> v;
vector<long long> sa, sb;
long long sum = 0;
void subset_sum(int i, vector<long long> &s, int n) {
  if(i == n) {
    s.push_back(sum);
    return;
  }
  sum += v[i];
  subset_sum(i + 1, s, n);
  sum -= v[i];
  subset_sum(i + 1, s, n);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, X;
  cin >> n >> X;
  v.resize(n);
  for(auto& i : v) cin >> i;
  subset_sum(0, sa, n / 2);
  subset_sum(n / 2, sb, n);
  sort(sa.begin(), sa.end());
  sort(sb.begin(), sb.end());
 
  long long ans = 0;
 
  for(int i = 0; i < (int)sa.size(); i++) {
    auto p = equal_range(sb.begin(), sb.end(), X-sa[i]);
    ans += p.second-p.first;
  }
  cout << ans << "\n";
  return 0;
}
