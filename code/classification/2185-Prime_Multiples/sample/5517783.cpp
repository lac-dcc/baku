#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int k;
	long long n, prime[20], ans = 0;
	cin >> n >> k;
	for(int i = 0; i < k; ++i) cin >> prime[i];
	for(int i = 1; i < 1<<k; ++i){
		int j = 0;
		long long tmp = 1;
		bool parity = 0;
		for(; 1<<j <= i; ++j){
			if(!(1<<j&i)) continue;
			parity = !parity;
			if(prime[j] > n/tmp) tmp = 2e18;
			else tmp *= prime[j];
		}
		ans += n/tmp * (parity?1:-1);
	}
	cout << ans;
	return 0;
}