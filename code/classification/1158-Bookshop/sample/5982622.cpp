#include<bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n, x;
    cin >> n >> x;
 
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
 
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for (int i = 0; i <= x; ++i) {
        dp[0][i] = 0;
    }
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= x; ++j) {
            dp[i+1][j] = dp[i][j];
            if (j - a[i] >= 0) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-a[i]] + b[i]);
            }
        }
    }
 
    int ans = 0;
    for (int i = 0; i <= x; ++i) {
        ans = max(ans, dp[n][i]);
    }
 
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int tt = 1; 
    //cin >> tt;
    for (int test = 1; test <= tt; test++) {
        solve();
    }
 
    return 0;
}