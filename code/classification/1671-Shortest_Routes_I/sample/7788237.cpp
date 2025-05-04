#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(x) begin(x), end(x)
#define pb push_back
 
const int maxn = 100001;
vector<pii> adj[maxn];
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
 
    //djikstra algorithm
    vector<ll> dist(n+1, 1e18);
    vector<bool> done(n+1, false);
    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        int d = p.first, a = p.second;
        if(done[a]) continue;
        done[a] = true;
        for(auto r: adj[a]){
            int b = r.first, w = r.second;
            if(dist[a]+w < dist[b]){
                dist[b] = dist[a]+w;
                pq.push({dist[b], b});
            }
        }
    }
 
    for(int i=1; i<=n; i++) cout << dist[i] << ' ';
}
