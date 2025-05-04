#include <bits/stdc++.h>
 
using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<ll,ll> ii;
 
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
 
const int maxn = 505;
int n, m, q;
ll d[maxn][maxn];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = 1e15;
        }
        d[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> v >> u >> w;
        --u; --v;
        d[v][u] = min(d[v][u], w);
        d[u][v] = min(d[u][v], w);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    while (q--) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        cout << (d[v][u] >= 1e15 ? -1 : d[v][u]) << '\n';
    }
}
 
 
 
 
 
