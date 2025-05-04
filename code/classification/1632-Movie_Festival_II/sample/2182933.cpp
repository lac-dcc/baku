//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cctype>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define ii pair <int, int>
#define FORC(i, r, a) for(int i = 1; i <= r; cin >> (a)[i++])
#define FOR(i,l,r) for(int i = l; i <= r; ++i)
#define FOD(i,l,r) for(int i = l; i >= r; --i)
#define vt vector <int> 
#define mvt vector<vt>
#define rs resize
//#define taskname
const long long maxN = 1e6, oo = 1e9, MOD = 1e9 + 7;
using namespace std;
int n, k, ans = 0;
vector <ii> a;
void readInput() {
	cin >> n >> k;
	FOR(i, 1, n) {
		int x, y;
		cin >> x >> y;
		a.push_back({ y,x });
	}
}
 
void process() {
	multiset <int> s;
	FOR(i, 1, k) s.insert(0);
	sort(all(a));
	FOR(i, 0, n - 1) {
		auto it = s.upper_bound(a[i].se);
		if (it == s.begin()) continue;
		s.erase(--it);
		s.insert(a[i].fi);
		++ans;
	}
}
 
void writeOutput() {
	cout << ans;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(taskname".INP", "r", stdin);
	//freopen(taskname".OUT", "w", stdout);
	readInput();
	process();
	writeOutput();
}