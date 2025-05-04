#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static constexpr ll M = 1e9 + 7;
 
constexpr ll pow_mod(const ll base, const ll exp, const ll m) {
    if (!exp) return 1;
    if (exp % 2) return (base * pow_mod(base, exp - 1, m)) % m;
    const ll q = pow_mod(base, exp / 2, m);
    return (q * q) % m;
}
 
constexpr ll safe_mod(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}
 
constexpr std::pair<ll, ll> inv_gcd(ll a, ll b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};
 
    ll s = b, t = a;
    ll m0 = 0, m1 = 1;
 
    while (t) {
        ll u = s / t;
        s -= t * u;
        m0 -= m1 * u;
 
        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
 
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}
 
constexpr ll inv_mod(ll x, ll m) {
    assert(1 <= m);
    auto z = inv_gcd(x, m);
    assert(z.first == 1);
    return z.second;
}
 
constexpr ll sum_1_to_n_mod(const ll n, const ll m) {
    ll ans = (n % M) * ((n + 1) % M);
    ans %= m;
    ans *= inv_mod(2LL, m);
    ans %= m;
    return ans;
}
 
ll sum_of_sum_of_divisors(const ll x) {
    ll ans = 0;
 
    for (ll lo = 1; lo <= x;) {
        const ll q = x / lo;
        const ll hi = x / q;
 
        ll to_add = sum_1_to_n_mod(hi, M) - sum_1_to_n_mod(lo - 1, M);
        to_add += M;
        to_add %= M;
 
        to_add *= (q % M);
        to_add %= M;
 
        ans += to_add;
        ans %= M;
 
        lo = hi + 1;
    }
 
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll x;
    cin >> x;
    cout << sum_of_sum_of_divisors(x) << '\n';
 
    return 0;
}


