#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
 
using namespace std;
 
int main() 
{
    ll n,i,j,x;
    cin >> n >> x;
    ll a[n];
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }
    ll dp[x+1];
    for(i=0; i<=x; i++)
    {
        dp[i]=LLONG_MAX;
    }
    dp[0]=0;
    for(i=1; i<=x; i++)
    {
        for(j=0; j<n; j++)
        {
            if((i-a[j])>=0 && (dp[i-a[j]]!=LLONG_MAX))
                dp[i]=min(dp[i],1+dp[i-a[j]]);
        }
    }
    if(dp[x]==LLONG_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << dp[x];
    }
}