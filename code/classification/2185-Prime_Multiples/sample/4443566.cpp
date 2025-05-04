#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+7;
const ll MOD=1e9+7;
ll m,a[N],kq,dp[N],ans,n;
bool ok;
void sub_lauaj()
{
    kq=0;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if (i%a[j]==0) {kq++;break;}
    cout<<kq;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n;ok=true;
    if (m<=N) {sub_lauaj();return 0;}
    memset(dp,0,sizeof dp);
    for (int i=1;i<=n;i++) {cin>>a[i];if (a[i]==1) ok=false;}
    if (ok==false) {cout<<m;return 0;}
    for (int msk=1; msk<(1<<n); ++msk) {
        ans = m; int bits = 0;
        for (int i=0; i<n; ++i)
        if (msk & (1<<i)) {
            ++bits;
            ans=1LL*(ans/(1LL*a[i+1]));
        }
        dp[bits]+=1LL*ans;
    }kq=0;
        for (int i=1;i<=n;i++){
            kq+=1LL*(i&1?1:-1)*dp[i];//cout<<dp[i]<<'\n';
            }
        cout<<kq;
    return 0;
}