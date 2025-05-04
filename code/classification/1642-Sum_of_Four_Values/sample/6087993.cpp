// https://cses.fi/problemset/task/1642
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, x;
  cin>>n>>x;
 
  vector<int> a(n+1);
  for (int i=1; i<=n; ++i) cin>>a[i];
 
  map<int,pair<int,int>> mp;
  for (int i=1; i<=n; ++i) {
    for (int j=i+1; j<=n; ++j) {
      int cur = x - a[i] - a[j];
      if (mp[cur].first) {
        cout<<i<<" "<<j<<" "<<mp[cur].first<<" "<<mp[cur].second;
        return 0;
      }
    }
    for (int j=1; j<i; ++j) mp[a[i] + a[j]] = {i, j};
  }
 
  cout<<"IMPOSSIBLE";
}