#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;
const int inf = 1e18;
 
signed main() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n),adj_reverse(n);
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u-1].push_back({v-1,w});
        adj_reverse[v-1].push_back({u-1,w});
    }
    
    priority_queue<pair<int,int>>q;
    vector<int>d1(n,inf),dn(n,inf);
    q.push({0,0});
    d1[0] = 0;
    vector<bool>processed(n,false);
    while(!q.empty()) {
        int s = q.top().second;
        q.pop();
        if(processed[s]) continue;
        processed[s] = true;
        for(auto u:adj[s]) {
            if(d1[u.first] > d1[s] + u.second) {
                d1[u.first] = d1[s] + u.second;
                q.push({-d1[u.first],u.first});
            }
        }
    }
 
    for(int i=0;i<n;i++) {
        processed[i] = false;
    }
 
    q.push({0,n-1});
    dn[n-1] = 0;
    while(!q.empty()) {
        int s = q.top().second;
        q.pop();
        if(processed[s]) continue;
        processed[s] = true;
        for(auto u:adj_reverse[s]) {
            if(dn[u.first] > dn[s] + u.second) {
                dn[u.first] = dn[s] + u.second;
                q.push({-dn[u.first],u.first});
            }
        }
    }
 
    int ans = inf;
    for(int i=0;i<n;i++) {
        for(auto u:adj[i]) {
            ans = min(ans,d1[i]+dn[u.first]+u.second/2);
        }
    }
    cout<<ans;
 
    return 0;
}
