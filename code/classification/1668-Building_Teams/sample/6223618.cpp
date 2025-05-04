#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
vector<bool> visited(1000006, false);
vector<bool> colored(1000006, false);
unordered_map<ll, vector<ll>> graph;
bool bad = false;
vector<bool> color(1000006);
void dfs(ll x, bool col = false){
   color[x] = col;
   visited[x] = true;
   for(auto u : graph[x]){
      if(visited[u]){
         if(color[u] == col) bad = true;
      }else  dfs(u, !col);
   }
}
 
int main(){
   ll n, m;
   cin >> n >> m;
   
   for(ll i = 0; i<m; i++){
      ll x,y;
      cin >> x >> y;
      graph[x].push_back(y);
      graph[y].push_back(x);
   }
 
   for(ll i = 1; !bad && i<=n;i++){
      if(!visited[i]) dfs(i);
   }
   if(bad){
      cout << "IMPOSSIBLE\n";
      return 0;
   }
   for(ll i = 1; i<=n;i++){
      if(color[i]) cout << "1 ";
      else cout << "2 ";
   }
   cout << '\n';
 
}     
