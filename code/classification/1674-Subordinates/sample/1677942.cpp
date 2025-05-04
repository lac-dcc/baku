#include <bits/stdc++.h>
 
using namespace std;
const int Nmax = 2e5 + 5;
vector <int> adj[Nmax];
bool vis[Nmax];
int cnt[Nmax];
void dfs(int u)
{
    vis[u] = true;
    for (int v: adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
            cnt[u] += 1;
        }
        cnt[u] += cnt[v];
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        int j;
        cin >> j;
        adj[j].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
        cout << cnt[i] << " ";
    return 0;
}
