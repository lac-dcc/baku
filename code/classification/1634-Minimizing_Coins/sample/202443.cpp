#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <iomanip>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector <int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
const ll inf = 3e18 + 5;
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
 
const int maxn = 1e6 + 5;
int n, a[maxn], dp[maxn];
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif*/
 
	int x;
	cin >> n >> x;
	memset(dp, mod, sizeof dp);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		dp[a[i]] = 1;
	}
	for(int i = 1; i <= x; i++){
		for(int j = 0; j < n; j++){
			if(i - a[j] >= 0)
				dp[i] = min(dp[i], dp[i - a[j]] + 1);
		}
	}
	cout << (dp[x] > 1e6 ? -1 : dp[x]);
}