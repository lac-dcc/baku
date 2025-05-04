// #include<bits/stdc++.h>
// #define int long long int
// #define pb push_back
// #define rep(i,j,n) for(int i=j;i<n;i++)
// #define mod 1000000007
// #define endl '\n'
// using namespace std;
 
// //.........................................................................................................
// int phi(int n){int result = n;for(int i=2;i*i<=n;i++){if(n%i == 0){while(n%i == 0){n/=i;}result-= result/i;}}if(n > 1){result-=result/n;}return result;}
// int expo(int a,int b){int ans = 1;while(b>0){if(b&1){ans = ans*a%mod;}a = a*a%mod;b >>= 1;}return ans;}
// vector<int> factor(int n){vector<int>ans;for(int i=2;i*i<=n;i++){if(n%i == 0){while(n%i == 0){ans.pb(i);n/=i;}}}if(n > 1){ans.pb(n);}return ans;}
// vector<bool> primes(int n){vector<bool>ans(n+1,true);ans[0] = ans[1] = false;for(int i=2;i<n;i++){if(ans[i]){for(int j=i*i;j<n;j+=i){ans[j] = false;}}}return ans;}
// bool perfect_sqrt(int n){double ans = sqrt(n);if(ans == (int)sqrt(n)){return true;}return false;}
// int lcm(int a,int b){return a/__gcd(a,b)*b;}
// //.........................................................................................................
 
// void solve()
// {
//   int n,x;
//   cin>>n>>x;
 
//   vector<int>arr(n+1);
//   rep(i,1,n+1)
//   {
//     cin>>arr[i];
//   }
  
//   vector<int>ans(x+1,0);
 
//   ans[0] = 1;
//   for (int i = 1; i <= n; i++)
//   {
//     for (int weight = 0; weight <= x; weight++)
//     {
//       if(weight - arr[i - 1] >= 0)
//       {  // prevent out of bounds cases
//         ans[weight] += ans[weight - arr[i - 1]];
//         ans[weight] %= mod;
//       }
//     }
//   }
//   cout << ans[x] << '\n';
 
 
// }
 
// signed main()
// {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
 
//   //int t;
//   //cin>>t;
 
//   //while(t--)
//   solve();
 
//   return 0;
// } 
 
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int mod = 1e9 + 7;
    int n, target;
    cin >> n >> target;
    vector<int> coins(n + 1);
    for (int i = 1;i <= n;i++)
        cin >> coins[i];
 
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            int left = j - coins[i];
            if (left >= 0) {
                (dp[i][j] += dp[i][left]) %= mod;
            }
        }
    }
    //dp[i][j]= what are no ways to form sum j using starting [0..i]
    cout << dp[n][target] << endl;
}
