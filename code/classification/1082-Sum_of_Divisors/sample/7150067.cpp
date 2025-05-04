#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x; cin >> x;
    ll cur = 1, sum = 0, mod = 1e9 + 7;
    function<ll(ll, ll)> bpow = [&](ll p, ll n) {
        if(n == 0) return 1ll;
        if(n & 1) return (bpow(p, n ^ 1) * p) % mod;
        ll sqroot = bpow(p, n >> 1);
        return (sqroot * sqroot) % mod;
    };
    ll inv_2 = bpow(2, mod - 2);
    auto calc = [&](ll l, ll r) {
        return (((((r - l + 1) % mod) * ((l + r) % mod)) % mod) * inv_2) % mod;
    };
    while(cur <= x) {
        ll cnt = x / cur;
        ll next = x / cnt;
        sum = (sum + calc(cur, next) * cnt) % mod;
        cur = next + 1;
    }
    cout << sum;
    return 0;
}
