#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
#define all(x) x.begin(), x.end()
 
 
vector <ll> gen(vector <int> v, int l, int r)
{
	int n = r - l + 1;
 
	vector <ll> ans;
 
	for (int i = 0; i < (1 << n); i++)
	{
		ll sum = 0;
 
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				sum += v[l + j];
 
		ans.push_back(sum);
	}
 
	return ans;
}
 
int main()
{
	//freopen ("input.txt","r", stdin);
	//freopen ("output.txt","w", stdout);
 
	int n, s;
 
	cin >> n >> s;
 
	vector <int> v(n);
 
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	vector <ll> vl = gen(v, 0, n / 2 - 1);
	vector <ll> vr = gen(v, n / 2, n - 1);
 
	sort(all(vl));
	sort(all(vr));
 
	ll ans = 0;
 
	for (ll x : vl)
	{
		ans += upper_bound(all(vr), s - x) - lower_bound(all(vr), s - x);
	}
 
	cout << ans << "\n";
}
