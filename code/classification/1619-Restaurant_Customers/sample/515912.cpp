#include <bits/stdc++.h>
typedef long long ll;
#define mod 1e9+7
#define endl "\n"
#define ff first
#define se second
#define all(s) s.begin(),s.end()
#define pb push_back
#define mkp make_pair
#define uno unordered_map
#define pi 3.1415926536
#define dig(a) fixed<<setprecision(a)
#define w(zz) int zz; cin>>zz; while(zz--)
#define fa(var, start, end) for(int var = start; var < end; var++)
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
ll power(ll a, ll n) {ll res = 1; while (n) {if (n % 2) {res *= a;} n >>= 1; a *= a;} return res;}
ll powerm(ll a, ll n, ll m) {ll res = 1; while (n) {if (n % 2) {res = (res * a) % m;} n >>= 1; a = (a * a) % m;} return res;}
using namespace std;
 
int main() {
	fast();
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int n, x, y, ma = 0, cur = 0;
	cin >> n;
	vector<pair<int, bool>> v;
	for (ll i = 0; i < n; i++) {
		cin >> x >> y;
		v.pb(mkp(x, true));
		v.pb(mkp(y, false));
	}
	sort(all(v));
	for (ll i = 0; i < (int)v.size(); i++) {
		cur += v[i].se ? 1 : -1;
		ma = max(ma, cur);
	}
	cout << ma << endl;
	return 0;
 
}
