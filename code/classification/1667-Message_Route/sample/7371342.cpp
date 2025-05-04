#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<int> adj[n + 1];
 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<int> visited(n + 1, 0);
 
    queue<int> q;
 
    
    q.push(1);
 
 
    vector<int> dist(n + 1, INT_MAX);
    vector<int> p(n+1,-1);
 
 
    dist[1] = 0;
 
    bool flag=false;
 
    while(!q.empty()){
        int  par= q.front();
        q.pop();
 
        if(par==n){
            flag =true;
            break;
        }
        
        for(auto it : adj[par]){
            if(!visited[it]){
                if(dist[it]>dist[par]+1){
                    dist[it]=dist[par]+1;
                    q.push(it);
                    p[it]=par;
                }
            }
        }
    }
 
    if(!flag){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
 
    vector<int> ans;
 
    while(n!=-1){
        ans.push_back(n);
        n=p[n];
    }
 
    cout<<ans.size()<<endl;
 
    reverse(ans.begin(),ans.end());
 
    for(auto it : ans){
        cout<<it<<" ";
    }
 
    cout<<endl;
 
    
 
    return 0;
}
