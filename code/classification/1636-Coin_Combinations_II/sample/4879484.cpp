#include<iostream>
#include<vector>
using namespace std;
 
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n+1);
    for(int i= 1;i<n+1;i++){
        cin >> coins[i];
    }
            
    int dp[n+1][x+1];
    
    int mod = 1e9+7;
 
    for(int i = 1; i<= n;i++){
        for(int sum = 0; sum <= x;sum ++){
            if(sum == 0){
                dp[i][sum] = 1;
            }else{
                int op1 = (coins[i] > sum ) ? 0: dp[i][sum - coins[i]];
                int op2 = (i==1) ? 0 : dp[i-1][sum];
                dp[i][sum] = (op1+ op2) % mod;
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}
