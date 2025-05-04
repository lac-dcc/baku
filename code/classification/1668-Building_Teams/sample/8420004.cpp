#include <bits/stdc++.h>
 
using namespace std;
const int MAX=1e5+10;
const int INF=(1<<30);
int n,m;
vector<int> graph[MAX];
int vis[MAX];
bool flag=true;
void dfs(int node, int color)
{
    if(flag==false)return;
    if(vis[node]!=-1)return;
    vis[node]=color;
    for(auto neighbour:graph[node])
    {
        if(vis[neighbour]==color)
        {
            flag=false;
            return;
        }
        dfs(neighbour,!color);
    }
 
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(vis,-1,sizeof(vis));
    for(int i=0; i<n; i++)
    {
        if(vis[i]==-1)
        {
            dfs(i,0);
        }
        if(!flag)break;
    }
    if(!flag)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        cout<<vis[i]+1<<" ";
    }
    cout<<endl;
    return 0;
}
