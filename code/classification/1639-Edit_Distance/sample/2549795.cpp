#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define fill0(dp) memset(dp,0,sizeof(dp))
#define fill(dp) memset(dp,-1,sizeof(dp))
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 
string a,b;
int n,m;
vector<vector<int>>dp;
 
int f(int i,int j)
{
    if(i<0 and j<0) return 0;
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]) return dp[i][j] = f(i-1,j-1);
    int f1 = 1+f(i-1,j),f2=1+f(i,j-1),f3=1+f(i-1,j-1);
    return dp[i][j] = min({f1,f2,f3});
}
 
void solve()
{
    cin>>a>>b;
    n=sz(a);m=sz(b);
    dp.assign(n+1,vector<int>(m+1,-1));
    cout<<f(n-1,m-1);
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}
