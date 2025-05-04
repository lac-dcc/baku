#include<bits/stdc++.h>
using namespace std;
 
#define int long long
const int mod = 1e9 + 7;
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coin(n);
    for(int i = 0; i < n; i++)
        cin >> coin[i];
    sort(coin.begin(), coin.end());
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for(int pos = 0; pos < n; pos++) {
        for(int target = coin[pos]; target <= x; target++)
            dp[target] = (dp[target] + dp[target - coin[pos]]) % mod;
    }
    cout << dp[x];
}
 
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    solve();
    return 0;
}
