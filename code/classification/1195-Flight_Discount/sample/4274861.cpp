#include<bits/stdc++.h>
 
using namespace std;
 
void dij(vector<vector<pair<int, int> > >&adj, vector<long long>&dist, int n, int s){
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > >pq;
    vector<int>visit(n + 1);
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        auto u = pq.top(); pq.pop();
        if (visit[u.second]) continue;
        visit[u.second] = 1;
        for (auto x : adj[u.second]){
            int w = x.second;
            int v = x.first;
            if (dist[v] > dist[u.second] + w){
                dist[v] = dist[u.second] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
 
    }
}
 
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > >adj(n + 1);
    vector<vector<pair<int, int> > >adjt(n + 1);
    vector<pair<pair<int, int>, int> >edge(m);
 
    for (int i = 0; i < m; i++){
        int s, e, c;
        cin >> s >> e >> c;
        adj[s].push_back(make_pair(e, c));
        adjt[e].push_back(make_pair(s, c));
        edge[i] = make_pair(make_pair(s, e), c);
    }
    vector<long long>dist1(n + 1, LLONG_MAX);
    vector<long long>distn(n + 1, LLONG_MAX);
    dist1[1] = 0;
    distn[n] = 0;
    dij(adj, dist1, n, 1);
    dij(adjt, distn, n, n);
    long long ans = dist1[n];
    for (auto e: edge){
        int u = e.first.first;
        int v = e.first.second;
        if (dist1[u] == LLONG_MAX || distn[v] == LLONG_MAX) continue;
        ans = min(ans, dist1[u] + e.second / 2 + distn[v]);
    }
    cout << ans;
 
}