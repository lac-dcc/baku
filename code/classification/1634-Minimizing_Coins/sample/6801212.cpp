#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int mod = 1e9+7;
vector<int> v ;
int t,n;
int dp[(int) 1e6+1];
 
int solve(  int sum){
    if(sum==t) return 0;
    if(sum>t) return 1e9;
    
    int ans= INT_MAX;
    if(dp[sum]!=-1) return dp[sum];
    for(int c:v){
        ans=  min(ans, 1+ solve(sum+c));
    }
    return dp[sum]= ans;
}
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("test_input.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // int n;
    cin>>n>>t;
    memset(dp,-1,sizeof(dp));
    // cout<<n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(), greater<int>());
    int x = solve(0);
    if(x>=1e9) cout<<-1;
    else cout<<x;
 
 
 
 
}
