#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
int MOD = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
 
    // start!
    int n, x;
    cin >> n >> x;
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> dp(x+1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = x; j > 0 ; j--) {
            if (j - h[i] >= 0 and (dp[j-h[i]] + s[i]) > dp[j]) {
                dp[j] = dp[j] = max(dp[j], dp[j-h[i]] + s[i]);
            }
        }
    }
    cout << dp[x];
    return 0;
}
