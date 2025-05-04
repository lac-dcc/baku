#include<bits/stdc++.h>
using namespace std;
 
 
#define ll long long
#define pb push_back
#define ff first
#define ss second
 
vector<vector<pair<ll,ll>>> adj;
vector<vector<pair<ll,ll>>> rev;
vector<ll> d1;
vector<ll> dn;
ll n,m;
 
int main(){
 
    cin>>n>>m;
    adj.resize(n);
    rev.resize(n);
    d1.resize(n,1e16);
    dn.resize(n,1e16);
 
    vector<pair<pair<ll,ll>,ll>> edges;
 
    for(ll i=0;i<m;i++){
        ll u,v,w; cin>>u>>v>>w;
        adj[u-1].pb({v-1,w});
        rev[v-1].pb({u-1,w});
        edges.pb({{u-1,v-1},w});
    }
    
    ll ans = 1e18;
    
    set<pair<ll,ll>> s;
    vector<bool> vis(n);
    s.insert({0,0});
    d1[0]=0;
 
    while(!s.empty()){
        ll u = s.begin()->ss;
        s.erase(s.begin());
 
        if(vis[u]) continue;
        vis[u] = true;
 
        for(auto p:adj[u]){
            ll v=p.ff;
            ll d=p.ss;
 
            if(d1[v]>d1[u]+d){
                d1[v] = d1[u]+d;
                s.insert({d1[v],v});
            }
        }
    }
    vector<bool> vis2(n);
    s.insert({0,n-1});
    dn[n-1]=0;
 
    while(!s.empty()){
        ll u = s.begin()->ss;
        s.erase(s.begin());
 
        if(vis2[u]) continue;
        vis2[u] = true;
 
        for(auto p:rev[u]){
            ll v=p.ff;
            ll d=p.ss;
 
            if(dn[v]>dn[u]+d){
                dn[v] = dn[u]+d;
                s.insert({dn[v],v});
            }
        }
    }
 
    for(ll i=0;i<m;i++){
        ll u = edges[i].ff.ff;
        ll v = edges[i].ff.ss;
        ll w = edges[i].ss;
        ans = min(ans,d1[u]+w/2+dn[v]);
    }
 
    cout<<ans;
 
    return 0;
}
