#include<iostream>
#include<bits/stdc++.h>
#include<set>
#include<vector>
#include<unordered_map>
#define ll long long
#define mod (int)1e9+7 
using namespace std;
   int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int n,k;
     cin>>n>>k;
     int a[n];
     for(int i=0;i<n;i++)
     	cin>>a[i];
    vector<ll> dp(k+1,0);
     
     dp[0]=1;
     for(int i=0;i<n;i++){
     	for(int j=1;j<=k;j++){
     		if(a[i]<=j)
     		dp[j]+=dp[j-a[i]];
     	dp[j]%=mod;
     	}
     }
   
     
     cout<<dp[k]<<endl;
    
   return 0;
}