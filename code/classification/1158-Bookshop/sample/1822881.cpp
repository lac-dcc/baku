//   PIGMEISTER™   //
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll int
#define ld long double
#define sidha(i,x,n) for(ll i=(ll)(x);i<(ll)(n);++i)
#define ulta(i,x,n) for(ll i=(ll)(x);i>=(ll)(n);--i)
#define sab(a) a.begin(),a.end()
#define bas(a) a.rbegin(),a.rend()
#define test ll _;cin>>_;while(_--)
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//#define MAX 100005
#define PI (ld)3.141592653589793238
//#define MOD LLONG_MAX
#define MOD (ll)1000000007
//#define MOD (ll)998244353
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    jaldi;
    
    ll n, x;
    cin >> n >> x;
    ll pr[n], pg[n];
    sidha (i, 0, n) cin >> pr[i];
    sidha (i, 0, n) cin >> pg[i];
 
    ll dp[n+1][x+1];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    sidha (i, 1, n+1) {
        sidha (j, 0, x+1) {
            if (dp[i-1][j] == -1) continue;
            if (j+pr[i-1] <= x) dp[i][j+pr[i-1]] = max(dp[i][j+pr[i-1]],
                                                    dp[i-1][j]+pg[i-1]);
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
 
    ll ans = 0;
    sidha (i, 0, x+1) ans = max(ans, dp[n][i]);
 
    cout << ans;
    
    return 0;
}
