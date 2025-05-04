#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
 
vi adj[500001];
int rt = 1, rd = 0;
int dist[500001], dist2[500001];
 
void dfs(int x, int p, int d, int* dist)
{
    if (d >= rd)
        rt = x, rd = d;
 
    dist[x] = d;
    for (int y : adj[x])
        if (y != p)
            dfs(y, x, d + 1, dist);
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, 0, dist);
    dfs(rt, 0, 0, dist);
    dfs(rt, 0, 0, dist2);
    for (int i = 1; i <= n; ++i)
        cout << max(dist[i], dist2[i]) << ' ';
}
