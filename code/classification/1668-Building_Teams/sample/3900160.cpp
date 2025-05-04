#include <bits/stdc++.h>
 
using namespace std;
 
#define ull unsigned long long int
 
#define ll long long int
 
#define endl "\n"
 
#define mod 1000000007
 
vector<ll> graph[100005];
vector<bool> went(100005, false);
vector<ll> color(100005, 0);
vector<ll> p(100005, -1);
 
void dfs(ll s, ll toba)
{
    if (went[s])
    {
        return;
    }
    color[s] = 1 + toba;
    // cout << s << " " << 1 + toba << endl;
    went[s] = true;
    for (auto it : graph[s])
    {
        p[it] = s;
        dfs(it, (toba + 1) % 2);
    }
    return;
}
 
void solve()
{
    ll i, j, n, m;
    cin >> n >> m;
 
    ll a, b;
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    for (i = 1; i <= n; i++)
    {
        if (!went[i])
        {
            dfs(i, (ll)0);
        }
    }
 
    for (i = 1; i <= n; i++)
    {
        if (color[i] == color[p[i]])
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
 
    for (i = 1; i <= n; i++)
    {
        cout << color[i] << " ";
    }
 
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    solve();
 
    // ll tc;
    // cin >> tc;
    // while (tc--)
    // {
    //     solve();
    // }
}
