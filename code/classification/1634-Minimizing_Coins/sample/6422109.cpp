#include<bits/stdc++.h>
using namespace std;
long long n,x;
 
long long help(vector<long long>& dp,vector<long long>& nums,long long ind){
    if(ind==0)return 0;
    if(dp[ind]!=0)return dp[ind];
    long long t=INT_MAX;
    for(int k=0;k<n;++k){
        if(ind-nums[k]>=0){
            t=min(help(dp,nums,ind-nums[k])+1,t);
        }
    }
    return dp[ind]=t;
}
int main(){
    cin>>n>>x;
    vector<long long> dp(x+1,0),nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    int m=help(dp,nums,x);
    if(m>=INT_MAX)cout<<-1<<endl;
    else cout<<m<<endl;
    return 0;
}
