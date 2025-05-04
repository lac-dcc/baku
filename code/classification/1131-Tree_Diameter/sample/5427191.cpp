#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<ll,ll>> pii;
#define pb push_back
#define rep(i,a,b) for(int i = a; i < b; i++)
#define all(x) x.begin(),x.end()
const ll mod = 2e5+5; 
 
/**double findSqrt(double x)
{
    if (x < 2)
    return x;
    double y = x;
    double z = (y + (x / y)) / 2;
    while (abs(y - z) >= 0.00001) {
        y = z;
        z = (y + (x / y)) / 2;
    }
    return z;
}**/
 
ll height[mod];
ll visited[mod];
ll dp[mod][2];
void dfs(ll n, vector<ll> v[])
{
	visited[n]=1;
	dp[n][0]=dp[n][1]=0;
	bool flag=1;
	for(int i=0; i<v[n].size(); i++)
	{
		if(visited[v[n][i]]==1) continue;
		flag=0;
		dfs(v[n][i],v);
	}
	if(flag==1) return;
	for(int i=0; i<v[n].size(); i++)
	{
		dp[n][0]=max(dp[n][0],dp[v[n][i]][0]);
	}	
	dp[n][0]++;
	ll l1=0,l2=0;
	for(int i=0; i<v[n].size(); i++)
	{
		if(dp[v[n][i]][0]>=l1)
		{
			l2=l1;
			l1=dp[v[n][i]][0]+1;
		}
		else if(dp[v[n][i]][0]>=l2)
		{
			l2=dp[v[n][i]][0]+1;
		}
	}
	if(v[n].size()>1) dp[n][1]=l1+l2;
 
	return;
}
 
void solve()
{
	ll n; cin>>n;
	vector<ll>v[n+1];
 
	for(ll i=0; i<n-1; i++)
	{
		ll x,y; cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
 
	dfs(1,v);
	ll ans=0;
	rep(i,1,n+1) ans=max(ans,max(dp[i][1],dp[i][0]));
	cout<<ans<<endl;
}
 
 
 
int main()
{
  //memset(dp,-1,sizeof(dp));
  cin.tie(0); 
  cout.tie(0); 
  ios_base::sync_with_stdio(0);
  //int t; cin>>t;
  //while(t--)
  //{
    solve();
  //}
}
