#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
    #include "D:/algo/debug.h"
#else
    #define dbg(...) 1
    #define cerr if(0) cerr
#endif
 
#define ll long long int
#define endl "\n"
 
void solve(int &tc)
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    for(ll i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<ll> dist(n + 1, 0);
    vector<ll> par(n + 1, -1);
    for(ll i = 1; i <= n - 1; i++) {
        for(auto e : edges) {
            ll u = e[0];
            ll v = e[1];
            ll w = e[2];
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                par[v] = u;
            }
        }
    }
    ll x = -1;
    for(auto e : edges) {
        ll u = e[0];
        ll v = e[1];
        ll w = e[2];
        if(dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            par[v] = u;
            x = v;
        }
    }
    if(x == -1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        // to get back into cycle
        for(ll i = 1; i <= n - 2; i++) {
            x = par[x];
        }
        vector<ll> ans;
        ans.push_back(x);
        ll tmp = par[x];
        while(tmp != x) {
            ans.push_back(tmp);
            tmp = par[tmp];
        }
        ans.push_back(x);
        reverse(ans.begin(), ans.end());
        for(ll aa : ans) {
            cout << aa << ' ';
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    #ifdef LOCAL
        freopen("D:/algo/io/input.txt", "r", stdin);
        freopen("D:/algo/io/output.txt", "w", stdout);
        freopen("D:/algo/io/debug.txt", "w", stderr);
    #endif
 
    int rep = 1;
    while(rep--) {
        int tc = 1;
        for(int i = 1; i <= tc; i++) {
            cerr << "Case #" << i << endl;
            solve(i);
        }
        if(dbg()) break;
    }
    return 0;
}
