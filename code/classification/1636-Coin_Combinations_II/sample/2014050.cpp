#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 
int main(){
    // code here
    ll  n,x;
    cin  >> n >> x;
    std::vector<ll> ar(n);
    for(ll i=0; i<n; i++) cin >> ar[i];
    std::vector<ll> dp(x+1,0);
    dp[0] = 1;
    //dp[1]=1;
    for(ll i=0; i<n; i++){
        for(ll j=1; j<=x; j++ ){
            if(ar[i]>j) continue;
            dp[j] = (dp[j] + (dp[j - ar[i]]))%mod;
        }
    }
    cout<<dp[x];
        
    return 0;
}