#include<stdio.h>
using namespace std;
#include<bits/stdc++.h>
int main(){
int n,x;
cin>>n>>x;
vector<int> c;
int mod=1e9+7;
 
for(int i=0;i<n;i++)
{
    int f;
    cin>>f;
    c.push_back(f);
}
sort(c.begin(),c.end());
vector< vector<int> > dp(n,vector<int>(x+1,0));
for(int i=0;i<=x;i++){
    if(!(i%c[0])) dp[0][i]=1;
}
for(int i=0;i<n;i++){
    dp[i][0]=1;
}
 
for(int i=1;i<n;i++){
    for(int j=1;j<=x;j++){
        if(c[i]>j) dp[i][j]=dp[i-1][j];
        else dp[i][j]=dp[i-1][j]%mod+dp[i][j-c[i]]%mod;
        dp[i][j]=dp[i][j]%mod;
    }
}
cout<<dp[n-1][x];
 
    return 0;
}
