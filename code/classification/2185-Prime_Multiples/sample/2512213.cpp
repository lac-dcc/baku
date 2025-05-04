#include <iostream>
 
typedef long long int i64;
 
using namespace std;
 
int ilog2(int i) {
	int t = 0;
	for(int p = 16; p != 0; p >>= 1) {
		if((i >> p) > 0) {
			t |= p;
			i >>= p;
		}
	}
	return t;
}
int main() {
	int k;
	i64 n, ans = 0;
	cin >> n >> k;
	i64 num[k];
	for(int i = 0; i < k; i++) {
		cin >> num[i];
	}
	i64 dp[(1<<k)];
	dp[0] = -n;
	for(int i = 1; i < (1<<k); i++) {
		int j = (i & -i);
		dp[i] = -dp[i-j]/num[ilog2(j)];
		ans = ans + dp[i];
	}
	cout << ans << endl;
	return 0;
}
