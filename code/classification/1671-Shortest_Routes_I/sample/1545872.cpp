#include<bits/stdc++.h>
using namespace std;
 
struct Dijkstra {
    const long long INF = 1e18;
    typedef pair <long long, long long> II;
    vector<vector<II>> adj;
    vector<long long> d; // shortest dist
    int n; // number of vertices
 
    Dijkstra(int n): n(n) {
        adj.resize(n + 1);
        d.resize(n + 1);
    }
 
    void addEdge(int u, int v, long long c) {
        adj[u].push_back({v, c});
      //  adj[v].push_back({u, c});
    }
    
    void dijkstra(int a) {
        priority_queue < II, vector<II>, greater<II> > pq;
 
        for (int i = 1; i <= n; i++) {
            d[i] = INF;
        }
 
        d[a] = 0;
 
        pq.push(II(0, a));
        while (!pq.empty()) {
            long long du = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d[u] != du) continue;
            
            for (auto i: adj[u]){
                int v = i.first;
                long long uv = i.second;
 
                // this v is better
                if (d[v] > du + uv){
                    d[v] = du + uv;
                    pq.push(II(d[v],v)); // push the better one
                }
            }
        }
    }
 
};
 
 
int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
 
 
    Dijkstra dijkstra(n);
    for (int i = 1; i <= m; i++) {
    	int u , v ,c;
    	cin >> u >> v >> c;
    	dijkstra.addEdge(u,v,c);
    }
    dijkstra.dijkstra(1);
    for (int i = 1; i <= n; i++) {
    	cout << dijkstra.d[i] << ' ';
    }
    return 0;
}
 
