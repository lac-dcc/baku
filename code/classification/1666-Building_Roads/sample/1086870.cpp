#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void dfs(vector<ll> adj[],vector<bool>& visited,ll s){
    if(visited[s])  return;
    visited[s]=true;
    for(auto u:adj[s]){
        dfs(adj,visited,u);
    }
}
 
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> adj[n+1];//we have declared size as n+1 coz we will consider index from 1 to n and not from 0 to n-1
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n+1,false);
    ll components=0;
    vector<ll> nodes;//it will store one node from each component
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            dfs(adj,visited,i);
            nodes.push_back(i);
            components++;
        }
    }
    cout<<components-1<<endl;
    if(components>1){
        ll a=nodes[0];
        for(size_t i=1;i<nodes.size();i++)
            cout<<a<<" "<<nodes[i]<<endl;
    }
    return 0;
}
