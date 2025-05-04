/*
 * Author: Jameson Chen
 * Created: 2023/11/17
 * Link: https://adalab.cs.nthu.edu.tw/contest/75/problem/W7-4
 * Title: Sum of Divisors
 */
 
#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
const long long mod = 1e9 + 7;
 
void add(long long& a, long long b) {
    a = (a + b) % mod;
}
 
long long mul(long long a, long long b) {
    return (a * b) % mod;
}
 
long long constexpr fastPow(long long x, long long p) {
    long long res = 1;
    while (p) {
        if (p & 1) res = mul(res, x);
        p >>= 1;
        x = mul(x, x);
    }
    return res;
}
 
const long long mod_inv2 = fastPow(2, mod - 2);
 
int main() {
    long long n;
    cin >> n;
 
    long long ans = 0;
    vector<long long> v;
    long long prv;
    for (long long i = 1, f; i * i <= n; prv = i++) {
        f = n / i;
        add(ans, f * i);
        v.emplace_back(f);
    }
    reverse(v.begin(), v.end());
 
    for (auto const& cur : v) {
        add(ans, mul(n / cur, mul(mod_inv2, mul((cur + prv + 1) % mod, (cur - prv) % mod))));
        prv = cur;
    }
 
    cout << ans << flush;
 
    return 0;
}
