#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define el "\n"
#define space " "
//
const int N = 2e5 + 10;
int a[N];
//
void solve()
{
	int n;
	cin >> n;
	for (int i=1;i<=n;++i) cin >> a[i];
	int max_so_far = INT_MIN;
	int max_ending_here = 0;
	for (int i=1;i<=n;++i)
    {
        max_ending_here+=a[i];
        max_so_far = max(max_so_far, max_ending_here);
        if (max_ending_here < 0) max_ending_here = 0;
    }
    cout << max_so_far;
}
//
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}