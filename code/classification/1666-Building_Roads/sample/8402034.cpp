#include<bits/stdc++.h>
using namespace std;
static const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];
 
void dfs(int src)
{
    visited[src] = true;
    for(int child:adj[src])
    {
        if(!visited[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(visited,false,sizeof(visited));
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            v.push_back(i);
            dfs(i);
        }
    }
 
    cout<<v.size()-1<<endl;
    for(int i=1;i<v.size();i++)
    {
        cout<<v[i-1]<<" "<<v[i]<<endl;
    }
    return 0;
}
