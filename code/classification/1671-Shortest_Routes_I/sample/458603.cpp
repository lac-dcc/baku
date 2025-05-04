#include<bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
 
vector<pair<long, long>> paths[200001];
ll dist[100001];
priority_queue<pair<long, long>> q;
bool processed[100001] = {false};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, m, a, b, w;
    cin >> n >> m;
 
    for (int i=0; i<m; i++) {
        cin >> a >> b >> w;
        paths[a].push_back({b, w});
    }
 
    for (int i=0; i<=n; i++) dist[i] = LLONG_MAX;
 
    q.push({0, 1});
    dist[1] = 0;
    while (!q.empty()) {
        ll x = q.top().second; q.pop();
        if (processed[x]) continue;
        processed[x] = true;
        for (auto path : paths[x]) {
            tie(b, w) = path;
            ll d = dist[x] + w ;
            if (d < dist[b]) {
                q.push({-d, b});
                dist[b] = d;
            }
        }
    }
 
    for (int i=1; i<=n; i++) cout << dist[i] << " ";
}
