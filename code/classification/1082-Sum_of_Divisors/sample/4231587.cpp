#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define PI acos(-1)  // acos(-1)    P  P v
#define cl(x) (x * 2)  //   l ` Iindex
#define cr(x) (x * 2 + 1)  // k l ` Iindex
#define NO_TAG 0
#define MOD 1000000007
#define inf 1e9
#define INF 0x3f3f3f3f
#define FZ(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(x) (int)x.size()
#define ll long long int
using namespace std;
 
ll total_sum(ll l, ll r) {
	return ((((l + r) % MOD) * ((r - l + 1) % MOD) % MOD) * 500000004 % MOD);
}
 
ll sum(ll n) {/*for (ll i = 1; i <= n; i++) ret += (n/i)*i;*/
	ll ret = 0;
	for (ll l = 1, r, add; l <= n; l = r + 1) {
		r = n / (n / l);
		ret = (ret + (n / l) *  ((((l + r) % MOD) * ((r - l + 1) % MOD) % MOD) * 500000004 % MOD)) % MOD;
	}
	return ret;
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	cout << sum(n);
}