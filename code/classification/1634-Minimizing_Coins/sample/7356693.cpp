#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, x; 
    cin>>n>>x;
    vector<int> coins(n,0);
    vector<int>dp(x+1,1e9);
    for(int i = 0;i<n;i++){
        int y;
        cin>> y;
        coins[i] =y;
        if(coins[i]<x+1){
            dp[coins[i]] =1;
        }
    }
    for(int i =1 ; i<x+1;i++){
        for(int j = 0; j<n;j++){
            if(i>=coins[j]){
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    if(dp[x] == 1e9){
        cout<< -1;
        return 0;
    }
    cout<< dp[x];
    return 0;
    
    
}
    // int n;
    // cin >> n ; 
    // int x;
    // cin>>x;
    // vector<long long> c(n,0);
    // vector<long long> dp(x+1,4e18);
    // for(int i= 0; i<n; i++){
    //     int y;
    //     cin>>y;
    //     // cout<<y<<endl;
    //     if(y<=x){
    //         dp[y] = 1;
    //     }
    //     c[i] = y;
    // }
    // dp[0]=1;
    // for(int i=1; i<x+1;i++){
    //     for(int j=0; j<n;j++){
    //         if(i>=c[j]){
    //             dp[i] = min(dp[i], dp[i-c[j]]+1);
    //         }
    //     }
    // }
    // if(dp[x]==4e18)
    // {
    //     dp[x]=-1;
    // }
    // cout<< dp[x];
 
    // return 0;
