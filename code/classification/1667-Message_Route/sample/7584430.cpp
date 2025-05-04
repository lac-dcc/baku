/*
I want to see what happens
if I don't give
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
using i64 = long long;
const int maxn = 1e5 + 5;
vector<int> a[maxn];
vector<int> ans;
int n, m;
void dijktra(int s) {
  vector<int> d(n + 5, 1e9);
  vector<int> pre(n + 5, -1);
  priority_queue<pair<int, int> , vector<pair<int,int>>, greater<pair<int,int>>> q;
  d[s] = 0;
  q.push({s, d[s]});
  while(!q.empty()) {
    auto [u, du] = q.top();
    q.pop();
    if(du > d[u]) continue;
    for(auto x : a[u]) {
      if(d[x] > du + 1) {
        d[x] = du + 1;
        pre[x] = u;
        q.push({x, d[x]});
      }
    }
  }
  if(d[n] == 1e9) {
    cout << "IMPOSSIBLE";
  }
  else {
    while(n != 1) {
      ans.push_back(n);
      n = pre[n];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto x : ans) {
      cout << x << ' ';
    }
  }
}
void solve() {
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  dijktra(1);
}
int main() {
  ios :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) {
    solve();
  }
 
   return 0;
}
