#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define int long long int
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>
#define setbits(x) __builtin_popcountll(x)
#define md (ll)1e9 + 7
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define f(i, j, n) for (ll i = j; i < n; i++)
#define r(i, j, n) for (ll i = n - 1; i >= j; i--)  
void solve()
{
    string s,r;
    cin>>s>>r;
    if(s.length()<r.length())
        swap(s,r);
    ll n=s.length(),m=r.length();
    ll dp[n+1][m+1];
    f(i,0,n+1)  f(j,0,m+1)  dp[i][j]=inf;
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
        if (i) 
	        dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
        if (j) 
	        dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
        if (i && j) 
	        dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(s[i-1] != r[j-1]));
    }
  }
  cout<<dp[n][m];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inpput.txt", "r", stdin); //freopen("op.txt", "w", stdout);
#endif
    ll test_cases = 1;
    //cin >> test_cases;
    for (ll t = 1; t <= test_cases; t++)
        solve(),cout<<"\n";;
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
