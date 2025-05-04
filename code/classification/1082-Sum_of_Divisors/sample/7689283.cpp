#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const long long mod = 1e9 + 7;
const long long inv2 = 500000004;
 
long long f(long long l, long long r) {
	l %= mod, r %= mod;
	return (l + r) % mod * (r - l + 1 + mod) % mod * inv2 % mod;
} 
 
long long cal(long long n) {//计算sum: i * (n / i) 
	long long l = 1ll, r = 0ll;
	long long ans = 0ll;
	while (l <= n) {
		r = n / (n / l);
		ans += f(l, r) % mod * (n / l) % mod;
		ans %= mod;
		l = r + 1;
	}
	return ans;
}
 
int main() {
	long long n;
	cin >> n;
	cout << cal(n) << endl;
	return 0;
}
