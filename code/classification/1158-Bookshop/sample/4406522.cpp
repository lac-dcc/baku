#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long int
#define printvec(v) for(auto x: v){std::cout<<x<<" ";}std::cout<<std::endl;
 
int MOD = 1000*1000*1000+7;
 
int main(){
    int n,x;
    std::cin>>n>>x;
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(x+1,0));
    std::vector<int> costs(n+1,0);
    std::vector<int> values(n+1,0);
    for(int i = 1; i <= n; ++i){
        std::cin>>costs[i];
    }
    for(int i = 1; i <= n; ++i){
        std::cin>>values[i];
    }
    for(int i = 1; i <= n; ++i){
        for(int k = 0; k<=x; ++k){
            dp[i][k]=std::max(dp[i-1][k],dp[i][k]);
            if(k>=costs[i]){
                dp[i][k]=std::max(dp[i-1][k-costs[i]]+values[i],dp[i][k]);
            }
        }
    }
    // for(auto x: dp){
    //     for(auto y: x){
    //         std::cout<<y<<" ";
    //     }
    //     std::cout<<std::endl;
    // }
    std::cout<<dp[n][x]<<std::endl;
}
