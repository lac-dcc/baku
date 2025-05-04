#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> h(n);
    vector<int> s(n);
    for(int& v:h)cin>>v;
    for(int& v:s)cin>>v;
    int dp[x+1];
    memset(dp,0,sizeof(dp));
   for(int j=0;j<n;j++){
       for(int i=x;i>=0;i--) {
            if(i-h[j]>=0)
            dp[i]=max(dp[i-h[j]]+s[j],dp[i]);
        }
    }
    cout<<dp[x]<<endl;
 
}