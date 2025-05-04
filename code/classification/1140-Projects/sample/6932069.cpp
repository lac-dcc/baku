#include<bits/stdc++.h>
 
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define ss second
#define ff first
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
// #define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
//fn-> find_by_order(), order_of_key();
int n;
vector<vector<int>>p;
int lb(int vl){
   int i=0,j=p.size()-1;
   int ans=p.size();
   while(i<=j){
      int m=(i+j)/2;
      if(p[m][0]<=vl){
         i=m+1;
      }
      else{
         j=m-1;
         ans=m;
      }
   }
   return ans;
}
void solve(){
   cin>>n;
   p.resize(n);
   for(int i=0;i<n;i++){
      p[i].resize(3);
   }
   rep(i,n){
      cin>>p[i][0]>>p[i][1]>>p[i][2];
   }
   sort(p.begin(),p.end());
   long long dp[n+1];
   memset(dp,0,sizeof(dp));
   for(int i=n-1;i>=0;i--){
      int ind=lb(p[i][1]);
      dp[i]=max(dp[i],p[i][2]+dp[ind]);
      dp[i]=max(dp[i],dp[i+1]);
   }
   cout<<dp[0]<<endl;
}
int main(){
    IOS
   int t=1;
   //cin>>t;
   while(t--){
      solve();
   }
    return 0;
}
