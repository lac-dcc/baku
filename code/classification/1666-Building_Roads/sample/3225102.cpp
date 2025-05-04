#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
std::vector<bool> v;
std::vector<std::vector<ll>> a;
 
void A(int i)
{
	v[i] = true;
 
	for (const auto& entry : a[i])
	{
		if (!v[entry])
		{
			A(entry);
		}
	}
}
 
 
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	ll n, m;
	std::cin >> n >> m;
 
	v.resize(n);
	a.resize(n);
 
	for (ll i = 0; i < m; i++)
	{
		ll l, r;
		std::cin >> l >> r;
		--l;
		--r;
 
		a[l].push_back(r);
		a[r].push_back(l);
	}
 
	std::vector<ll> ans;
 
	for (ll i = 0; i < n; i++)
	{
		if (!v[i])
		{
			ans.push_back(i);
			A(i);
		}
	}
 
	if (ans.size() == 1)
	{
		std::cout << "0\n";
	}
	else
	{
		std::cout << ans.size() - 1 << '\n';
		for (ll i = 1; i < ans.size(); ++i)
		{
			std::cout << ans[i] + 1 << ' ' << ans[i - 1] + 1 << '\n';
		}
	}
	return 0;
}
