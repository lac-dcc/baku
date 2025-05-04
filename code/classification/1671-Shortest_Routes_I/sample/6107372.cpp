#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
 
int main(){
    ll n, m;cin>>n>>m;
    vector<pair<ll, ll>> adj[n+1];
    while(m--){
        ll a, b, c;cin>>a>>b>>c;
        adj[a].push_back({b, c});
        // adj[b].push_back({a, c});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    vector<ll> vis(n+1, 0);
    vector<ll> dist(n+1, 1e18);
    q.push({0, 1});
    dist[1]=0;
    while(!q.empty()){
        ll node = q.top().second;
        ll dis = q.top().first;
        q.pop();
        if(vis[node]==true){
            continue;
        }
        vis[node]=true;
        for(auto it:adj[node]){
            if(vis[it.first]==true){
                continue;
            }
            if(!vis[it.first] && (dis+it.second < dist[it.first])){
                dist[it.first] = (dis+it.second);
                q.push({dist[it.first], it.first});
            }
        }
    }
    for(ll i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}