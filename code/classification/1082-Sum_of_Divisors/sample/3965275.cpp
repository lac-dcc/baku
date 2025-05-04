#include<bits/stdc++.h>
#define FOR(i,a,b,k) for (ll i=a;i<=b;i+=k)
#define FORD(i,a,b,k) for (ll i=a;i>=b;i-=k)
#define ll long long int
#define all(a) (a).begin(), (a).end()
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll MOD=1e9+7;
 
//inline ll readll()       {char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();ll  n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';return(!sign)?n:-n;}
//inline string readstring() {char c;while(c=getchar(),c==' '||c=='\n'||c=='\t');string s({c});while(c=getchar(),c!=EOF&&c!=' '&&c!='\n'&&c!='\t')s+=c;return s;}
 
// hết phần lộn xào rồi, vào main code thoi :v
 
/* Không theo thuật toán nhưng học vì nó vui
                                -Lê Quý Long- */
ll n;
 
ll POW(ll a, ll b, ll m)
{
	ll res = 1;
	a %= m;
 
	while(b > 0)
	{
		if(b&1) res = res*a%m;
		b = b >> 1;
		a = a*a%m;
	}
 
	return res%m;
}
 
ll inverse(ll x)
{
	return POW(x,MOD-2,MOD);
}
 
ll sum(ll n)
{
	return ((n%MOD) * ((n+1)%MOD) % MOD) * inverse(2) % MOD;	
}
 
ll divisorSum(ll n)
{
	ll l  = 1;
	ll res = 0;
 
	while(l <= n)
	{
		ll k = n/l;
		ll r = n/k;
		k %= MOD;
 
		res += ((sum(r) - sum(l-1)%MOD) * k )%MOD;
 
		res %= MOD;
		l = r + 1;
	}
 
	res %= MOD;
	if(res < 0) return res + MOD;
	else return res;
}
 
int main()
{
    	fast_cin 	
	//freopen("TEST.INP", "r", stdin);
	//freopen("TEST.OUT", "w", stdout);
	cin >> n;
	cout << divisorSum(n);
 
	
	return 0;
}