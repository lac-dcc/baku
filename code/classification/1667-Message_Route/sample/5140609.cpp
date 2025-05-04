#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int start=1, end=n;
    vector<int> vis(n+1,0);
    vector<int> par(n+1,-1);
    queue<int> q;
    q.push(1);
    vis[1]=1;
    int found=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(node==end){
            found=1;
            break;
        }
        else{
            for(auto x:g[node]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=1;
                    par[x]=node;
                }
            }
        }
    }
    if(found){
        vector<int> path;
        while(end!=start){
            path.pb(end);
            end=par[end];
        }
        path.pb(start);
        cout<<path.size()<<"\n";
        for(int i=path.size()-1;i>=0;i--){
            cout<<path[i]<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE";
    }
    cout<<"\n";
}
