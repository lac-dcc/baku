/*
 
Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.
 
- Tooru Oikawa.
 
*/
 
#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using namespace std;
#define ld long double
#define ll long long int
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define vv vector<ll>
#define ve vector
#define pll pair<ll,ll>
#define pa pair
#define fr(i, a, b) for (ll i = a; i < b; ++i)
#define frn(i, a, b) for (ll i = a; i > b; --i)
#define MAX 100005
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MOD 1000000009
#define endl "\n"
#define inarr(arr,n); for(int i=0;i<n;i++) cin >> arr[i];
#define outarr(arr,n); for(int i=0;i<n;i++) cout<<arr[i]<<' ';
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz(a) (int)((a).size())
#define deci fixed<<setprecision(9)
const ll inf = 9e18;
const ld pi = 2*acos(0.0);
 
ll c[MAX];
 
void solve()
{
    ll n,x;
    cin>>n>>x;
    vv dp(MAX*30LL,inf);
    inarr(c,n);
    dp[0] = 0LL;
    fr(i,0,x+1)
    {
        fr(j,0,n)
        {
            if(dp[i]!=inf)dp[i+c[j]] = min(dp[i+c[j]],dp[i]+1);
        }
    }
    cout<<(dp[x]==inf?-1LL:dp[x])<<endl;
    return;
}
 
 
 
 
 
 
int main()
{
    IOS;
    ll tc=1;
//    cin>>tc;
    while(tc--)
    {
        solve();
    }
}
