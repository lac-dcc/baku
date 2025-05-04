#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005
 
vector<pll> adj[2][MAXN];
ll dist[2][MAXN];
 
void djikstra(ll id, ll bg)
{
    ll cur, cd;
 
    set<pll> st;
    st.insert({0, bg});
    dist[id][bg] = 0;
 
    while(!st.empty())
    {
        cd = (*st.begin()).ff;
        cur = (*st.begin()).ss;
 
        st.erase(st.begin());
 
        if(dist[id][cur] < cd)
            continue;
 
        for(auto [nd, nxt] : adj[id][cur])
        {
            if(dist[id][nxt] > cd + nd)
            {
                st.insert({cd + nd, nxt});
                dist[id][nxt] = cd + nd;
            }
        }
    }
}
 
void solve(ll caseno)
{
    ll n, m, i, a, b, c, cur, cd, ans;
 
    cin >> n >> m;
 
    for(i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
 
        adj[0][a].push_back({c, b});
        adj[1][b].push_back({c, a});
    }
 
    fill(dist[0]+1, dist[0]+n+1, 1e18);
    djikstra(0, 1);
 
    fill(dist[1]+1, dist[1]+n+1, 1e18);
    djikstra(1, n);
 
    ans = LLONG_MAX;
    for(cur = 1; cur <= n; cur++)
    {
        for(auto [nd, nxt] : adj[0][cur])        
            ans = min(ans, dist[0][cur] + nd/2 + dist[1][nxt]);        
    }
 
    cout << ans << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll T = 1, caseno = 0;
 
    // cin >> T;
 
    while(T--)
    {
        solve(++caseno);
    }
}
