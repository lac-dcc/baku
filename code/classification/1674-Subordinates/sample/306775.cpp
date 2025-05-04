#include <bits/stdc++.h>
 
using namespace std;
int chi[200005];
int n,u;
vector <int> adj[200005];
 
void dfs(int u)
{
    for (int v : adj[u])
    {
        dfs(v);
        chi[u] += chi[v] + 1;
    }
}
 
int main()
{
    //freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> u;
        adj[u].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << chi[i] << " ";
    }
    return 0;
}
