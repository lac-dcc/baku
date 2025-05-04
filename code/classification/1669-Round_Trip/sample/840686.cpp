#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
 
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pll pair<long long int, long long int>
#define vli vector<long long int>
#define print(ar) for(auto e:ar)cout<<e<<' '; cout<<endl;
#define mod %modconst
const int modconst = 1e9 + 7;
const int PINF = INT_MAX;
const int NINF = INT_MIN;
 
bool dfs(int src, int par, vector<vli>& adj, vector<bool> &vis, vli &store){
    vis[src]=true;
    store.push_back(src);
    for(auto e:adj[src]){
        if(e==par)continue;
        if(vis[e]){
            store.push_back(e);
            return true;
        }
        if(dfs(e, src, adj, vis, store))return true;
    }
    store.pop_back();
    return false;
}
 
int main(int argc, char const *argv[])
{
    ll n, m, x, y;
    cin>>n>>m;
    vector<vli> adj(n+1, vli());
    for(int i=0; i<m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    if(n<3){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<bool> vis(n+1, false);
    vli store;
 
    for(int i=1; i<=n; i++){
        if(vis[i])continue;
        if(dfs(i, -1, adj, vis, store))break;
    }
    if(!store.size()){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    // cout<<"-> "; for(auto e:store)cout<<e<<" "; cout<<endl;
    int ind=store.size()-2;
    while(store[ind]!=store.back())ind--;
    cout<<store.size()-ind<<endl;
    while(ind<store.size()){
        cout<<store[ind]<<" ";
        ind++;
    }
    cout<<endl;
 
    return 0;
}
