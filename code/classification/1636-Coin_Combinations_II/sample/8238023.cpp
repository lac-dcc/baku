# include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
using namespace std;
 
 
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   int n,x;
   cin>>n>>x;
   int a[n];
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   vector<int> dp(x+1,0);
   dp[0]=1;
   for (int j=0;j<n;j++){
       for (int i=0;i<=x;i++ ){
           if (a[j]<=i){
               dp[i]+=dp[i-a[j]];
               dp[i]%=mod;
           }
       }
   }
 
   cout<<dp[x];
 
}
