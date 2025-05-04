// Vaibhav Goyal
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pr(X) cout << (X) << endl;
#ifndef ONLINE_JUDGE
#include "myprettyprint.hpp"
#else
#define dbg(...)
#endif
 
const int inf = 1e18;
struct Solution {
    void solve() {
        // dp[i][j][1...k]
        // use the kth node or not
        // dp[i][j][1...k-1]
        // let the kth
        int n, m, q; cin >> n >> m >> q;
        vector<vector<int>> dp(n, vector<int>(n, inf));
        for (int i = 0; i < m; i++) {
            int a, b, d; cin >> a >> b >> d;
            a--; b--;
            dp[a][b] = min(dp[a][b], d);
            dp[b][a] = min(dp[b][a], d);
        }
        for (int i = 0; i < n; i++) dp[i][i] = 0;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
 
        while(q--) {
            int a, b; cin >> a >> b;
            a--; b--;
            cout << (dp[a][b] == inf ? -1 : dp[a][b]) << endl;
        }
 
 
 
 
 
 
    }
};
 
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
 
    int tc = 1;
 
//    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        Solution solution;
        solution.solve();
    }
    return 0;
}
