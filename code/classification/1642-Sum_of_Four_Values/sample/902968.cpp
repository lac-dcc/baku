#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  int n, t;
  cin >> n >> t;
  
  vector<pair<int, int>> a(n);
  
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  for (int j = 0; j < n; j++) {
    int t1 = t - a[j].first;
    for (int i = j+1; i < n; i++) {
      int t2 = t1 - a[i].first;
      int s = i+1, e = n-1;
      while (s < e) {
        if (a[s].first + a[e].first < t2) {
          s++;
        } else if (a[s].first + a[e].first == t2) {
          cout << a[j].second+1 << ' ' << a[i].second+1 << ' ' << a[s].second+1 << ' ' << a[e].second+1 << '\n';
          return 0;
        } else {
          e--;
        }
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}