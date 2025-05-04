#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    //dp[i] = nr minim de monede pt a obtine i
    //dp[i] = min{1 + dp[i - coins[j], dp[i]}
    //dp[i - coins[j]], i - coins[j] < 0 -> return -1
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
        
    vector<int> dp(x + 1);
    
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        dp[i] = 1e9;
        for (auto &y : coins) {
            if (i - y >= 0)
                dp[i] = min(dp[i], dp[i - y] + 1);
        }
    }
    
    if (dp[x] == 1e9) {
        cout << -1 << '\n';
        return 0;
    }
    cout << dp[x] << '\n';
    return 0;
}
