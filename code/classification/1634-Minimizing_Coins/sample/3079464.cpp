#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,s;
    cin>>n>>s;
    vector<int>coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];
    
    vector<int>dp(s+1,INT_MAX-1);
    dp[0]=0;
    for(int i=1;i<s+1;i++){
        for(int j=0;j<n;j++){
            if(coins[j]>i)continue;
            dp[i]=min(dp[i],dp[i-coins[j]]+1);
        }
    }
	if(dp[s]==INT_MAX-1)cout<<-1<<endl;
    else cout<<dp[s]<<endl;
	
    return 0;
}