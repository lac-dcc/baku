/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-22 12:50]
 *	"Compete against yourself"
**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define endl '\n'
#define mod 1000000007
#define modd 998244353
#define inf 1e18
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define clr(x,n) x.clear();x.resize(n,0)
#define precise(x) fixed<<setprecision(x)
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/
 
 
void solve() {
	int n, m; cin >> n >> m;
	vector<pii> g[n + 1], gr[n + 1];
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		g[x].pb({y, w});
		gr[y].pb({x, w});
	}
	vi d1(n + 1, inf), dn(n + 1, inf);
	set<pii> s;
	d1[1] = 0; s.insert({0, 1});
	while (!s.empty()) {
		pii f = *s.begin();
		int cur = f.ff, node = f.ss;
		s.erase(f);
		for (auto x : g[node]) {
			if (cur + x.ss < d1[x.ff]) {
				auto y = s.find({d1[x.ff], x.ff});
				if (y != s.end())
					s.erase(y);
				d1[x.ff] = cur + x.ss;
				s.insert({d1[x.ff], x.ff});
			}
		}
	}
	s.clear();
	dn[n] = 0; s.insert({0, n});
	while (!s.empty()) {
		pii f = *s.begin();
		int cur = f.ff, node = f.ss;
		s.erase(f);
		for (auto x : gr[node]) {
			if (cur + x.ss < dn[x.ff]) {
				auto y = s.find({dn[x.ff], x.ff});
				if (y != s.end())
					s.erase(y);
				dn[x.ff] = cur + x.ss;
				s.insert({dn[x.ff], x.ff});
			}
		}
	}
	int ans = inf;
	for (int i = 1; i <= n; i++) {
		for (auto y : g[i]) {
			if (d1[i] != inf && dn[y.ff] != inf) ans = min(ans, d1[i] + dn[y.ff] + y.ss / 2);
		}
	}
	cout << ans << endl;
}
 
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T; cin.ignore();
	for (int i = 1; i <= T; i++) {
		// cout << "Case #" << i << ": ";
		// clock_t start = clock();
		solve();
		// clock_t end = clock();
		// cout << (end-start) << endl;
		//print execution time in ms
	}
 
	return 0;
}
