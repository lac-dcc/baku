#include <bits/stdc++.h>
 
using namespace std;
const int N = 100000;
const long long INF = (1LL<<60);
vector< pair<int, int> >adj[N + 1];
int n, m;
long long dist[N + 1];
 
void dijkstra(int x)
{
    for(int i=1; i<=n; i++)
        dist[i] = INF;
    dist[x] = 0;
 
    //min heap (distance, node)
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    q.push({dist[x], x});
    int node;
    long long distance;
    while(!q.empty())
    {
        distance = q.top().first;
        node = q.top().second;
        q.pop();
        if(dist[node] < distance)
            continue;
        for(auto u: adj[node])
        {
            int child = u.first;
            long long weight = u.second;
            if(dist[node] + weight < dist[child])
            {
                dist[child] = dist[node] + weight;
                q.push({dist[child], child});
            }
        }
    }
}
 
int main()
{
    cin >> n >> m;
    int a, b, c;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
 
    dijkstra(1);
    for(int i=1; i<=n; i++)
        cout << dist[i] << ' ';
    return 0;
}
