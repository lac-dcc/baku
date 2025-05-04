#include <bits/stdc++.h>
#define FASTIO                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
#define FILEIO(x, y, z)    \
  freopen(x, "r", stdin);  \
  freopen(y, "w", stdout); \
  freopen(z, "w", stderr);
typedef long long int lli;
typedef long double ld;
using namespace std;
const int modu = 1e9 + 7;
const int N = int(1e5) + 5;
 
void prepareSubset(lli arr[], lli n, vector<lli>& v)
{
	for (int i = 1; i < (1 << n); i++)
	{
		lli s = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				s += arr[j];
			}
		}
		v.push_back(s);
	}
}
int main()
{
	FASTIO
	lli n, x;
	cin >> n >> x;
	lli arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<lli> t1 = {0};
	vector<lli> t2 = {0};
	prepareSubset(arr, n / 2, t1);
	prepareSubset(arr + n / 2, n - n / 2, t2);
	/*for (auto& x : t1)
	{
		cout << x << " ";
	}
	cout << "\n";
	for (auto& x : t2)
	{
		cout << x << " ";
	}
	cout << "\n";*/
	sort(t1.begin(), t1.end());
	sort(t2.begin(), t2.end());
	lli cnt = 0;
	for (auto& y : t1)
	{
		if (y > x) break;
		lli reqsum = x - y;
		cnt += upper_bound(t2.begin(), t2.end(), reqsum) - upper_bound(t2.begin(), t2.end(), reqsum - 1);
	}
	cout << cnt << "\n";
	return 0;
}
