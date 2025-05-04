#include <bits/stdc++.h>
 
using namespace std;
 
const int MN = 1e5 +10;
int dp[1005][MN];
int prices[1005], pages[1005];
 
 
int main(){
    int n,x; cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> prices[i];
    for(int i = 0; i < n; i++) cin >> pages[i];
    for(int i = 0; i < n; i++){
        dp[0][i] = 0;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if(j - prices[i-1] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-prices[i-1]] + pages[i-1]);
            }
        }
    }
    cout << dp[n][x];
 
 
 
 
 
}
