#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];
    vector<int> dp(x + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = x - prices[i]; j >= 0; j--) {
            if (dp[j] == -1) continue;
            dp[j + prices[i]] = max(dp[j + prices[i]], dp[j] + pages[i]);
        }
    }
    for (int i = 0; i <= x; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
