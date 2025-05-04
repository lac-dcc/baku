#include<iostream>
#include<vector>
#include<queue>
#define MAXN 200005
using namespace std;
 
int n;
vector<int> adj[MAXN];
bool vis[MAXN] = {0};
int children[MAXN] = {0};
 
int subordinates(int u){
    if( vis[u] )
        return children[u];
    vis[u] = true;
    for(int v: adj[u]){
        children[u]++;
        if(!vis[v]){
            children[u] += subordinates(v);
        }
    }
    return children[u];
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
 
    for(int i=1; i<=n; i++){
        cout<<subordinates(i)<<" ";
    }
 
}
