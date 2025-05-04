#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f first
#define s second
#define pb push_back
#define For(i,a,n) for(ll i=(a);i<(n);i++)
 
ll n,m;
vector<vector<int> >adj;
vector<int>group;
vector<bool>visited;
 
bool dfs(ll node,ll curr){
    visited[node] = 1;
    group[node] = curr;
    for(auto i:adj[node]){
        if(group[i] == group[node])return 0;
        if(!visited[i]){
            bool temp = dfs(i,3-curr);
            if(temp==0)return 0;
        }
    }
    return 1;
}
 
void solution(){
    // cout<<"Hello world "<<endl;
    cin>>n>>m;
    adj.resize(n+1);
    visited.resize(n+1);
    For(i,1,n+1)visited[i] = 0;
    For(i,0,m){
        ll u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    group.resize(n+1);
    For(i,1,n+1){
        if(!visited[i]){
           bool temp =  dfs(i,1);
           if(temp==0){
                cout<<"IMPOSSIBLE"<<endl;
                return;
           }
        }
    }
    For(i,1,n+1)cout<<group[i]<<" ";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}
