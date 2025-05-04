#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'
#define pii pair<ll int, ll int>
#define vi vector<ll int>
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define sz(x) (ll int)x.size()
#define r(i, a, b) for (i = a; i < b; i++)
#define ra(i, a, b) for (i = a; i <= b; i++)
#define lbnd lower_bound
#define ubnd upper_bound
#define bs binary_search
#define mp make_pair
#define ss set<ll int>
using namespace std;
 
// void kickstart(ll int &t, ll int &z)
// {
//     cout << "Case #" << (z - t) << ": "
//          << "\n";
// }
 
#define N 5000005
#define M 1000000007
 
int start = -1;
int en = -1;
 
bool dfs(int i, int c, vector<ll int> adj[], vector<bool> &vis, vector<ll int> &city)
{
    vis[i] = true;
    city[i] = c;
 
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            bool res = dfs(it, i, adj, vis, city);
            if (res)
                return true;
        }
        else if (it != c)
        {
            start = it;
            en = i;
            return true;
        }
    }
    return false;
}
 
void solve()
{
    ll n, m, i, j, k, l;
    cin >> n >> m;
 
    vi adj[n + 1];
 
    r(i, 0, m)
    {
        cin >> k >> l;
        adj[k].pb(l);
        adj[l].pb(k);
    }
 
    vector<bool> vis(n + 1, false);
    vector<ll int> city(n + 1, -1);
    bool resp;
 
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bool resp = dfs(i, -1, adj, vis, city);
            if (resp)
                break;
        }
    }
 
    vector<int> ans;
 
    for (int i = en; (city[i] != -1 && i != start); i = city[i])
        ans.push_back(i);
    if (start != -1 && en != -1)
    {
        ans.push_back(start);
        ans.push_back(en);
    }
 
    if (ans.size() > 0)
    {
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    }
    else
        cout << "IMPOSSIBLE"
             << "\n";
}
 
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.sync_with_stdio(0), cout.tie(0), cout.sync_with_stdio(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
