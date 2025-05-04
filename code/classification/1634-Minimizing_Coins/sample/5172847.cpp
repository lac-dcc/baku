#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 542
#endif
#define all(v) v.begin(),v.end()
#define int long long int
#define endl "\n"
using namespace std;
int cases();
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    clock_t z = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin );
    freopen("output.txt", "w", stdout);
    freopen("error.txt" , "w", stderr);
#endif
    int T = 1;
    //cin >> T;
    while (T--)
    {
        cases();
#ifndef ONLINE_JUDGE
cout << "____________________________________\n";
#endif
    }
    cerr << "Run time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
}
int solvetab(int n,vector<int>&v)
{
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(auto x:v)
        {
            if(i-x>=0 && dp[i-x]!=INT_MAX)
                dp[i]=min(dp[i],1+dp[i-x]);
        }
    }
    if(dp[n]==INT_MAX)return -1;
    return dp[n];
}
int cases()
{
    int n,x,cnt=0;
    cin>>n>>x;
    vector<int> v(n);
    for (int &val : v)
    {
        cin >> val;
    }
    cout<<solvetab(x,v)<<endl;
    return 0;
}
