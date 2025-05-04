#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>
#include <bitset>
#include <stack>
#include <memory.h>
#include <list>
#include <numeric>
#include <functional>
#include <complex>
#include <cassert>
#include <regex>
#include <random>
#include <fstream>
 
 
#define ll long long
#define ld long double
#define ull unsigned ll
#define mp(xx, yy) make_pair(xx, yy)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pii pair<int,int> 
#define pll pair<ll, ll> 
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vector<int>>
#define forn(it,from,to) for(int (it)=from; (it)<to; (it)++)
ld pi = acos(-1.0);
const int mod = 1000000007;
using namespace std;
 
void yn(int a) {
	if (a) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
 
int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
 
ll add(ll a, ll b) {
	return ((a % mod) + (b % mod)) % mod;
}
 
ll mul(ll a, ll b) {
	return ((a % mod) - (b % mod)) % mod;
}
 
 
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(10);
	cout.setf(ios::fixed);
 
 
	int n;
	cin >> n;
	vll v(n);
	forn(i, 0, n) {
		cin >> v[i];
	}
	ll sm=0,ans=-2e9;
	forn(i, 0, n) {
		sm += v[i];
		ans = max(ans, sm);
		sm = max(sm, 0LL);
	}
	cout << ans;
	return 0;
}
