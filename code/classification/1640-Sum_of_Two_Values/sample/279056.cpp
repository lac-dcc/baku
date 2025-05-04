#include <iostream>
#include <algorithm>
 
#define f first
#define s second
 
using namespace std;
 
int n, x;
pair<int, int> a[200000];
 
 
bool pred(const pair<int, int>& p1, const pair<int, int>& p2)
{
	return p1.f < p2.f;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> x;
	for (int i = 0; i < n; ++i) cin >> a[i].f, a[i].s = i + 1;
 
	sort(a, a + n);
 
	int m = n - 1;
	for (int i = 0; i < m; ++i)
	{
		int j = lower_bound(a + i + 1, a + n, make_pair(x - a[i].f, 0), pred) - a;
		if (j == n) continue;
		if (a[j].f + a[i].f == x) {
			cout << a[i].s << ' ' << a[j].s;
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
