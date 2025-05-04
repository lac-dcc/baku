#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
const int MOD = 1e9 + 7, INV = (1e9 + 8) / 2;
inline static long long sumMod(long long a, long long b);
long long sumMod(long long a, long long b) {
	long long A = (b - a + 1) % MOD, B = (a + b) % MOD; 
	return A * B % MOD * INV % MOD;
}
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n, *r, ans = 0;
	int K;
	cin >> n;
	K = sqrt(n);
	r = new long long[K + 1];
	r[0] = n + 1;
	for(int i = 1; i <= K; ++i) {
		long long a = 1, b = n;
		while(a < b) {
			long long mid = (a + b) / 2;
			if(n / mid > i) a = mid + 1;
			else b = mid;
		}
		if(n / i != i) ans += n - n % i;
		ans = (ans + 1LL * i * sumMod(b, r[i - 1] - 1)) % MOD;
		r[i] = b;
	}
	cout << ans << '\n';
    return 0;
}
