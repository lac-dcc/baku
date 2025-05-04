#include<bits/stdc++.h>
using namespace std;
#define SZ 200005
 
int n, m, x, y; 
vector<int> adj[SZ];
 
pair<int,int> bfs(int src)
{
    int d=0;
    queue<pair<int,int>> q;
    q.push({src,0});
    vector<bool> visited(SZ,false);
    pair<int,int> u;
 
    while(!q.empty())
    {
        u= q.front();
        visited[u.first] = true;
        q.pop();
        
        for(int v: adj[u.first])
        {
            if(!visited[v])
            {
                q.push({v,u.second+1});
            }
        }
    }
 
    return u; //return the last node and dist
}
 
int main()
{
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pair<int,int> end1 = bfs(1); //last node, dist
    pair<int,int> end2 = bfs(end1.first); //last node, dist
    cout<<end2.second<<endl;
 
}
