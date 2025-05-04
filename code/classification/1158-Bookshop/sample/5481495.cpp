#include <bits/stdc++.h>
using namespace std;
 
int dp[5][100005];
int precios[1005];
int paginas[1005];
int n, x;
 
/*int dp(int i, int j){
    if(i > n || j < 0) return 0;
 
    if(memo[i][j] == 0){
        if(j - precios[i] >= 0)
            memo[i][j] = max( dp(i + 1, j - precios[i]) + paginas[i], dp(i + 1, j) );
        else
            memo[i][j] = dp(i + 1, j);
    }
 
    return memo[i][j];
}*/
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> precios[i];
    for (int i = 1; i <= n; i++) cin >> paginas[i];
 
    for (int i = n; i >= 1; i--){
        for (int j = 1; j <= x; j++){
            if (j - precios[i] >= 0)
                dp[i % 2][j] = max(dp[(i + 1) % 2][j - precios[i]] + paginas[i], dp[(i + 1) % 2][j]);
            else
                dp[i % 2][j] = dp[(i + 1) % 2][j];
        }
    }
 
    cout << dp[1][x];
    //cout << dp(1, x);
    return 0;
}
