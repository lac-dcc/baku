#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define arr array
#define for_(i, s, e) for (ll i = s; ((i < e) && (s < e)) || ((i > e) && (s >= e)); (s < e) ? i++ : i--)
 
int main()
{
    ll t;
    t = 1;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> adj[n + 1];
        for_(i, 0, m)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<ll> color(n + 1, -1); // IMPORTANT
        bool visited[n + 1];
        memset(visited, false, sizeof(visited)); // IMPORTANT
        for_(i, 1, n + 1)
        {
            if (!visited[i])
            {
                queue<ll> q;
                q.push(i);
                color[i] = 0;
                while (!q.empty())
                {
                    ll node = q.front();
                    q.pop();
                    
                    if (visited[node])
                        continue;
                    visited[node] = true;
                    for (auto it : adj[node])
                    {
                        q.push(it);
                        
                        if (color[it] == -1)
                        {
                            color[it] = 1 - color[node];
                        }
                        else if (color[it] == color[node])
                        {
                            cout << "IMPOSSIBLE";
                            return 0;
                        }
                    }
                }
            }
        }
        for_(i, 1, n + 1)
        {
            cout << color[i] + 1 << " ";
        }
    }
}
