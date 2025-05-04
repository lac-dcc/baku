#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    int k;
    cin >> n >> k;
    vector arr(k, 0ll);
    for (ll& i : arr) cin >> i;
    ll res = 0;
    for (int mask = 1; mask < (1<<k); mask++) {
        __int128_t prod = 1;
        int sgn = -1;
        bool bad = 0;
        for (int i = 0; i < k; i++) {
            if (mask& 1 << i) prod *= arr[i], sgn *= -1;
            if (prod > LONG_LONG_MAX) {
                bad = 1; break;
            }
        }
        if (bad) continue;
        res += sgn * (n / prod);
    }
    cout << res << '\n';
    return 0;
}