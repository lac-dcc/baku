#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = (int) 1e9 + 7;
 
vector <pair <int, int>> get(vector <int> a)
{
  vector <int> ans;
  int n = (int) a.size();
  for (int m = 0; m < (1 << n); m++)
  {
    int c = 0;
    bool ok = 1;
    for (int i = 0; (1 << i) <= m; i++)
      if (m & (1 << i))
      {
        c += a[i];
        if (c >= INF)
        {
          ok = 0;
          break;
        }
      }
    if (ok)
      ans.push_back(c);
  }
  sort(ans.begin(), ans.end());
  vector <pair <int, int>> buga;
 
  if (ans.empty()) return buga;
  buga.push_back({ans[0], 1});
  for (int i = 1; i < (int) ans.size(); i++)
  {
    int x = ans[i];
    if (x == buga.back().first)
      buga.back().second++;
    else
      buga.push_back({x, 1});
  }
  return buga;
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
 
  int n;
  int want;
  cin >> n >> want;
  vector <vector <int>> a(2);
 
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a[i % 2].push_back(x);
  }
 
  vector <vector <pair <int, int>>> b(2);
  b[0] = get(a[0]);
  b[1] = get(a[1]);
 
  int p1 = (int) b[1].size() - 1;
  long long ans = 0;
 
  for (auto &it : b[0])
  {
    int x = it.first;
    while (p1 >= 0 && b[1][p1].first + x > want)
      p1--;
    if (p1 >= 0 && b[1][p1].first + x == want)
    {
      long long a = b[1][p1].second;
      long long b = it.second;
      ans += a * b;
    }
  }
  cout << ans << "\n";
  return 0;
}
