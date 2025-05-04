#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int n;
vector<ll> l, r;
ll ans, x;
int main() {
  cin >> n >> x;
  ll arr[n];
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  int llen = (n + 1) >> 1;
  int rlen = n - llen;
  ll* right = &arr[llen];
  for (int i=0;i<(1 << llen);i++) {
    ll sum = 0;
    for (int j=0;j<llen;j++) {
      if (i & (1 << j)) {
        sum += arr[j];
      }
    }
    l.push_back(sum);
  }
  for (int i=0;i<(1<<rlen);i++) {
    ll sum=0;
    for (int j=0;j<rlen;j++) {
      if (i & (1 << j)) {
        sum += right[j];
      }
    }
    r.push_back(sum);
  }
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  for (ll i : l) {
    int lb = lower_bound(r.begin(), r.end(), x - i) - r.begin();
    int ub = upper_bound(r.begin(), r.end(), x- i) - r.begin();
    ans += ub - lb;
  }
  cout << ans << endl;
  return 0;
}
