#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
using namespace std;
int dp[100005];
void solve()
{
    int n,x,ans=0; cin>>n>>x;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=x;j>0;j--)
        {
            if(j-a[i]<0)continue;
            dp[j]=max(dp[j],b[i]+dp[j-a[i]]);
            ans=max(ans,dp[j]);
        }
    }
    cout<<ans;
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; t=1;
    while(t--)solve();
    return 0;
}