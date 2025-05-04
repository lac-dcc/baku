#include <bits/stdc++.h>
 
#define mod 1000000007
using namespace std;
 
 
int main(){
 
            int n, x; cin >> n >> x;
            vector<int> c(n);
            for(int i = 0 ; i < n ; i++) cin >> c[i];
 
            vector<vector<int>> dp(n+1, vector<int>(x + 1));
            for(int i = 0 ; i < n ; i++) dp[i][0] = 1;
 
            for(int i = n-1 ; i >= 0 ; i--){
                for(int j = 1 ; j <= x ; j++){
 
                    int a = dp[i+1][j];
                    int b = 0;
                    if(j >= c[i]) b = dp[i][j - c[i]];
                    dp[i][j] = (a + b)%mod;
 
                }
            }
 
            cout << dp[0][x];
 
return 0;
}
