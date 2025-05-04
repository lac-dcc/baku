#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};
const int inf = 1e9+7, N = 105,MX = 1e6+5, mod=1e9+7;
int n,ar[N],target;
int dp[MX];
int f(int sum){
     if(sum > target ) return 0;
     if(sum == target) return 1;
     if(dp[sum] != -1) return dp[sum];
     int ans = 0;
     for(int i = 1; i <= n; i++){
          ans += f(sum+ar[i]);
          ans = ans % mod;
     }
     return dp[sum] = ans;
}
void solve(){
 cin >> n >> target;
for(int i = 1; i <= n; i++) cin >> ar[i];
memset(dp,-1,sizeof dp);
cout << f(0) << endl;
   
}
int main(){
ios::sync_with_stdio(false);cin.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin); 
freopen("output.txt","w",stdout); 
#endif
int t=1;//cin >> t;
while(t--){
     solve();
}
     
     return 0;
 
}
