#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
using namespace std;
 
typedef long long ll;
const ll INF = 1e18;
 
struct Edge{
  int u, v;
  ll cost;
};
 
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  vector <Edge> e;
  vector <ll> d(n, 0);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v;
    u--; v--;
    ll cost; cin >> cost;
    e.push_back({u, v, cost});
  }
  vector <int> p(n, -1);
  int found=-1;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int u = e[j].u, v = e[j].v;
      if(d[u] < INF && d[u]+e[j].cost<d[v]){
        d[v] = d[u]+e[j].cost;
        p[v] = u;
        if(i == n-1){
          found=v;
        }
      }
    }
  }
  if(found == -1){
    cout << "NO\n";
    return 0;
  }
  vector <bool> seen(n, false);
  int u;
  for(u = found; !seen[u]; u=p[u]){
    seen[u]=1;
  }
  cout << "YES\n";
  vector <int> ans = {u};
  for(int v = p[u]; v != u; v=p[v]){
    ans.push_back(v);
  }
  ans.push_back(u);
  for(int i=ans.size()-1; i>=0; i--){
    cout << ans[i]+1 << ' ';
  } cout << '\n';
  return 0;
}
