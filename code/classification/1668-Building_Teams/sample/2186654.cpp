#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int group[100001];
bool visited[100001];
bool color;
int flag=1;
int n,m;
void dfs(int node,bool color)
{
    visited[node]=1;
    group[node]=color;
    for(auto v: adj[node])
    {
        if(!visited[v])
            dfs(v,!color);
        else
        {
            if(group[v]==color)
            flag=0;
        }
    }
}
 
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    for(int i=1;i<n;i++)
    {
        if(!visited[i])
            dfs(i,0);
    }
    if(flag==0)
        cout<<"IMPOSSIBLE"<<endl;
    else
        for(int i=1;i<=n;i++)
        cout<<group[i]+1<<" ";
}
