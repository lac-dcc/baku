#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <string>
#include <utility>
#include <cassert>
 
using namespace std;
typedef long long ll;
 
const int MAXN = 2e5+10;
int a[MAXN], b[MAXN];
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  int res = 0;
  int i = 0, j = 0;
  while (j < m) {
    while (i < n && a[i] + k < b[j]) i++;
    if (i == n) break;
    if (a[i] - k <= b[j] && b[j] <= a[i] + k) {
      res++;
      i++;
    }
    j++;
  }
  cout << res << endl;
  return 0; 
}