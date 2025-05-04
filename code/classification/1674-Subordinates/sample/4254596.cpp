#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 200001
ll n;
bool vis[N];
ll sub[N];
vector<int> adj[N];
void dfs(int node,int par){
   for(auto child:adj[node]){
    if(child!=par){
        dfs(child,node);
        sub[node]+=(1+sub[child]);
    }
   }
}
int main(){
    cin>>n;
    int par;
    for(int i=2;i<=n;i++){
        cin>>par;
        adj[i].push_back(par);
        adj[par].push_back(i);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++)
    cout<<sub[i]<<" ";
}
