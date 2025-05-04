/*  एक ही नारा एक ही नाम जय श्री राम -जय श्री राम  */
#include<bits/stdc++.h>
using namespace std;
 
#define  ull unsigned long long int
#define ll long long
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second
#define pb push_back
#define Setbit(n)   __builtin_popcountll(n)
#define ms(a,x) memset(a,x,sizeof(a))
const ll INF = 1e15;
const  ll  N = 200007;
 
 
ll pow1(ll base, ll p)
{
	ll res = 1;
	while (p > 0)
	{
		if (p & 1)
		{
			res = (res * base) % mod;
		}
		base = (base * base) % mod;
		p = p >> 1;
 
	}
	return res;
 
}
 
 
ll modinv(ll n)
{
	return pow1(n, mod - 2);
}
 
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
	if (a.ss != b.ss)return a.ss < b.ss;
	else return a.ff < b.ff;
}
 
 
 
void solve() {
 
	ll n, m, i, j, k;
	ll x;
	cin >> n >> x;
	ll a[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> prev(x + 1, 0), curr(x + 1, 0);
 
 
 
	for (int i = 0; i <= x; i++) {
		if ( i % a[0] == 0) {
			prev[i] = 1;
		}
	}
 
	for (int ind = 1; ind < n; ind++) {
		for (int target = 0; target <= x; target++) {
			ll notTake = prev[target];
			ll take = 0;
			if (target >= a[ind])take = curr[target - a[ind]];
 
			curr[target] = (take % mod + notTake % mod) % mod;
		}
		prev = curr;
	}
 
	cout << prev[x];
}
 
 
 
int  main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	ll t;
	t = 1;
	// cin >> t;
 
	while (t--)
	{
 
		solve();
 
	}
	return 0;
 
}