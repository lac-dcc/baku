#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
 
const int inf = 1e17;
const int ninf = -1e17;
vector<vector<pii>> graph;
vector<vector<pii>> rev_graph;
vector<tuple<int, int, int>> edges;
vector<int> dis1, disn;
vector<bool> vis;
 
int32_t main()
{
    int n, m; cin >> n >> m;
    graph.assign(n + 1, vector<pii>());
    rev_graph.assign(n + 1, vector<pii>());
    dis1.assign(n + 1, inf);
    disn.assign(n + 1, inf);
    vis.assign(n + 1, false);
    for(int i = 0; i < m; i++)
    {
        int a, b, w; cin >> a >> b >> w;
        graph[a].push_back({b, w});
        rev_graph[b].push_back({a, w});
        edges.push_back({a, b, w});
    }
    dis1[1] = 0; disn[n] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    while(!pq.empty())
    {
        pii e = pq.top(); pq.pop();
        int a = e.second;
        if(vis[a]) continue;
        vis[a] = true;
        for(auto x : graph[a])
        {
            int u = x.first, v = x.second;
            if(dis1[u] > dis1[a] + v)
            {
                dis1[u] = dis1[a] + v;
                pq.push({dis1[u], u});
            }
        }
    }
    //for(int x : dis1) cout << x << " "; cout << endl;
    
    vis.assign(n + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq1;
    pq1.push({0, n});
    while(!pq1.empty())
    {
        pii e = pq1.top(); pq1.pop();
        int a = e.second;
        if(vis[a]) continue;
        vis[a] = true;
        for(auto x : rev_graph[a])
        {
            int u = x.first, v = x.second;
            if(disn[u] > disn[a] + v)
            {
                disn[u] = disn[a] + v;
                pq1.push({disn[u], u});
            }
        }
    }
    //for(int x : disn) cout << x << " "; cout << endl;
    
    int ans = inf;
    for(auto e : edges)
    {
        int a, b, w;
        tie(a, b, w) = e;
        ans = min(ans, dis1[a] + w / 2 + disn[b]);
    }
    cout << ans;
    cout << "\n";
    return 0;
}
