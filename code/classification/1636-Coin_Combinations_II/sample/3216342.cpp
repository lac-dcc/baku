#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int coins[100];
// dp[i][j] := cantidad de formas de obtener la suma j
//             usando las primeras i monedas (ordenadas
//             ascendentemente)
int dp[1000001];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x, i, j, res;
    cin >> n >> x;
    for (i = 0; i < n; ++i)
        cin >> coins[i];
    sort(coins, coins+n);
 
    dp[0] = 1;
    for (j = 1; j <= x; ++j)
        dp[j] = 0;
 
    for (i = 0; i < n; ++i) {
        for (j = 1; j <= x; ++j) {
            res = j - coins[i];
            if (res >= 0) {
                dp[j] += dp[res];
                if (dp[j] >= MOD)
                    dp[j] -= MOD;
            }
        }
    }
    
    cout << dp[x] << '\n';
    return 0;
}
 
