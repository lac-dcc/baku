#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
#define fl(i, x, n) for (int i = x; i < n; i++)
 
bool checkPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
 
void dfs(vector<vector<int>> &adj, int node, vector<int> &visited, queue<int> &q)
{
 
    visited[node] = 1;
 
    for (auto x : adj[node])
    {
 
        if (visited[x] != 1)
        {
            dfs(adj, x, visited, q);
        }
    }
 
    q.push(node);
}
 
void solve()
{
    int n, m;
 
    cin >> n >> m;
 
    vector<vector<int>> adj(n + 1);
    vector<int> visited(n + 1, 0);
 
    fl(i, 0, m)
    {
 
        int x, y;
        cin >> x >> y;
 
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    int last = -1, cnt = 0;
    vector<pair<int, int>> ans;
    queue<int> qq;
 
    dfs(adj, 1, visited, qq);
    last = qq.front();
 
    fl(i, 2, n + 1)
    {
 
        if (last != -1 && visited[i] == 0)
        {
            cnt++;
            ans.push_back({last, i});
 
            queue<int> q;
            dfs(adj, i, visited, q);
            last = q.front();
        }
    }
 
    cout << cnt << "\n";
    fl(i, 0, cnt)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}
 
int main()
 
{
 
    fast_io;
 
    int t = 1;
 
    while (t--)
    {
        solve();
    }
 
    return 0;
}
