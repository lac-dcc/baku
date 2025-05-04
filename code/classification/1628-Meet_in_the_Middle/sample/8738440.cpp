#include<bits/stdc++.h>
#define fo(i,x,n) for(int i=x;i<=n;++i)
#define fi(i,x,n) for(int i=x;i>=n;--i)
#define ll long long
#define SYNCHRONIZE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define nmax 5005
using namespace std;
ll n, x, a[nmax], b[nmax];
vector<ll> dp, f;
int main()
{
    cin>>n>>x;
    for(int i = 0; i < n / 2; i++) cin>>a[i];
    for(int i = 0; i < n / 2 + n % 2; i++) cin>>b[i];
    ll tmp = n / 2;
    for(int mark = 0; mark < (1 << tmp); mark++)
    {
        ll kq = 0;
        for(int i = 0; i < tmp; i++)
            if(mark & (1 << i)) kq += a[i];
        dp.push_back(kq);
    }
    for(int mark = 0; mark < (1 << tmp + (n % 2)); mark++)
    {
        ll kq = 0;
        for(int i = 0; i < tmp + n % 2; i++)
            if(mark & (1 << i)) kq += b[i];
        f.push_back(kq);
    }
    sort(dp.begin(), dp.end(), greater<ll>());
    sort(f.begin(), f.end());
    ll ans = 0;
    for(int i = 0, j1 = 0, j2 = 0; i < dp.size(); ++i)
    {
      ll s = x - dp[i];
      while (j1 < f.size() && f[j1] < s) ++j1;
      while (j2 < f.size() && f[j2] <= s) ++j2;
      ans += j2 - j1;
    }
    cout<<ans;
 
}
