#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
 
vector<ll>arr[100005];
bool color[100005];
ll w[100005];
bool ha_vor;
ll q = -1, e = -1, y = -1;
 
void dfs(ll x, ll k)
{
	
	color[x] = true;
	w[x] = k;
	for (ll i = 0; i < arr[x].size(); i++)
	{
		if (color[arr[x][i]])
		{
			if (k - w[arr[x][i]] >= 2)
			{
				ha_vor = true;
				q = w[arr[x][i]];
				e = k;
				y = arr[x][i];
				return;
			}
		}
		else
		{
			dfs(arr[x][i], k + 1);
		}
		if (ha_vor)
			return;
	}
	w[x] = 0;
}
 
void du(ll x)
{
	cout << x + 1 << ' ';
	if (!color[x])
		return;
	color[x] = true;
	for (ll i = 0; i < arr[x].size(); i++)
	{
		if (w[arr[x][i]] == w[x] + 1)
		{
			du(arr[x][i]);
			return;
		}
	}
}
int main()
{
	ll i, j, k, m, n, a, b;
	cin >> n;
	cin >> m;
	ha_vor = 0;
	for (i = 0; i < m; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (i = 0; i < n; i++)
	{
		if (!color[i])
			dfs(i, 1);
		if (ha_vor)
		{
			cout << e - q + 2 << endl;
			du(y);
			cout << y + 1 << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
 
	return 0;
}
