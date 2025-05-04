#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int n, x;
  cin >> n >> x;
 
  vector<int> a, b;
  for(int i = 0; i < n / 2; i++) {
    int c;
    cin >> c;
    a.push_back(c);
  }
 
  for(int i = n / 2; i < n; i++) {
    int c;
    cin >> c;
    b.push_back(c);
  }
 
  // unordered_map<int, int> freq;
  vector<int> half;
 
  n = a.size();
 
  for(int mask = 0; mask < (1 << n); mask++) {
    int s = 0;
    for(int i = 0; i < n; i++) {
      if(mask & (1 << i)) {
        s += a[i];
      }
    }
    half.push_back(s);
  }
 
  sort(half.begin(), half.end());
  vector<int> continuous((1 << n), 1);
  for(int i = 1; i < (1 << n); i++) {
    if(half[i] == half[i - 1]) {
      continuous[i] = continuous[i - 1] + 1;
    }
  }  
 
  int ans = 0;
  n = b.size();
 
  for(int mask = 0; mask < (1 << n); mask++) {
    int s = 0;
    for(int i = 0; i < n; i++) {
      if(mask & (1 << i)) {
        s += b[i];
      }
    }
    int in = upper_bound(half.begin(), half.end(), x - s) - half.begin() - 1;
    if(in >= 0 && in < (int)half.size() && half[in] == x - s) {
      ans += continuous[in];
    }
  }
 
  cout << ans << '\n';
}
