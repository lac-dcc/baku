#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define file "name" 
template <typename T1, typename T2> bool minimize(T1 &a, T2 b){if (a > b) {a = b; return true;} return false;}
template <typename T1, typename T2> bool maximize(T1 &a, T2 b){if (a < b) {a = b; return true;} return false;}
 
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const ll INF = 1e16;
 
int n, m;
ll res = INF;
vector <pii> a[N], b[N];
vector <ll> d1, d2;
 
void inp()
{
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].pb({v, w});
        b[v].pb({u, w});
    }
}
 
void dijkstra(int s, vector <pii> a[], vector <ll> &d)
{
    d.resize(N, INF);
    priority_queue <pll, vector <pll>, greater <pll>> q;
    q.push({0, s});
    d[s] = 0;
    while(!q.empty()) {
        int u = q.top().se;
        ll du = q.top().fi;
        q.pop();
        if(du != d[u]) continue;
        for(auto e : a[u]) {
            int v = e.fi;
            ll w = e.se;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}
 
void solve()
{
    dijkstra(1, a, d1);
    dijkstra(n, b, d2);
    for(int u = 1; u <= n; ++u)
        for(auto i : a[u]) {
            int v = i.fi;
            ll w = i.se;
            minimize(res, d1[u] + d2[v] + w / 2);
    }
    cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen(file".inp" , "r" , stdin);
    // freopen(file".out" , "w" , stdout);
    inp();
    solve();
    return 0;
}
