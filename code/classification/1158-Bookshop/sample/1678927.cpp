//#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
//#pragma GCC target("fma")
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
using namespace std;
 
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}
 
 
int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int n, x;
	cin >> n >> x;
 
	vector<int> dp(x + 1, -1);
	vector<int> a(n), b(n);
	fab(0, n, i)
	{
		cin >> a[i];
	}
	fab(0, n, i)
	{
		cin >> b[i];
	}
	dp[0] = 0;
 
	for ( int j = 0; j < n; j++)
	{
		for ( int i = x - a[j]; i >= 0; i--)
		{
 
			if (dp[i] != -1 and i + a[j] <= x)
			{
				dp[i + a[j]] = max(dp[i + a[j]], dp[i] + b[j]);
 
			}
 
 
		}
 
	}
 
 
 
	cout << *max_element(all(dp)) << endl;
 
 
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
