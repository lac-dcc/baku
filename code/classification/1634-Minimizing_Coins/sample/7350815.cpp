#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
long long minimumCoins(long long n, vector<long long>& coins) {
    vector<long long> dp(n + 1, n + 1);  // Initialize with a large value
    dp[0] = 0;
    
    for (long long i = 1; i <= n; ++i) {
        for (long long coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != n + 1) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[n] != n + 1 ? dp[n] : -1;
}
 
int main() {
    long long n, totalSum;
    cin >> n >> totalSum;
    
    vector<long long> coins(n);
    for (long long i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    
    long long result = minimumCoins(totalSum, coins);
    cout << result << endl;
    
    return 0;
}
