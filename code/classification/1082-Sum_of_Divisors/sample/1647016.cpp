#include <bits/stdc++.h>
#pragma GCC optimize("Ofast","unroll-loops")
#define ll long long
#define ft first
#define sec second
#define pb push_back
#define pi pair<ll,ll>
using namespace std;
const int mod=1e9+7;
ll n,sum;
ll fpow(ll x,ll y)
{
	ll ret=1;
	for(; y; y>>=1,x=(x*x)%mod) if(y&1) ret=(ret*x)%mod;
	return ret;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(ll i=1; i<=n; )
	{
		ll v=n/i;
		ll nxt=n/v;
		ll k=((i+nxt)%mod)*((nxt-i+1)%mod)%mod;
		k=k*fpow(2,mod-2)%mod;
		k=(k*v)%mod;
		sum=(sum+k)%mod;
		i=nxt+1;
	}
	cout << sum%mod;
}
