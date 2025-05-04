#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long n, m, temp;
  cin >> n >> m;
  multiset<long> tPrice;
 
  while (n--) {
    cin >> temp;
    tPrice.insert(temp);
  }
 
  while (m--) {
    cin >> temp;
    auto it = tPrice.upper_bound(temp);
    if (it == tPrice.begin()) {
      cout << "-1\n";
      continue;
    }
    cout << *(--it) << "\n";
    tPrice.erase(it);
  }
}
