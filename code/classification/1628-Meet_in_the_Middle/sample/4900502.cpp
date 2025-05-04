#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define N 100000
#define all(x) (x).begin(), (x).end()
#define inf 1000000007
#define pi 3.141592653589793238462643383279502884197169399
 
ll binpow(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
  
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n, x; 
	cin >> n >> x;
	vll a, b, aa, bb;
	ll ans = 0;
	for(int i = 0; i<n; i++)
	{
		ll t; cin >> t;
		if(i < (n+1)/2) a.push_back(t);
	    else b.push_back(t);	
	}	
	for(int i = 0; i<(1<<a.size()); i++)
	{
		ll sum = 0;
		for(int j = 0; j<a.size(); j++)
		{
			if((1<<j)&(i)) sum += a[j];
			if(sum > x) break;
		}
		if(sum <= x) aa.push_back(sum);
	}
	for(int i = 0; i<(1<<b.size()); i++)
	{
		ll sum = 0;
		for(int j = 0; j<b.size(); j++)
		{
			if((1<<j)&i) sum += b[j];
			if(sum > x) break;
		}
		if(sum <= x) bb.push_back(sum);
	}
	sort(all(bb));
	for(auto it: aa) ans += upper_bound(all(bb), x-it) - lower_bound(all(bb), x-it);
	cout << ans << '\n';
}
