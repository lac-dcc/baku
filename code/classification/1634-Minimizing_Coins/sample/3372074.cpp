#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve()
{
	ll n,x;
	cin>>n>>x;
	vector<ll> dp(x+1,1e18);
	vector<ll> v(n+1);
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(v[i]<=x)
			dp[v[i]]=1;
	}
	
	dp[0] = 0;
	for(int i=1;i<=x;i++){
		for(int j=0;j<v.size();j++){
			if(i+v[j]<=x)
				dp[i+v[j]] = min(dp[i+v[j]],dp[i]+1);
		}
	}
 
	ll ans = dp[x];
	if(ans==1e18){
		cout<<"-1";
		return;
	}
	cout<<ans;
}
 
 
signed main()
{
	ios_base::sync_with_stdio(0);             
	cin.tie(0);cout.tie(0);
	// int _t; 
	// cin>>_t; 
	// while(_t--)
		solve();
 
}
 
/*//recursive
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[1000010];
vector<ll> v;
 
ll rec(ll x){
	if(x<0)
		return 1e18;
 
	if(dp[x]!=-1)
		return dp[x];
 
	ll ans = 1e18;
	for(int i=0;i<v.size();i++){
		ans = min(ans,1+rec(x-v[i]));
	}
 
	return dp[x]=ans;
}
 
void solve()
{
	ll n,x;
	cin>>n>>x;
	memset(dp,-1,sizeof(dp));
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
		dp[v[i]]=1;
	}
	
	ll ans = rec(x);
	if(ans==1e18){
		cout<<"-1";
		return;
	}
	cout<<ans;
}
 
 
signed main()
{
	ios_base::sync_with_stdio(0);             
	cin.tie(0);cout.tie(0);
	// int _t; 
	// cin>>_t; 
	// while(_t--)
		solve();
 
}
*/