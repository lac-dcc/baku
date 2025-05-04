#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long
const int INF = 1e16;
 
vector<vector<pair<int, int>>> adjOrig;
vector<vector<pair<int, int>>> adjInv;
vector<tuple<int, int, int>> edges;
 
void dijkstra(
    vector<vector<pair<int, int>>>& adj,
    vector<int>& dis, 
    int source
) {
 
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;
 
    dis[source] = 0;
    pq.push({0, source});
 
    while(!pq.empty()) {
 
        auto [cur_dis, cur_v] = pq.top();
        pq.pop();
        
        if(dis[cur_v] < cur_dis) continue;
        
        for(auto [x, w]: adj[cur_v]) {
            if(dis[x] > dis[cur_v] + w) {
                dis[x] = dis[cur_v] + w;
                pq.push({dis[x], x});
            }
        }
    }
}
 
int32_t main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("io/input.txt", "r", stdin);
        freopen("io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif
 
    // Code goes here
    int n, m;
    cin >> n >> m;
    adjOrig.assign(n+1, vector<pair<int, int>>());
    adjInv.assign(n+1, vector<pair<int, int>>());
 
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adjOrig[a].push_back({b, c});
        adjInv[b].push_back({a, c});
        edges.push_back({a, b, c});
    }
 
    vector<int> dis1(n+1, INF), disn(n+1, INF);
    dijkstra(adjOrig, dis1, 1);
    dijkstra(adjInv, disn, n);
 
    int ans = INF;
    for(auto [a, b, w]: edges) {
        ans = min(ans, dis1[a] + w/2 + disn[b]);
    }
    cout << ans << "\n";
 
    #ifdef LOCAL
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\n\nTime: " << double(duration.count())/1000 << " ms\n";
    #endif
    return 0;
}
