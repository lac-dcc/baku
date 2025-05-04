#include <bits/stdc++.h>
using namespace std;
typedef int int32_t;
#define int long long int
#define newline '\n'
 
void dfs(int v, vector<bool> &visited, vector<int> &parent, const vector<vector<int>> &adj, int &start, int &end)
{
    if(start != -1)
        return;
    visited[v] = true;
    for(const int &u: adj[v])
    {
        if(!visited[u])
        {
            parent[u] = v;
            dfs(u,visited,parent,adj,start,end);
        }
        else if(visited[u] && parent[v] != u)
        {
            // static int st = 0;
            // cout<<st++<<" ";
            // cout<<u<<"*"<<v<<newline;
            end = v;
            start = u;
            return;
        }
        if(start!=-1)
            break;
    }
 
}
 
int32_t main()
{
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // ..........................//
 
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n);    
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n,false);
    vector<int> parent(n,-1);
    int start = -1;
    int end = -1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            // res.push_back(i+1);
            dfs(i, visited, parent, adj, start ,end);
            if(start!=-1)
                break;
        }
    }
    if(start == -1)
        cout<<"IMPOSSIBLE"<<newline;
    vector<int> res;
    res.push_back(start);
    
    // cout<<start<<" ";
    while(end != start)
    {
        res.push_back(end);
        // cout<<end<<" ";
        end = parent[end];
    }
    // cout<<start<<newline;
    res.push_back(start);
    cout<<res.size()<<newline;
    for(const auto &i: res)
        cout<<i+1<<" ";
    cout<<newline;
    return 0;
}
