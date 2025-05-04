#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pi;
typedef vector<int> vi;
#define pb push_back
#define sortd(v) sort(v.rbegin(), v.rend())
#define fr(i, a, b) for (int i = a; i < b; i++)
#define in(v, n)                \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
#define out(v, n)               \
    for (int i = 0; i < n; i++) \
    cout << v[i] << " "
#define all(v) v.begin(), v.end()
#define maxe(v) *max_element(all(v))
#define mine(v) *min_element(all(v))
//--------------------------------------------------------------------------------------------------------
vector<int> ans;
int dfs(int node, int par, vi adj[])
{
    int cnt = 1;
    for (auto it : adj[node])
    {
        if (it != par)
        {
            cnt += dfs(it, node, adj);
        }
    }
    ans[node] = cnt;
    return cnt;
}
void solve()
{
    int n;
    cin >> n;
    vi a(n - 1);
    in(a, n - 1);
    vi adj[n];
    fr(i, 0, n - 1)
    {
        int v = i + 1, u = a[i] - 1;
        adj[u].push_back(v);
    }
    ans.resize(n, 0);
    dfs(0, -1, adj);
    for (auto it : ans)
    {
        cout << it - 1 << " ";
    }
}
 
//--------------------------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
