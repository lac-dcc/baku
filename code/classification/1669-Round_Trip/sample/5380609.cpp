#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
 
const int nmax = 1e5+5;
 
vector<int>adjacent_List[nmax];
bool visited[nmax];
int parent[nmax];
 
bool cycleFound;
int cycleEndNode;
 
void dfs(int node, int from)
{
    if(cycleFound == true)
    {
        return;
    }
    if(visited[node]==true)
    {
        cycleFound = true;
        cycleEndNode = from;
        parent[node] = from;
        return;
    }
 
    visited[node] = true;
    parent[node] = from;
 
    for(int to:adjacent_List[node])
    {
        if(to != from)
        {
            dfs(to, node);
        }
    }
}
 
void pathRetrieve(vector<int>&path, int node)
{
    if(node == cycleEndNode)
    {
        path.push_back(node);
        return;
    }
    else
    {
        pathRetrieve(path, parent[node]);
        path.push_back(node);
    }
}
 
int main()
{
    fastio;
 
    int node,edges; cin>>node>>edges;
 
    for(int i=1;i<=edges;i++)
    {
        int from,to;
        cin>>from>>to;
 
        adjacent_List[from].push_back(to);
        adjacent_List[to].push_back(from);
    }
 
    cycleFound = false;
    cycleEndNode = -1;
 
    for(int i=1;i<=node;i++)
    {
        if(cycleFound == true)
        {
            break;
        }
        if(visited[i]==false)
        {
            dfs(i,0);
        }
    }
 
    if(cycleFound==false)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        vector<int>path;
        pathRetrieve(path,parent[cycleEndNode]);
        path.push_back(cycleEndNode);
        cout<<path.size()<<endl;
        for(int x:path)cout<<x<<" ";
    }
    return 0;
}
