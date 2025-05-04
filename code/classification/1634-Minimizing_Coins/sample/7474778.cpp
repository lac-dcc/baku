// Tabulation
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,s; cin >> n >> s;
//     vector<int> coins(n);
//     for(auto &temp:coins) cin >> temp;
//     vector<int> dp(s+1,1e9);
//     dp[0] = 0;
//     for(int i{1};i<=s;i++){
//         for(int j{};j<n;j++){
//             if(i >= coins[j] && dp[i-coins[j]] != 1e9){
//                 dp[i] = min(dp[i], 1+dp[i-coins[j]]);
//             }
//         }
//     }
//     cout << (dp[s] == 1e9 ? -1 : dp[s]) << "\n";
//     return 0;
// }
 
// Memoization
#include <bits/stdc++.h>
using namespace std;
int X(int n,int s,vector<int> &coins,vector<int> &dp){
    if(s == 0) return 0;
    if(s < 0) return -1;
    if(dp[s] != -1) return dp[s];
    int ans = 1e9;
    for(int i{};i<n;i++){
        if(s >= coins[i]){
            int temp = X(n,s-coins[i],coins,dp);
            if(temp != 1e9)
                ans = min(ans, 1+temp);
        }
    }
    return dp[s] = ans;
}
int main()
{
    int n,s; cin >> n >> s;
    vector<int> coins(n);
    for(auto &temp:coins) cin >> temp;
    vector<int> dp(s+1,-1);
    int ans = X(n,s,coins,dp);
    cout << (ans == 1e9 ? -1 : ans) << "\n";
    return 0;
}
