#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define emb emplace_back
#define bigint __int128
#define fi first
#define se second
#define Task ""
 
#define fi first
#define se second
 
const int N = 4e1 + 2, T = 2e6, mod = 1e9 + 7;
const ll MAX = 1e18;
 
int n, x, a[N], sum;
ll ans;
vector <int> v;
 
void backtrack1(int i, int end) {
	if(i > end) {
		v.emb(sum); return;
	}
	backtrack1(i + 1, end);
	if (sum + a[i] <= x) sum += a[i], backtrack1(i + 1, end), sum -= a[i];
}
 
void backtrack2(int i, int end) {
	if(i > end) {
		if (v.back() + sum < x) return;
		ans += upper_bound(v.begin(), v.end(), x - sum) - lower_bound(v.begin(), v.end(), x - sum);
		return;
	}
	backtrack2(i + 1, end);
	if (sum + a[i] <= x) sum += a[i], backtrack2(i + 1, end), sum -= a[i];
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	if(fopen(Task".inp", "r")) {
		freopen(Task".inp", "r", stdin);
		freopen(Task".out", "w", stdout);
	}
	
	cin >> n >> x;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	backtrack1(1, n / 2); sort (v.begin(), v.end());
	sum = 0; backtrack2(n / 2 + 1, n);
	cout << ans;
}
