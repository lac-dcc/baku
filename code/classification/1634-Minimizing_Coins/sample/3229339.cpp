#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 +7;
 
int32_t main(){
    int n;
    cin>>n;
    int x;cin>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int dp[x+1];
    dp[0]=0;
    for(int i=1;i<=x;i++){
      dp[i] = INT_MAX;
    }
    for(int i=1;i<=x;i++){
        if(i<v[0]){dp[i]=-1;}
        else{
            for(int j=0;j<n;j++){
                if(v[j]<=i){
                   if(dp[i-v[j]]!=-1){dp[i]=min(dp[i-v[j]]+1,dp[i]);}
                }
                else{break;}
            }
            if(dp[i]==INT_MAX){dp[i]=-1;}
        } 
    }
     cout<<dp[x]<<endl;
 
 
 
 
 
 
 
 
    
    
    
}