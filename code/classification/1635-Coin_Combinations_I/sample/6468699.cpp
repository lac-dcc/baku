#include "bits/stdc++.h"
using namespace std;
 
const int mxn = 1e6 + 10;
const int mod = 1e9 + 7;
typedef long long ll;
 
ll dp[mxn+1],c[mxn+1]; 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,x; cin>>n>>x;
 
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
 
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i - c[j] >= 0){
                dp[i] += dp[i - c[j]];
                dp[i] %= mod;
            }
        }
    }
     
    cout<<dp[x]<<'\n'; 
 
}