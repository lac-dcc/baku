#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 1e5;
ll dist[N + 1];
 
void bfs(const vector<pair<int, int>> graph[], const int& start, const int& n){
    memset(dist, 0x3f, sizeof(dist));
    dist[start] = 0;
 
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, start});
 
    while(!q.empty()){
        int u = q.top().second; ll c = q.top().first;
        q.pop();
 
        if(dist[u] != c) continue;
 
        for(auto t : graph[u]){
            int v = t.first;
            int k = t.second;
            if(dist[v] > dist[u] + k){
                dist[v] = c + k;
                q.push({dist[v], v});
            }
        }
    };
    // cerr << '\n';
    // cerr << n << '\n';
 
    // return dist[n];
};
 
int n, m;
vector<pair<int, int>> graph[N + 1];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
 
    for(int i = 1, x, y, c; i <= m; i++){
        cin >> x >> y >> c;
        graph[x].push_back({y, c});
    };
 
 
    bfs(graph, 1, n);
    
    for(int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
 
 
 
    return 0;
}