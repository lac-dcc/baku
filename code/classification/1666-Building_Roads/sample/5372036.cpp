#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);
 
using namespace std;
//int range 1e9
//ll range 1e18
//double > float
// 1sec -> 1e8
const int MOD = 1e9 + 7;
 
void Usaco(string s) { 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
 
bool vis[1000005];
vector<int> adj[1000005];
 
void dfs(int node){
 
      vis[node] = 1;
      for(auto it : adj[node]){
         if(!vis[it]) dfs(it);
      }
}
 
void solve(){
      int n, m;
      cin >> n >> m;
 
      
 
      for(int i=0; i < m; i++){
         int a, b;
         cin >> a >> b;
         a--; b--;
         adj[a].pb(b);
         adj[b].pb(a);
      }
 
      for(int i=0; i < n; i++) vis[i] = 0;
         vector<int>road;
 
         for(int i=0; i < n; i++){
            if(!vis[i]){
               road.pb(i+1);
               dfs(i);
            }
         }
         cout << road.size() -1 << endl;
         for(int i=1; i < road.size(); i++) cout << road[i-1] << " " << road[i] << endl;
 
 
 
}
 
 
 
 
signed main(){
   BOOST
   solve();
}
