#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int coins[100], dp[1000001], n, x;
bool visited[1000001];
 
int min_val(int v) {
  if (v<0) return INF;
  else if (v==0) return 0;
  else {
    int val=INF;
    if (!visited[v]) {
      for (int i=0; i<n; i++) val = min(val, min_val(v-coins[i])+1);
      dp[v] = val;
    }
    visited[v] = true;
    return dp[v];
  }
}
 
int main(){
  cin >> n >> x;
  for (int i=0; i<=x; i++) dp[i] = INF;
  for (int i=0; i<n; i++) cin >> coins[i];
  int rst=min_val(x);
  if (rst==INF) cout << "-1";
  else cout << rst;
}
