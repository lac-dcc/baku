#include<bits/stdc++.h>
using namespace std;
 
void DFS(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int> &child)
{
    if(vis[node])   return;
    vis[node]=true;
    for(int v:adj[node])
    {
        child[node]+=1;
        DFS(v,vis,adj,child);
        child[node]+=child[v];
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>child(n,0);
    vector<int>vis(n,false);
    vector<vector<int>>adj(n);
    for(int i=1;i<n;i++)
    {
        int u;  cin>>u;
        adj[u-1].push_back(i);
    }
    DFS(0,vis,adj,child);
    for(int i:child)
    {
        cout<<i<<' ';
    }
return 0;
}
