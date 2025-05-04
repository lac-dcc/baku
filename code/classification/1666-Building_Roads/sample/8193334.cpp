#include<bits/stdc++.h>
 
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
void dfs(vector<vector<int>> &adj,int node,vector<bool> &visited)
{
    //BC
    
    if(visited[node])
    {
        return;
    }
    
    //RC
    
    int n=adj[node].size();
    visited[node]=true;
    
    for(int i{};i<n;i++)
    {
        int x=adj[node][i];
        dfs(adj,x,visited);
    }
}
 
int main()
{
    fastio()
    
    int n{},m{};
    cin>>n>>m;
    
    vector<vector<int>> adj(n+1);
    
    for(int i{};i<m;i++)
    {
        int a{},b{};
        cin>>a>>b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> ans;
    vector<bool> visited(n+1,false);
    
    for(int i{1};i<n+1;i++)
    {
        if(!visited[i])
        {
            dfs(adj,i,visited);
            ans.push_back(i);
        }
    }
    
    // for(int i{1};i<n+1;i++)
    // {
    //     cout<<visited[i]<<" ";
    // }
    
    // cout<<" aka "<<endl;
    
    int n1=ans.size();
    
    cout<<n1-1<<endl;
    
    for(int i{1};i<n1;i++)
    {
        cout<<ans[i-1]<<" "<<ans[i]<<endl;
    }
    
    return 0;
}
        
