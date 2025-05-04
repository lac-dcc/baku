#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int coins[n];
    int dp[x+1];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    dp[0]=0;
    for(int i=1;i<=x;i++){
        dp[i]=1e9;
        for(int j:coins){
            if((i-j)>=0){
                dp[i]=min(dp[i],dp[i-j]+1);
            }
        }
    }
    if(dp[x]==1e9){
        cout<<-1;
        return 0;
    }
    cout<<dp[x];
}