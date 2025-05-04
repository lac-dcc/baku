#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
#define vll vector<long long>
#define vvll vector<vll>
#define vp vector<pair<ll, ll>>
#define mp make_pair
#define mll map<ll, ll>
#define mpll map<pll, ll>
#define all(a) (a).begin(), (a).end()
#define FF first
#define SS second
#define sz(x) (int)x.size()
#define endl '\n'
#define hell 998244353
#define rep(i, a, b) for (i = a; i <= b; i++)
#define re(i, a, b) for (i = a; i >= b; i--)
#define pie 2 * acos(0.0)
// #define fori(n) for (ll i = 0; i < n; i++)
// #define fori1(n) for (int i = 1; i < n; i++)
#define pi 3.14159265358979323
#define mod 1000000007
using namespace std;
 
void dfs(ll root, vvll &g, vll &vis)
{
    vis[root] = 1;
 
    for (auto i : g[root])
    {
        if (!vis[i])
            dfs(i, g, vis);
    }
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n + 1);
    vvll edges;
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        edges.push_back({a, b, c});
    }
 
    vvll dp(n + 1, vector<ll>(2, 1e16));
 
    dp[1][0] = 0, dp[1][1] = 0;
 
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q;
    // 0 -> Coupon Available
    // 1 -> Coupon Not Available
    q.push({0, 1, 1});
 
    while (!q.empty())
    {
        vector<ll> v = q.top();
        q.pop();
        ll coupon = v[2], d = v[0], root = v[1];
 
        if ((coupon && d > dp[root][0]) || (!coupon && d > dp[root][1]))
            continue;
 
        for (auto i : g[root])
        {
            ll v = i.first, w = i.second;
            ll i1 = dp[v][0], i2 = dp[v][1];
            dp[v][0] = min(dp[root][0] + w, dp[v][0]);
            dp[v][1] = min({dp[v][1], dp[root][1] + w, dp[root][0] + w / 2});
            if (dp[v][0] == i1 && dp[v][1] == i2)
                continue;
 
            if (i1 != dp[v][0])
                q.push({dp[v][0], v, 1});
            if (i2 != dp[v][1])
                q.push({dp[v][1], v, 0});
        }
    }
 
    cout << dp[n][1] << endl;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}
