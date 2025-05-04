#include <bits/stdc++.h>
using namespace std;
#define int long long
const string pi = "314159265358979323846264338327950288419716939937510";
int mod = 1000000007;
// int binpow(int a, int b)
// {
//     int res = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//             res = res * a;
//         a = a * a;
//         b >>= 1;
//     }
//     return res;
// }
// // n^x %m
int fastpow(int n, int x, int m)
{
    int ret = 1;
    while (x)
    {
        if (x & 1)
            (ret *= n) %= m;
        x >>= 1;
        (n *= n) %= m;
    }
    return ret;
}
// // a/b % mod = a*b^-1 % mod where b^-1 = b^(m-2)%m
// //  eg:
// //  int pp = fastpow(n, mod-2, mod);
// //  int ans = pp*binpow(2, n);
 
 
///////////////////////////////////////////////////////////////////////
 
int N = 1e7;
 
void solve()
{
    string s,t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = INT_MAX;
        }
    }
    dp[0][0] = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i!=0){
                dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            }
            if(j!=0){
                dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            }
            if(i!=0 && j!=0){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }else{
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
    }
    cout<<dp[n][m]<<endl;
 
}       
 
int32_t main()
{
    int l;
    //cin >> l;
    l=1;
    while (l--)  
    {
    solve();
    }
}
