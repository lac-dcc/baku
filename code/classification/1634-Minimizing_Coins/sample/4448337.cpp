#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n, x;
    cin >> n >> x;
 
    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
 
    int dp[x+1];
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        dp[i] = MOD;
    }
    for (int i = 1; i <= x; i++) {
        for (int x : coins) {
            if (x <= i) {
                dp[i] = min(dp[i], dp[i-x] + 1);
            }
        }
    }
 
    if (dp[x] == MOD) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }
 
    return 0;
}
