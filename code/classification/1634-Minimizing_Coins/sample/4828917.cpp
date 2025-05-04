#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
int Min(int arr[], int n, int sum){
    int dp[n+1][sum+1];
    for(int i = 0; i<=sum; ++i) dp[0][i] = INT_MAX-1;
    for(int i = 0; i<=n; ++i) dp[i][0] = 0;
    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=sum; ++j){
            if(arr[i-1]<=j){
                dp[i][j] = min(dp[i-1][j], 1+dp[i][j-arr[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(dp[n][sum]==INT_MAX-1) return -1;
    else return dp[n][sum];
}
void solve()
{
    int n, sum;
    cin>>n>>sum;
    int arr[n];
    for(int i = 0; i<n; ++i) cin>>arr[i];
    int ans = Min(arr, n, sum);
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
 
        solve();
    }
 
    return 0;
}
