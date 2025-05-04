#include<iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;
typedef pair <long long, long long> pr;
 
long long int INF=numeric_limits<long long int>::max();
 
struct Edge
{
    long long int to,weight;
};
 
void djiksta(int start, vector< vector<Edge> >& graph, vector<long long int>& dist)
{
    priority_queue< pr, vector<pr>, greater<pr> >q;
    q.push({0,start});
    dist[start]=0;
    //q.push(make_pair(dist[src],src));
 
    while (!q.empty())
    {
        pr node;
        node = q.top();
        long long int d=node.first;
        long long int u= node.second;
        q.pop();
 
        if (d>dist[u]) continue;
 
        //int v,w;
        //for (const auto& edge : graph[u])
        for (vector<Edge>::iterator it=graph[u].begin(); it!=graph[u].end(); it++)
        {
            long long int v= it->to;
            long long int w= it->weight;
            if (dist[u]+w <dist[v])
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    q.push({dist[v], v});
                }
        }
    }
}
 
int main()
{
    long long int n,m;
    cin>>n>>m;
 
    vector<vector<Edge> >graph(n+1);
    vector<long long int> dist (n+1,INF);
    for (int i=0; i<m; i++)
    {
        long long int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    int source=1;
    djiksta(source,graph,dist);
 
    for(int i=1; i<=n; i++)
    {
        cout<<dist[i]<<" ";
    }
 
}
