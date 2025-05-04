#include <bits/stdc++.h> 
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 
 
int main()
{
    fast_io;
 
    ll n,x;
    ll mod = 1e9+7;
    cin>>n>>x;
 
    vector <ll> coin(n);
    for(ll&i : coin)
    cin>>i;
 
    vector <ll> dp(x+1,0);
    dp[0] = 1; 
    
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<=x;j++)
        {
            if(j-coin[i] >= 0)
            {
            dp[j] += dp[j-coin[i]];
            dp[j] %= mod;
            }
        }
    }
    cout<<dp[x]<<endl;
 
    return 0;
}
