#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define inf (1LL<<61)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key 
const int MOD = 1000000007;
//const long long INF = 1e18;
 
/*int sum(int a, int b){
     int s = a+b;
     if(s >= mod) s -= mod;
     return s;
}
int sub(int a, int b){
     int s =a-b;
     if(s < 0){
          s += mod;
     }
     return s;
}
int mult(int a, int b){
     return (1LL*a*b)%mod;
}*/
// ll MOD = 1e9+7;
int n, x; vi arr;
ll solve(int x){
     vector<ll> dp(x+1, 0LL);
     dp[0] = 1LL;
for(int i=1; i <= x; i++){
     for(int coin: arr){
          if(i  >= coin){
               dp[i] += dp[i-coin];
          }
          if(dp[i] >= MOD){
               dp[i] -= MOD;
          }
     }
}
return dp[x];
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
  #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
  #endif
       cin>>n>>x;
       arr.resize(n);
       for(int &i: arr) cin>>i;
     cout << solve(x) << endl;
return 0;
}
