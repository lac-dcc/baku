#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n,m,a,b;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
 
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parent(n+1,-1);
    vector<bool> vis(n+1,0);
 
    queue<int> q;
    bool sol = 0;
    q.push(1);
    int p;
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p==n){
            sol = 1;
            break;
        }
        // if(vis[p])continue;
        // vis[p]=1;
 
        for(auto x:adj[p]){
            if(vis[x] or parent[x]!=-1)continue;
            vis[p]=1;
            parent[x] = p;
            q.push(x);
        }
    }
 
    if(!sol){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<int> v;
    int par = n;
    int count = 0;
    while(par!=-1){
    	count++;
    	v.push_back(par);
        par = parent[par];
    }
    reverse(v.begin(),v.end());
    cout<<count<<endl;
    for(auto x:v)cout<<x<<" ";
    return 0;
}
