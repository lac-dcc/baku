#include<bits/stdc++.h>
using namespace std;
#define all(x) sort((x).begin(),(x).end());
#define int long long 
#define pb push_back
#define vi vector<int>
#define MAX INT_MAX
#define MIN INT_MIN
#define MOD 1e9+7;
 
 
void solve(){
    string s1,s2; cin>>s1>>s2;
    int n=s1.length(),m=s2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
    }
    cout<<dp[n][m]<<endl;
}
 
 
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();}
}
 
