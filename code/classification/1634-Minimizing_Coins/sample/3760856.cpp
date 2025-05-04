#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[105],dp[1000005];
int main(){
	cin >> n >> k;
	for ( ll i=1;i<=n;i++ ) cin >> a[i];
	sort ( a+1,a+1+n );
	for ( ll i=1;i<=k;i++ ) dp[i] = 1e18;
	for ( ll i=1;i<=k;i++ )
	{
		for ( ll j=1;j<=n;j++ )
		{
			if ( i-a[j]>=0 ){
				if ( dp[i-a[j]]!=1e18 )
					dp[i] = min ( dp[i],dp[i-a[j]]+1 );
			}
			else break;
		}
		//cout << dp[i] << " ";
	}
	ll res = (dp[k]!=1e18) ? dp[k] : (ll) -1;
	//if ( dp[k]!=1e18 ) cout << dp[k];
	//else cout << -1;
	cout << res;
}
