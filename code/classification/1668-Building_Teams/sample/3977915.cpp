#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
vector<ll> graph[100000 + 1];
bool visited[100000 + 1];
ll color[100000 + 1];
 
bool bipartite(ll nodes)
{
 
    queue<ll> q;
    for (ll i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = true;
            color[i] = 1;
        }
        while (!q.empty())
        {
            ll vertex = q.front();
            q.pop();
            for (ll i = 0; i < graph[vertex].size(); i++)
            {
                if (!visited[graph[vertex][i]])
                {
                    visited[graph[vertex][i]] = true;
                    q.push(graph[vertex][i]);
                    if (color[vertex] == 1)
                    {
                        color[graph[vertex][i]] = 2;
                    }
                    else if (color[vertex] == 2)
                    {
                        color[graph[vertex][i]] = 1;
                    }
                }
                else
                {
                    if (color[vertex] == color[graph[vertex][i]])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
 
int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    for (ll i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
    bool a = bipartite(n);
 
    if (a)
    {
        for (ll i = 1; i <= n; i++)
        {
            cout << color[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
