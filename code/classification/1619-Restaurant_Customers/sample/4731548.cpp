#include<bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
// 	freopen("input.in", "r", stdin);
// 	freopen("input1.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(6);
	int n; cin >> n;
	pair<int, int> times[2 * n];
	for (int i=0; i<n; i++)
	{
		int a, b; cin >> a >> b;
		times[2 * i] = {a, 1};
		times[2 * i + 1] = {b, -1};
	}
	sort(times, times + (n << 1));
	int ans=0, curr=0;
	for (int i=0; i<2*n; i++)
	{
		curr += times[i].second;
		ans = max(ans, curr);
	}
	cout << ans << "\n";
	return 0;
}
