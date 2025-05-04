#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree <ll,null_type,greater_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> oset; //ordered_set
#define pb push_back
ll fastExpo(ll base, ll expo, ll mod){
    ll ans = 1;
    while(expo > 0){
        if(expo%2){
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        expo /= 2;
    }
    return ans;
}
ll fact(ll n){
    ll ans = 1;
    for(int i=1;i<=n;i++){
        ans = (ans*1ll*i);
    }
    return ans;
}
 
ll fact_mod(ll n,ll mod){
    ll ans = 1;
    for(int i=1;i<=n;i++){
        ans = (ans*1ll*i)%mod;
    }
    return ans;
}
 
 
vector<ll> topoSort(ll N,vector<vector<ll>>adj){
    queue<ll>q;
    vector<ll>indeg(N+1,0);
    for(int i=1;i<=N;i++){
        for(auto it:adj[i]){
            indeg[it]++;
        }
    }
 
    for(int i=1;i<=N;i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    vector<ll>topo;
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        topo.pb(node);
        for(auto it:adj[node]){
            indeg[it]--;
            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }
    return topo;
}
 
void dfs(ll node, ll par,vector<vector<ll>>&adj,vector<ll>&depth){
    for(auto it:adj[node]){
        if(it == par) continue;
        depth[it] = depth[node]+1;
        dfs(it,node,adj,depth);
    }
}
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    ll n,u,v;
    cin >> n;
    vector<vector<ll>>adj(n+1);
    vector<ll>depth(n+1,0);
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0,adj,depth);
    ll mx_depth = -1;
    ll mx_node = -1;
    for(ll i=1;i<=n;i++){
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
            mx_node = i;
        }
        depth[i] = 0;
    }
    dfs(mx_node,0,adj,depth);
    cout << *max_element(depth.begin(),depth.end()) << endl;
 
 
    return 0;
}
