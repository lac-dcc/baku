#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
 
int t;
t=1;
 
while(t--){
    int n,x;
    cin>>n>>x;
    vector<int> coins;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        coins.push_back(c);
 
    }
    sort(coins.begin(),coins.end());
    vector<ll> dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<coins.size();j++){
            int k=i-coins[j];
            if(k>=0){
                dp[i]=min(dp[i],dp[k]+1);
            }
            else{
                break;
            }
        }
        //cout<<dp[i]<<" ";
    }
    //cout<<endl;
    if(dp[x]==INT_MAX){
        dp[x]=-1;
    }
    cout<<dp[x]<<endl;
}
return 0;
}
