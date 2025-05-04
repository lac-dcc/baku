#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,arr[1000],dp[2000005],sm,diff;
    cin>>n>>sm;
    for(int i=0;i<=sm;i++)
    {
        dp[i]=1e15;
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        dp[arr[i]]=1;
    }
    for(int i=1;i<=sm;i++)
    {
        diff = 1e15;
        for(int j=0;j<n;j++)
        {
            if((i-arr[j])>=0)
            {
                dp[i] = min(dp[i],dp[i-arr[j]]+1);
            }
        }
    }
    if(dp[sm]>=1e15)
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<dp[sm]<<'\n';
    }
    return 0;
}