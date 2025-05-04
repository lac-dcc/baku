#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long int n,m;
    cin>>n>>m;
    vector<pair<long long int,long long int>>adj[n+1];
    for (long long int i = 0; i < m; i++)
    {
        long long int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<long long int>dist(n+1, 1e18);
    priority_queue<pair<long long int,long long int>, vector<pair<long long int,long long int>>, greater<pair<long long int,long long int>>>p;
    dist[1] = 0;
    p.push({0,1});
    while (!p.empty())
    {
        long long int d = p.top().first;
        long long int node = p.top().second;
        p.pop();
        if(dist[node] < d)
			continue;
        for (auto it : adj[node])
        {
            if (it.first==1) continue;
            long long int adjNode = it.first;
            long long int w = it.second;
            if (d + w < dist[adjNode])
            {
                dist[adjNode] = d+w;
                p.push({dist[adjNode],adjNode});
            }
        }
    }
    for (long long int i = 1; i<=n; i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}
