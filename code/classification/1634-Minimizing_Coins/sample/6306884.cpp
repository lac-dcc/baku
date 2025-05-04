#include <iostream>
#include <vector>
#include <climits>
 
int minimumCoins(int n, int x, std::vector<int>& coins) {
    std::vector<int> dp(x + 1, INT_MAX); // 初始化dp数组
    dp[0] = 0; // 组成金额为0时，不需要硬币
 
    for (int i = 1; i <= x; ++i) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX && dp[i - coin] + 1 < dp[i]) {
                dp[i] = dp[i - coin] + 1;
            }
        }
    }
 
    if (dp[x] == INT_MAX) {
        return -1; // 无法组成总额为x的金额
    } else {
        return dp[x];
    }
}
 
int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }
 
    int result = minimumCoins(n, x, coins);
    std::cout << result << std::endl;
 
    return 0;
}
