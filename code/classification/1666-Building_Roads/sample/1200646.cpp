#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
#define fi first
#define sec second
#define mp make_pair
#define pub push_back
#define endl '\n'
#define f(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define frev(i,n,b,c)  for(ll i=n;i>=b;i-=c)
#define MOD 1000000007
using namespace std;
// ll setBitNumber(ll n)
// {
//     if (n == 0)
//         return 0;
 
//     ll msb = 0;
//     n = n / 2;
//     while (n != 0) {
//         n = n / 2;
//         msb++;
//     }
 
//     return (1 << msb);
// }
const int mxn = 1e6;
vector<int>adj[mxn];
bool vis[mxn] = {0};
 
void dfs(int i) {
	vis[i] = 1;
	for (auto k : adj[i]) {
		if (vis[k] == 0)dfs(k);
	}
}
 
int solve() {
	fastio
	int n, r;
	cin >> n >> r;
	f(i, 0, r - 1, 1) {
		int e, f;
		cin >> e >> f;
		adj[e].pub(f);
		adj[f].pub(e);
	}
	int nr = 0;
	vector<pair<int, int>>ans;
	dfs(1);
	f(i, 1, n, 1) {
		if (vis[i] == 0) {
			nr++;
			dfs(i);
			ans.pub({1, i});
		}
	}
	cout << nr << endl;
	for (auto i : ans)cout << i.fi << " " << i.sec << endl;
	return 0;
}
 
int main() {
	fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("outputz.txt", "w", stdout);
#endif
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
