#include "bits/stdc++.h"
using namespace std;
// const int mod = 1e9 + 7;
// #define int long long
// #define endl '\n'
// void fastIO(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// }
 
// int func_fact(int x, vector<int> &dp_fact){
//     if(x == 0) return 1;
//     if(dp_fact[x] != -1) return dp_fact[x];
//     return dp_fact[x] = (x%mod * 1LL * func_fact(x-1,dp_fact)%mod)%mod;
// }
 
// vector<int> factorial(){
//     vector<int> fact(10000010,0);
//     vector<int> dp_fact(10000010,-1);
//     for(int i = 0; i<10000010; i++){
//         fact[i] = func_fact(i,dp_fact)%mod;
//     }
//     return fact;
// }
 
// int binary_exponentiation(int a, int b){
//     if(b == 0) return 1;
//     int ans = 1;
//     while(b){
//         if(b&1)
//             ans = (ans%mod * 1LL * a%mod)%mod;
//         a = (a%mod * 1LL * a%mod)%mod;
//         b = b>>1;
//     }
//     return ans%mod;
// }
 
// int n_c_r(int a, int b){
//     vector<int> fact = factorial();
//     return (fact[a]%mod * 1LL * binary_exponentiation(fact[b],mod-2)%mod * 1LL * binary_exponentiation(fact[a-b],mod-2)%mod)%mod;
// }
 
// vector<bool> prime_valid(){
//     vector<bool> isPrime(10000010,1);
//     isPrime[0] = isPrime[1] = 0;
//     for(int i = 2; i*i <= 10000010; i++){
//         if(isPrime[i]){
//             for(int j = 2*i; j<=10000010; j = j+i){
//                 isPrime[j] = 0;
//             }
//         }
//     }
//     return isPrime;
// }
 
// vector<int> give_divisors(int x){
//     vector<int> ans;
//     for(int i = 1; i*i<=x; i++){
//         if(x%i == 0){
//             ans.push_back(i);
//             if(x/i != i) ans.push_back(x/i);
//         }
//     }
//     return ans;
// }
 
// vector<int> sieve(){
//     vector<int> smallest_prime(10000010,1);
//     smallest_prime[0] = 0;
//     smallest_prime[1] = 1;
//     for(int i = 2; i<=10000010; i++){
//         if(smallest_prime[i] == 1){
//             smallest_prime[i] = i;
//             for(int j = 2*i; j<=10000010;j = j+i){
//                 if(smallest_prime[j] == 1)
//                 smallest_prime[j] = i;
//             }
//         }
//     }
//     return smallest_prime;
// }
 
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 
void solve(){
    
    int n,x;
    cin>>n>>x;
    int price[n+1];
    int pages[n+1];
    int dp[n+1][x+1];
    for(int i = 0; i<(n+1); i++){
        for(int j = 0; j<(x+1); j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i<=n; i++) cin>>price[i];
    for(int i = 1; i<=n; i++) cin>>pages[i];
    // dp[i][j] --> maximum no of pages that can be read till i index having j rupees
    // [.......]
    // dp[i][j] : op1 = dp[i-1][j] --> this is the max pages we can read till i-1 with j rupees since we are not selecting i index
    // base case: dp[0][1.2.3.4.] = 0 but as we are taking 1 based indexing so this case will automatically eliminate
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=x; j++){
            if(i == 1) dp[i][j] = price[i] <= j ? pages[i] : 0;
            if(i == 1) continue;
            dp[i][j] = dp[i-1][j];
            dp[i][j] = max(dp[i][j], j - price[i] >= 0 ? dp[i-1][j-price[i]] + pages[i] : 0);
        }
    }
    cout<<dp[n][x];
}
 
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 
signed main(){
    // fastIO();
    int t;
    t = 1;
    // cin>>t;
    while(t--)
        solve();
}