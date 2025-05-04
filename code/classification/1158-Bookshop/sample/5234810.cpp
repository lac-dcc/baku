#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define TASK "name"
#define ll int
#define pii pair<ll,ll>
#define ff first
#define ss second
#define MAXN 1003
#define MAXK 100005
#define oo 1e18
#define pb push_back
using namespace std;
const ll MOD=1e9+7;
bool minimize (ll &a,ll b)
{
if (a>b)
{
    a=b;
    return true;
}
return false;
}
bool maximize (ll &a,ll b)
{
if (a<b)
{
    a=b;
    return true;
}
return false;
}
ll n,dp[MAXN+1][MAXK+1],k;
ll w[MAXN+1],p[MAXN+1];
void nhap()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen ("inp.inp","r",stdin);
    // freopen (TASK".inp","r",stdin);
    // freopen (TASK".out","w",stdout);
    cin >> n >> k;
    FOR(i,1,n) cin >> w[i];
    FOR(i,1,n) cin >> p[i];
}
void solve()
{
        FOR(i,1,n)
            FOR(j,1,k)
        {
            dp[i][j]=dp[i-1][j];
            if (j>=w[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+p[i]);
        }
        cout << dp[n][k];
            
}
int main(){
nhap();
solve();
return 0;
}