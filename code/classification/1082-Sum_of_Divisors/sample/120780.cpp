// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("sse4.2")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
// #include <algorithm>
// #include <iostream>
// #include <cstdlib>
// #include <random>
// #include <string>
// #include <vector>
// #include <queue>
// #include <map>
// #include <set>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
 
template<class K>
using uset = gp_hash_table<K, null_type>;
 
template<class key, class val>
using umap = gp_hash_table<key, val>;
 
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define len(v) ((signed)v.size())
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define int ll
#define kek pop_back
#define F first
#define S second
#define pii pair<int, int>
mt19937 rnd(5654897);
#define rand rnd()
 
#ifdef LOCAL
#define debug(x) cout << #x << " = " << x << endl;
#else
#define debug(x) ;
#endif
 
const int INF = numeric_limits<int>::max() >> 2;
 
template<class T1, class T2>
bool cmin(T1 &a, const T2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
 
template<class T1, class T2>
bool cmax(T1 &a, const T2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
 
inline void run();
 
void UseFiles(const string &s) {
#ifndef LOCAL
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
#endif
}
 
// signed main = 10;
 
signed main() {
	// UseFiles("sequence");
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef LOCAL
	// assert(freopen("test.in", "r", stdin));
	#endif
	run();
}
template<class t1, class t2>
pair<t1, t2> operator+(const pair<t1, t2> &a, const pair<t1, t2> &b) {
	return {a.first + b.first, a.second + b.second};
}
 
template<class t1, class t2>
pair<t1, t2> operator-(const pair<t1, t2> &a, const pair<t1, t2> &b) {
	return {a.first - b.first, a.second - b.second};
}
 
bool in_range(const pii &a, int n, int m) {
	return a.first > -1 && a.first < n && a.second > -1 && a.second < m;
}
 
 
const int mx = 1e12 + 100;
const int mx1 = 1e7 + 100;
const int mx2 = mx / mx1 + 100;
int mod = 1e9 + 7;
 
int get_upper(int n, int c) {
	int l = 0, r = n + 11;
	while (r - l > 1) {
		int x = (r + l) >> 1;
		if (n / x < c)
			r = x;
		else
			l = x;
	}
	return r;
}
 
int get_lower(int n, int c) {
	int l = 0, r = n + 11;
	while (r - l > 1) {
		int x = (r + l) >> 1;
		if (n / x <= c)
			r = x;
		else
			l = x;
	}
	return r;
}
 
int get_sum(int l, int r) {
	if (l >= r)
		return 0;
	int res = (r + l - 1) % mod;
	res *= (r - l) % mod;
	res %= mod;
	res *= (mod + 1) >> 1;
	res %= mod;
	return res;
}
 
void run() {
	int n;
	cin >> n;
	int sm = 0;
	for (int i = 1; i < mx1; ++i) {
		sm += i * (n / i);
		sm %= mod;
	}
	sm %= mod;
	for (int i = 1; i < mx2; ++i) {
		int r = get_upper(n, i), l = max(mx1, get_lower(n, i));
		sm += get_sum(l, r) * i;
		sm %= mod;
	}
	cout << sm << endl;
}