#include <bits/stdc++.h>
 
#define SZ(container) container.size()
#define REP(i, n) for (auto i = 0; i < n; ++i)
#define RANGE(i, a, b) for (auto i = a; i <= b; ++i)
#define FOR(e, container) for (auto e : container)
#define ITE(e, container) for (auto e = nums.begin(); e != nums.end(); ++e)
#define ALL(container) container.begin(), container.end()
#define MP(a, b) make_pair(a, b)
 
using namespace std;
 
void SetIO()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
}
 
int main(int argc, char const *argv[])
{
 
  SetIO();
 
  int n,x;
  cin >> n >> x;
  vector<pair<int, int>> a;
  REP(i, n) {
    int x1;
    cin >> x1;
    a.emplace_back(x1, i+1);
  }
  sort(ALL(a));
  int i=0, j=n-1;
  while (i < j) {
    int y=a[i].first + a[j].first;
    if (y>x) --j;
    else if (y<x) ++i;
    else {
      vector<int> ans {a[i].second, a[j].second};
      sort(ALL(ans));
      cout << ans[0] << " " << ans[1] << "\n";
      break;
    }
  }
  if (i>=j) cout << "IMPOSSIBLE\n";
}
