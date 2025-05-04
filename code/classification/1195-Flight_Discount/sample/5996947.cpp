#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
// #define cin fin
// #define cout fout
 
string file = "date";
ifstream fin(file + ".in");
ofstream fout(file + ".out");
const int mxN = 1e5;
int n, m;

void dijkstra(int src, vector<ll> &dist, vector<ar<ll, 2>> (&adj)[mxN])
{
     vector<bool> vis(n, 0);
     priority_queue<ar<ll, 2>> pq;
     pq.push({0, src});
     dist[src] = 0;
     while (!pq.empty())
     {
          int a = pq.top()[1];
          ll b = -1 * pq.top()[0];
          pq.pop();
          if (vis[a] || dist[a] < b)
               continue;
          vis[a] = true;
          for (auto u : adj[a])
          {
               if (dist[u[0]] > dist[a] + u[1])
               {
                    dist[u[0]] = dist[a] + u[1];
                    pq.push({-dist[u[0]], u[0]});
               }
          }
     }
}
 
int main()
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     // int n, m;
 
     cin >> n >> m;
     vector<ar<ll, 2>> adj[mxN];
     vector<ar<ll, 2>> iadj[mxN];
     vector<ar<ll, 3>> edges;
     for (int i = 0; i < m; ++i)
     {
          int a, b, g;
          cin >> a >> b >> g, a--, b--;
          adj[a].push_back({b, g});
          iadj[b].push_back({a, g});
          edges.push_back({a, b, g});
     }
 
     //ll dist[n];
     //memset(dist, 0x3f, sizeof(dist));
     vector<ll> dist(n, 0x3f);
     dist[0] = 0;
     dijkstra(0, dist, adj);
 
     //ll idist[n];
     //memset(idist, 0x3f, sizeof(idist));
     vector<ll> idist(n - 1, 0x3f);
     idist[n - 1] = 0;
     dijkstra(n - 1, idist, iadj);
     ll ans = LLONG_MAX;
 
     for (auto u : edges)
     {
          ans = min(ans, 1LL * dist[u[0]] + u[2] / 2 + idist[u[1]]);
     }
     cout << ans;
     return 0;
}
