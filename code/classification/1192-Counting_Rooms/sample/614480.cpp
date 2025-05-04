#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned ll
#define ld long double
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define VLL vector<ll>
#define VB vector<bool>
#define VS vector<string>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MOD 1000000007
#define MAX 1000005
using namespace std;
 
void bfs(VS &g, vector<VB> &vis, pll p)
{
    ll n = g.size(), m = g[0].size();
    queue<pll> q;
    q.push(p);
    while(!q.empty())
    {
        p = q.front();
        ll x = p.F, y = p.S;
        q.pop();
        if(vis[x][y]) continue;
        vis[x][y] = true;
        if(x-1>=0 && g[x-1][y]=='.') q.push({x-1, y});
        if(x+1<n && g[x+1][y]=='.') q.push({x+1, y});
        if(y-1>=0 && g[x][y-1]=='.') q.push({x, y-1});
        if(y+1<m && g[x][y+1]=='.') q.push({x, y+1});
    }
}
 
int main()
{
    FASTIO;
    ll n,m;
    cin>>n>>m;
    VS g(n);
    for(auto &i:g) cin>>i;
 
    vector<VB> vis(n, VB(m, false));
    ll ans = 0;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(g[i][j]=='.' && !vis[i][j])
            {
                ans++;
                bfs(g, vis, {i, j});
            }
        }
    }
    cout<<ans<<'\n';
}
