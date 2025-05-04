#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second
 
#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
 
ld const PI = 4*atan((ld)1);
 
int const N = 2e5 + 7;
 
int n, x;
ii ar[N];
int main()
{
	fastio;
 
	cin >> n >> x;
	for (int i = 0; i < n; ++i)
		cin >> ar[i].f1, ar[i].s2 = i+1;
	sort(ar, ar+n);
 
	for (int i = 0, j = n-1; i < j; ++i)
	{
		while (ar[i].f1 + ar[j].f1 > x) --j;
 
		if (i >= j)
			break;
 
		if (ar[i].f1 + ar[j].f1 == x)
		{
			cout << ar[i].s2 << " " << ar[j].s2 << '\n';
			return 0;
		}
	}
 
	cout << "IMPOSSIBLE\n";
	return 0;
}