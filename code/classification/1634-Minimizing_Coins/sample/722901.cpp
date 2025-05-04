#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>   //PBDS
#include <ext/pb_ds/tree_policy.hpp>       //PBDS
#define int long long int
#define vi vector<int>
#define vii vector<pair<int,int>>
#define pi pair<int,int>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mi map<int,int>
#define PI   3.141592653589
#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define f(i,x,n) for(int i=x;i<n;i++)
#define rf(i,x,n) for(int i=n-1;i>=x;i--)
#define check(x)   cerr<<#x<<" : "<<x<<endl;
#define ordered_set tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
#define fbo find_by_order                    //return iterator PBDS
#define ook order_of_key                     //return number :)) PBDS
#define baar exit(0)
#define INF 1000000000000000000
using namespace __gnu_pbds;
using namespace std;
int powmod(int base,int exponent,int mod)
{
	int ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
signed main()
{
	fast
	int n,x;
	cin>>n>>x;
	vi v(n);
	for(int &x:v) cin>>x;
	int dp[x+1];
	memset(dp,0,sizeof(dp));
	f(i,1,x+1)
	{
		int coins=LLONG_MAX;
		f(j,0,n)
		{
			if(i-v[j]==0)
			{
				coins=1;
			}
			if(i>v[j] && dp[i-v[j]]!=0)
			{
				coins=min(coins,dp[i-v[j]]+1);
			}
		}
		if(coins==LLONG_MAX) dp[i]=0;
		else dp[i]=coins;
	}
	if(dp[x]==0)cout<<-1;
	else cout<<dp[x];
	return 0;
}
