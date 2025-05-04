#include "bits/stdc++.h"
 
using namespace std;
using LL = long long;
 
constexpr int N = 1e5 + 5;
constexpr LL mod = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    LL n;
    cin >> n;
 
    LL sum = 0;
 
    for (LL i = 1; i * i <= n; i++) {
        LL j = (n / i) % mod;
        sum += (j * (j + 1) / 2) % mod;
        sum %= mod;
        sum -= (i * (i - 1) / 2) % mod;
        sum %= mod;
        if (sum < 0) sum += mod;
        sum += (j - i) * i % mod;
        sum %= mod;
        if (sum < 0) sum += mod;
    }
 
    cout << sum << endl;
}
