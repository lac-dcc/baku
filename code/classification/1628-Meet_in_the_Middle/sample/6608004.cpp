#include <bits/stdc++.h>
 
using namespace std;
 
int n, x, a[45];
long long ans;
 
vector<int> v;
 
void dfs1(int l, int r, int sum){
  if(l == r + 1){
    v.push_back(sum);
    return;
  }
  dfs1(l + 1, r, sum);
  if(sum + a[l] <= x){
    dfs1(l + 1, r, sum + a[l]);
  }
}
 
void dfs2(int l, int r, int sum){
  if(l == r + 1){
    auto p = equal_range(v.begin(), v.end(), x - sum);
    ans += p.second - p.first;
    return;
  }
  dfs2(l + 1, r, sum);
  if(sum + a[l] <= x){
    dfs2(l + 1, r, sum + a[l]);
  }
}
 
int main(){
  cin >> n >> x;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  int mid = (1 + n) / 2;
  dfs1(1, mid, 0);
  sort(v.begin(), v.end());
  dfs2(mid + 1, n, 0);
  cout << ans;
  return 0;
}
