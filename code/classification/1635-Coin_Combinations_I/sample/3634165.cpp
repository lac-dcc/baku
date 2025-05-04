#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
//vector<vector<int>>dp(100,vector<int>(100000,-1));
int dp[1000001]={};
 
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef OJ
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    int n,s;
    cin>>n>>s;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int m=1e9+7;
    //sort(a.begin(),a.end(),greater<int>());
    dp[0]=1;
    for(int i=0;i<=s;i++)
    {
        for(int x:a)
        {
            if(x<=i)
                dp[i]=(dp[i]+dp[i-x])%m;
        }
    }
    cout<<dp[s]<<'\n';
    return 0;
}