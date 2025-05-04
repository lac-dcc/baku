#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define ip pair<int,int>
 
using namespace std;
 
int mod = (int)1e9 + 7;
 
int finalAns=INT_MAX;
 
void dfs(int node,int des,vi graph[], bool vis[], vi & currPath,vi & path){
    vis[node]=true;
    currPath.pb(node);
    for(auto n:graph[node]){
        if(n==des){
            if(finalAns>currPath.size()){
                finalAns=currPath.size();
                path=currPath;
            }
            return;
        }
        if(vis[n]==false){
            dfs(n,des,graph,vis,currPath,path);
        }
    }
    currPath.pop_back();
    return;
}
 
void path (vi &parent,int n){
    vi vec;
    while(n>=1){
        vec.pb(parent[n]);
        n=parent[n];
    }
    for(int i=vec.size()-2;i>=0;i--){
        cout<<vec[i]<<" ";
    }cout<<parent.size()-1<<endl;
}
 
void solve(){
    int n,m;
    cin>>n>>m;
    vi graph[n+1];
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    priority_queue<ip,vector<ip>,greater<ip>> pq;
    
    vi dist(n+1,n+2);
    dist[1]=0;
    
    pq.push({0,1});
    
    bool pro[n+1];
    memset(pro,false,n+1);
    vi parent(n+1,-1);
    
    while(!pq.empty()){
        ip p = pq.top();
        pq.pop();
        pro[p.second]=true;
        for(auto node:graph[p.second]){
            if(pro[node]==false && dist[node]>dist[p.second]+1){
                dist[node]=dist[p.second]+1;
                parent[node]=p.second;
                pq.push({dist[node],node});
            }
        }
    }
    if(dist[n]==n+2){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<dist[n]+1<<"\n";
        path(parent,n);
    }
}
 
int main()
{
    solve();
   return 0;
}
