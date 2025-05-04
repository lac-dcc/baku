#include <bits/stdc++.h>
#define lop(i,a,b) for(ll i = a; i < b; i++)
#define alop(i,v) for(auto &i: v)
#define in(v) for(auto &i: v) cin >> i;
#define ll long long
//#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mem(dp, x) memset(dp, x, sizeof(dp))
using namespace std;
const ll mod = 1e9 + 7;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define orderedset tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
 
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    while(m--){
        ll a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    vector<ll> dist(n + 1, 9e18);
    priority_queue<pair<ll, ll>> pq;
    dist[1] = 0; pq.push({0, 1});
    while(!pq.empty()){
        ll cost = -pq.top().first, node = pq.top().second;
        pq.pop();
        if(cost > dist[node]) continue;
        alop(child, adj[node]){
            if(cost + child.second < dist[child.first]){
                dist[child.first] = cost + child.second;
                pq.push({-dist[child.first], child.first});
            }
        }
    }
    lop(i, 0, n) cout << dist[i + 1] << ' ';
 
    return 0;
}