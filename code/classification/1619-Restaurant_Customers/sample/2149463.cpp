#include<bits/stdc++.h>
using namespace std;
 
int n, a, b;
 
int main()
{
  cin >> n;
 
  vector<pair<int, int>> t;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    t.push_back({a,  1});
    t.push_back({b, -1});
  }
 
  sort(t.begin(), t.end());
 
  int sum = 0, ans = 0;
  for(auto [_, p]: t) {
    sum += p;
    ans = max(ans, sum);
  }
 
  cout << ans << endl;
 
  return 0;
}
