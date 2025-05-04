#include<bits/stdc++.h>
#define INF 1e9
#define NINF -INF
#define int long long int
#define pb push_back
#define endl "\n";
#define L(i,a,b) for(int i=a;i<b;i++)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
 
bool bfs(int i,vector<vector<int>>adj,vector<int>&dis,vector<bool>&visited,vector<int>&parent,int n){
    visited[i]=1;
    dis[i]=1;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(node==n){
            return true;
        }
        for(auto child : adj[node]){
            if(!visited[child]){
                visited[child]=1;
                dis[child]=1+dis[node];
                q.push(child);
                parent[child]=node;
            }
        }
    }
    return false;
}
 
void answer(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    L(i,0,m){
        int k1,k2;
        cin>>k1>>k2;
        adj[k1].pb(k2);
        adj[k2].pb(k1);
    }
    vector<int>dis(n+1,INF);
    vector<bool>visited(n+1,false);
    vector<int>parent(n+1,-1);
    if(bfs(1,adj,dis,visited,parent,n)){
        cout<<dis[n]<<endl;
        int a=n;
        stack<int>s;
        while(a!=1){
            s.push(a);
            a=parent[a];
        }
        s.push(1);
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    else{
        cout<<"IMPOSSIBLE";
    }
}
int32_t main(){
    fast_io;
    answer();
}
