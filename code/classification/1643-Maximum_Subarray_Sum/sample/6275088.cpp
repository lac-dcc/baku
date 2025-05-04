#include<bits/stdc++.h>
using namespace std;
 
#define int long long
int32_t main() {
    int n;
    cin >> n;
    int arr[n];
    int dp[n];
    for(int i=0; i<n; i++) cin >> arr[i];
 
    dp[0] = arr[0];
 
    for(int i=0; i<n-1; i++) {
        dp[i+1] = max(dp[i] + arr[i+1], arr[i+1]);
    }
 
    int ans = LONG_LONG_MIN;
 
    for(int i=0; i<n; i++) {
        ans = max(ans, dp[i]);
    }
 
    cout << ans;
}
