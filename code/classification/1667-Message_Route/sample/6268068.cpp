#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define pi pair<int,int>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool bfs(vector<vector<int>>&g,int source,vector<int>&vis,int n){
    queue<int>q;
    q.push(source);
    vis[source]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==n)return true;
        for(auto v:g[u]){
            if(!vis[v]){
                vis[v]=u;
                q.push(v);
            }
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
   vector<vector<int>>g(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int>vis(n+1,0);  
    if(bfs(g,1,vis,n)){
        vector<int>path;
        int i=n;
        while(i!=1){
            path.pb(i);
            i=vis[i];
        }
        path.pb(1);
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for(auto x:path)cout<<x<<" ";
        cout<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
