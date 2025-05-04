#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
#define f first
#define s second
#define FAST ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
#define rep(x , st , ed) for(int x = st ; x < ed ; x++)
const ll N = 1e5 + 9, M = 100 , mod = 1e9 + 7 , OO = 2 * 1e9 , OOLL = 1 * 1e18;
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif
//\//\//\//\//\//\//\//\//\//\//\//\//\//\//\//
int n , m;
vector<int> adj[N];
vector<int> c(N , -1);
bool Fail = false;
void dfs(int u , int color){
  c[u] = color;
  for(auto &v : adj[u]){
    if(c[v] == -1) dfs(v , 1 - color);
    else{
      if(color == c[v]) Fail = true;
    }
  }
}
void sol(){
  cin >> n >> m;
  rep(i , 0 , m){
    int u , v; cin >> u >> v;
    --u; --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  rep(i , 0 , n) 
    if(!~c[i]) dfs(i , 0);
  if(Fail) cout << "IMPOSSIBLE";
  else{
    rep(i , 0 , n) cout << c[i] + 1 << " ";
  }
}
int main(){
    FAST;
    #ifndef ONLINE_JUDGE
      judge();
    #endif
    int q = 1;
    // cin >> q;
    while (q--){  
        sol();
     //   cout << '\n';
    }
    #ifndef ONLINE_JUDGE
      end_clock();
    #endif
}