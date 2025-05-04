#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, x;
    cin >> n >> x;
    int dp[x + 1], arr[n], mod = 1e9 + 7;
    for(int i = 0;i < n; i++)
        cin >> arr[i];
    for(int i = 0;i <= x;i++)
        dp[i] = 0;
    dp[0] = 1;
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= x; i++) {
            if (i - arr[j] >= 0){
                dp[i] += dp[i - arr[j]];
                dp[i] %= mod;
            }
        }
    }
 
    cout<< dp[x] << endl;
    return 0;
}