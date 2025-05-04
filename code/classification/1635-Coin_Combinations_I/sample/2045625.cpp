#include<bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define inf (1LL<<60)
#define endl "\n"
const int N = 1e6 + 1;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
 
void solve()
{
    int n, target;
    cin >> n >> target;
    vector<int> dp(target + 1), arr(N);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int j = 1; j <= target; j++) {
        for (int i = 0; i < n; i++) {
 
            if (arr[i] <= j) {
                dp[j] += dp[j - arr[i]];
                dp[j] = dp[j] % mod;
            }
        }
    }
    cout << dp[target] % mod << endl;
 
}
 
 
void init_code()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
 
 
 
signed main()
{
    init_code();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}