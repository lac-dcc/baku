#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//using namespace __gnu_pbds;
using namespace std;
 
#define ordered_set tree<ll , null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ll  long long
#define mod 1000000007
#define ve vector
#define pi pair<ll,ll>
#define pii pair<int,pair<int,int>>
#define pb push_back
#define F first
#define S second
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
const ll inf=1e16+5;
 
 
ll power(ll a,ll b,ll c)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
			res=(res*a)%c;
		a=(a*a)%c;
		b/=2;
	}
	return res;
}
 
 
 
void solve()
{ 
ll n,m,q,i,j,k;
    cin>>n>>m>>q;
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,inf));
    for(i=0;i<=n;i++)
        dp[i][i]=0;
    for(i=0;i<m;i++)
    {
     ll x,y,z;
        cin>>x>>y>>z;
        dp[x][y]=min(dp[x][y],z);
        dp[y][x]=min(dp[y][x],z);
    }
    
    for(k=1;k<=n;k++)   
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                ll dist=dp[i][k]+dp[k][j];
                if(dist<dp[i][j])dp[i][j]=dist;
            }
        }
    }
    while(q--)
    {
     ll x,y;
        cin>>x>>y;
        if(dp[x][y]==inf)cout<<-1<<endl;
        else cout<<dp[x][y]<<endl;
    }
}
 
signed main()
{
//#ifndef ONLINE_JUDGE
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
//#endif
    FAST;
   
    
     int t=1;
  //  cin>>t;
     while(t--)
    	solve();
    return 0;
}
 
