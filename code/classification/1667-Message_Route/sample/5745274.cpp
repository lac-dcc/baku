#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
int visited[N], level[N], parent[N];
void bfs(int node)
{
    visited[node] = 1;
    level[node] = 1;
    parent[node] = -1;
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int head = q.front();
         q.pop();
         for(int i:adj[head])
         {
             if(visited[i] == 0)
             {
                 visited[i] = 1;
                 level[i] = level[head] + 1;
                 q.push(i);
                 parent[i] = head;
             }
         }
    }
}
 
int main()
{
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    if(visited[n] == 0)
    {
         cout<<"IMPOSSIBLE"<<endl;
         return 0;
    }
    cout<<level[n]<<endl;
    int s_node = n;
    vector<int> v;
    while(1)
    {
        v.push_back(s_node);
        if(s_node == 1) break;
        s_node = parent[s_node];
    }
    reverse(v.begin(), v.end());
    for(int i:v)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
