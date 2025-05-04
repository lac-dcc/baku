#include<iostream>
using ll = long long;
const ll mod = 1000000007;
signed main () {
    ll n, ans = 0;
    std::cin >> n;
    for (ll l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        ans += (n / l) % mod * ((l + r) % mod) % mod * ((r - l + 1) % mod) % mod * 500000004 % mod;
    }
    std::cout << ans % mod << '\n';
}
