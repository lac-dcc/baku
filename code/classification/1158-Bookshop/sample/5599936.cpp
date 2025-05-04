#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll; typedef pair<int,int> ii;
int testcases = 0;
const int INF = 1.05e9; const ll INFLL = 4.5e18;
#define endl '\n'
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif
 
void solve(){
    int n, mx; cin >> n >> mx;
    vector<int> x(n+1), p(n+1);
    for(int i = 0; i < n; i++){
        cin >> x[i+1];
    }
    for(int i = 0; i < n; i++){
        cin >> p[i+1];
    }
 
    vector<vector<int>> dp(n+1, vector<int>(mx+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= mx; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= x[i]) dp[i][j] = max(dp[i][j], p[i] + dp[i-1][j-x[i]]);
        }
    }
    cout << dp[n][mx] << endl;
 
    /* vector<vector<int>> dp(mx+1, vector<int>(n+1)); */
    /* for(int i = 1; i <= n; i++){ */
    /*     for(int j = 1; j <= mx; j++){ */
    /*         dp[j][i] = dp[j][i-1]; */
    /*         if(j >= x[i]) dp[j][i] = max(dp[j][i], p[i] + dp[j-x[i]][i-1]); */
    /*     } */
    /* } */
    /* cout << dp[mx][n] << endl; */
 
}
 
signed main(){
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);cin.tie(0);
#endif
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}