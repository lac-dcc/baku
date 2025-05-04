#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
typedef pair<ll,ll> pi;
#define f first
#define s second
 
int mod = 1e9 + 7;
ll inf = 1e15 + 7;
ll n,m,q;
 
void dijkstra(int s, vector<vector<pi>>&g, vector<ll>&dist){
  dist[s] = 0;
  set<pi>q;
  q.insert({0,s});
 
  while(!q.empty()){
    pi t = *(q.begin());
    q.erase(q.begin());
    ll v = t.s;
 
    for(pi& edge:g[v]){
      ll to = edge.f;
      ll wt = edge.s;
 
      if(dist[to] > dist[v] + wt){
        q.erase({dist[to], to});
        dist[to] = dist[v] + wt;
        q.insert({dist[to], to});
      }
    }
  }
}
 
 
int main() {
  ll u,v,w;
  cin>>n>>m;
 
  vector<vector<pi>>h(100003),g(100003);
 
  for(int i=0;i<m;++i){
    cin>>u>>v>>w;
    g[u].push_back({v,w});
    h[v].push_back({u,w});
  }
 
  vector<ll>df(n+1,inf), db(n+1, inf);
 
  dijkstra(1,g,df);
  dijkstra(n,h,db);
 
  ll ans = inf;
  for(int i=1;i<=n;++i){
    for(pi &j:g[i]){
      ans = min(ans, df[i]+db[j.f]+j.s/2);
    }
  }
  cout<<ans;
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";  
}
