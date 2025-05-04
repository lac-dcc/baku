#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ld eps = 1e-28;
 
void Solve()
{
 
	int n; cin >> n;
	vi nums(n);
	map<int, int> mp;
	int res = 0;
 
	rep(i, 0, n)
	{
		cin >> nums[i];
		(mp.find(nums[i]) == mp.end()) ? mp[nums[i]] == 1, ++res : ++mp[nums[i]];
	}
 
	cout << res;
}
int main()
{
	Solve();
 
	return 0;
}
 
/*
*C(i,L) = max(C(i-1,L-w[i])+v[i], C(i-1,L)}
*C[i,j] = C[i-1, j-1] +C[i-1,j]
*/