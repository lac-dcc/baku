#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1000000000
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, sum;
    cin>>n>>sum;
    vector<int> coins(n), dp(sum);
    for(int i = 0; i < n; i++) {
        cin>>coins[i];
    }
    for(int i = 1; i <= sum; i++) {
        dp[i] = INF;
        for(int coin:coins) {
            if(i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    if(dp[sum] != INF) {
        cout<<dp[sum]<<endl;
    }
    else {
        cout<<-1<<endl;
    }
 
    return 0;
}