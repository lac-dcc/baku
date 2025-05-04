#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define pi 2 * acos(0.0)
#define all(v) v.begin(), v.end()
 
using namespace std;
 
void OJ()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
int fp(ll a, ll b, ll m = mod)
{
    a %= m;
    if (a == 0)
        return 0;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}
 
/* -------------“All that we are is the result of what we have thought.” ------------- */
 
bool dfs(vector<vector<int>> &gr, int node, vector<int> &ans, int col)
{
    ans[node] = col;
 
    for (auto to : gr[node])
    {
        if (ans[to] == 0)
        {
            bool ok = dfs(gr, to, ans, 3 - col);
            if (!ok)
                return false;
        }
        else if (ans[to] == col)
            return false;
    }
    return true;
}
 
void solve()
{
    OJ();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
 
        vector<vector<int>> gr(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
 
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
 
        //int ans[n + 1] = {0};
	vector<int> ans(n + 1, 0);
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            if (ans[i] == 0)
            {
                bool ch = dfs(gr, i, ans, 1);
                if (!ch)
                {
                    ok = false;
                    break;
                }
            }
        }
 
        if (!ok)
            cout << "IMPOSSIBLE\n";
        else
        {
            for (int i = 1; i <= n; i++)
                cout << ans[i] << " ";
        }
    }
}
 
int main()
{
    solve();
 
    return 0;
}
