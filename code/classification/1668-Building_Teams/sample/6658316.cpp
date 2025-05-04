#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
void bfs( vector<ll> &vis, ll node,vector<ll>  adj[] ,bool & check)
{
    queue<ll> q;
    q.push(node);
    while (!q.empty())
    {
 
        ll adjnode = q.front();
        q.pop();
        for (auto it : adj[adjnode])
        {
            if (vis[it] == 0)
            {
                if (vis[adjnode] == 1)
                    vis[it] = 2;
                else
                    vis[it] = 1;
                q.push(it);
            }
            else if(vis[it]==vis[adjnode])
            {
                check=true;
                return;
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n];
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool check=false;
    vector<ll> vis(n, 0);
    for (ll i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            bfs(vis, i, adj,check);
        }
        if(check)
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    for (ll i = 0; i <n; i++)
    {
        cout<<vis[i]<<" ";
    }
    
 
    return 0;
}
