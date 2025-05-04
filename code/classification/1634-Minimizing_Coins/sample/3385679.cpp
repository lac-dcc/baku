/*
Nguyen Duc Anh Phuc _ Jacke
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
typedef pair<ll, pll>plll;
 
const ll m = 1e9 + 7;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, x;
	cin >> n >> x;
	vector<vector<ll>>d(2, vector<ll>(x + 1, INT_MAX));
	vector<ll>a(n + 1);
	for (ll i = 1; i <= n; i++)cin >> a[i];
	for (ll i = 0; i <= 1; i++)d[i][0] = 0;
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= x; j++)
		{
			if (j - a[i] >= 0 && d[1][j - a[i]] != INT_MAX)
				d[1][j] = min(d[0][j], d[1][j - a[i]] + 1);
			else
				d[1][j] = d[0][j];
		}
		d[0] = d[1];
		fill(d[1].begin(), d[1].end(), INT_MAX);
		d[1][0] = 0;
	}
	if (d[0][x] >= INT_MAX)cout << -1;
	else cout << d[0][x];
	return 0;
}
