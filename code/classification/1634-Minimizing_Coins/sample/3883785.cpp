#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,x,i;
    cin>>n>>x;
    vector<ll>coins(n);
    for(i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    sort(coins.begin(),coins.end());
    vector<ll>dp(x+1,0);
    dp[0]=0;
    for(i=1;i<=x;i++)
    {
        ll minimum=LONG_LONG_MAX;
        bool q=false;
        for(ll j=0;j<n;j++)
        {
            if(i>=coins[j])
            {
                if(dp[i-coins[j]]!=-1)
                {
                    minimum=min(minimum,dp[i-coins[j]]);
                    q=true;
                }
            }
            else
            {
                break;
            }
        }
        if(q)
        {
            dp[i]=1+minimum;
        }
        else{
            dp[i]=-1;
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}