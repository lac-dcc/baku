#include <bits/stdc++.h>
using namespace std;
 
#define IAMSPEED ios_base::sync_with_stdio(0); cin.tie(0);
 
const int mod = 998244353;
const int oo = 1000000010;
const int N = 510;
 
int n, m, q;
long long d[N][N];
 
void solve(){
    cin >> n >> m >> q;
    memset(d, 0x3f, sizeof(d));
    for(int i = 1; i <= n; ++i){
        d[i][i] = 0;
    }
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = min(d[u][v], (long long)w);
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    while(q--){
        int u, v; 
        cin >> u >> v; 
        cout << (d[u][v] < 1e18 ? d[u][v] : -1) << '\n';
    }
}
 
int main(){
    IAMSPEED
    int t = 1;
    // cin >> t; 
    while(t--){
        solve();
    }
    return 0; 
}
