#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
 
void solve() {
   int n,m;
   cin>>n>>m;
   vector<int>value(n);
   vector<int>page(n);
   for(int i=0;i<n;i++){
    cin>>value[i];
   }
   for(int j=0;j<n;j++){
    cin>>page[j];
   }
 
 
   /* tabulation without space optimization */
 
   /*vector<vector<int>>dp(n+1,vector<int>(m+1));
   for(int i=0;i<=m;i++){
    if(i>=value[0]){
        dp[0][i]=page[0];
    }
   }
   for(int i=1;i<n;i++){
    for(int val=0;val<=m;val++){
        int op1=0,op2=0;
       if(val>=value[i]){
          op1=page[i]+dp[i-1][val-value[i]];// include ith book 
       }
       
        op2=dp[i-1][val];// excluding ith book
       
       dp[i][val]=max(op1,op2);
    }
   }
        */
 
   /* tabulation with space optimization */
   vector<int>curr(m+1);
   vector<int>prev(m+1);
   for(int i=0;i<=m;i++){
    if(i>=value[0]){
        prev[i]=page[0];
    }
   }
   for(int i=1;i<n;i++){
    for(int val=0;val<=m;val++){
        int op1=0,op2=0;
       if(val>=value[i]){
          op1=page[i]+prev[val-value[i]];// include ith book 
       }
       
        op2=prev[val];// excluding ith book
       
       curr[val]=max(op1,op2);
    }
    prev=curr;
   }
   cout<<prev[m];
 
 
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
