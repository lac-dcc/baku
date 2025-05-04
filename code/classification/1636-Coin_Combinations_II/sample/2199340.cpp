#pragma GCC optimize ("O3")
//
#pragma GCC optimize ("-fno-stack-protector")
#include <iostream>
#include <vector>
#include <algorithm>
constexpr int MOD = 1e9 + 7;
constexpr int MN = 1000001;
int f[MN];
int main() {
	int n, x;
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> n >> x;
	std::vector<int> coins(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> coins[i];
	}
	// let f(s, l) be the number of ordered ways that sum
	// `s` can be produced with coins at most `c[l]`.
	//
	// Now the set of ordered ways can be split into
	// those that have 0 coins `c[l]` and those that
	// have at least 1 coin `c[l]`. The latter
	// set equals to the set of ordered ways
	// to produce sum `s-c[l]` with coins at most `c[l]`
	// with `c[l]` added to each of these sets.
	//
	//
	// In other words:
	//
	// f(s, l) = f(s, l-1) + f(s-c[l], l);
	f[0] = 1;
	std::sort(coins.begin(),coins.end());
	for (int coin: coins) {
		for (int sum = coin; sum <= x; ++sum) {
			f[sum] += f[sum - coin];
			if (f[sum] >= MOD) {
				f[sum] -= MOD;
			}
		}
	}
	std::cout << f[x] << std::endl;
}
