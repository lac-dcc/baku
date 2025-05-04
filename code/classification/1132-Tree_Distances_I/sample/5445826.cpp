#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
 
int n;
vector<pair<int, int>> dp1, dp2;
vector<vector<int>> G;
 
void push(int v, pair<int, int> VP){
  if(dp1[v] > VP)
    dp2[v] = max(dp2[v], VP);
  else if(dp1[v] != VP)
    dp2[v] = dp1[v], dp1[v] = VP;
  if(dp2[v].second == dp1[v].second)
    dp2[v] = {0, 0};
}
 
void dfs1(int v, int p){
  for(int x : G[v]){
    if(x == p) continue;
    dfs1(x, v);
    push(v, {dp1[x].first+1, x});
    push(v, {dp2[x].first+1, x});
  }
}
 
void dfs2(int v, int p){
  for(int x : G[v]){
    if(x == p) continue;
    if(dp1[v].second != x)
      push(x, {dp1[v].first+1, v});
    if(dp2[v].second != x)
      push(x, {dp2[v].first+1, v});
    dfs2(x, v);
  }
}
 
int main(){
  fastio;
  cin >> n;
  
  G = vector<vector<int>>(n+1);
  dp1 = dp2 = vector<pair<int, int>>(n+1);
  
  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
 
  dfs1(1, 0);
  /*
  for(int i = 1; i <= n; i++)
    cout << dp1[i].first << "," << dp1[i].second << " ";
  cout << "\n";
  for(int i = 1; i <= n; i++)
    cout << dp2[i].first << "," << dp2[i].second << " ";
  cout << "\n";
  cout << "\n";*/
  dfs2(1, 0);
 
  for(int i = 1; i <= n; i++)
    cout << dp1[i].first << " ";
  cout << "\n";
}
