#include <bits/stdc++.h>
 
using namespace std;
 
int n, x;
int mod = 1e9+7;
int coins[100];
int dp[1000001];
 
 
int main(){
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);
    sort(coins, coins+n);
    dp[0] = 1;
 
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= x; j++)
            dp[j] += dp[j-coins[i]], dp[j] -= (dp[j] >= mod ? mod : 0);
    printf("%d\n", dp[x]);   
}