#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
 
 
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, x;
  cin >> n >> m;
  multiset<int, greater<int>> h;
  while (n--) {
    cin >> x;
    h.insert(x);
  }
  while (m--) {
    cin >> x;
    auto it = h.lower_bound(x);
    if (it == h.end()) cout << -1 << '\n';
    else {
      cout << *it << '\n';
      h.erase(it);
    }
  }
  return 0;
}
