#include <bits/stdc++.h>
 
#ifdef COOKIE_CHAN
#include <debug.hpp>
#else
#define DEBUG(...)
#endif
 
typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;
 
#define int int64_t
#define ff first
#define ss second
#define vt(...) vector< __VA_ARGS__ >
#define sz(...) (int)(__VA_ARGS__).size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(x) x.begin(), x.end()
 
constexpr int M = 1000000007;
constexpr int MONKE = 0;
 
using namespace std;
 
template <typename T1, typename T2>
bool sort_by_second_greater(const pair<T1, T2>& a, const pair<T1, T2>& b) {
    return (a.ss > b.ss);
}
 
int32_t main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
#ifndef COOKIE_CHAN
    cin.tie(0);
#endif
    // todo
    int n, k;
    cin >> n >> k;
    int a[k];
    for (int i = 0; i < k; ++i) cin >> a[i];
    
    const int MAX = (1 << k);
    int odd = 0, even = 0;
    for (int mask = 1; mask < MAX; ++mask) {
        int res = n;
        for (int i = 0; i < k && res <= n; ++i) 
            if ((mask >> i) & 1) 
                res /= a[i];
 
 
        if (__builtin_popcount(mask) % 2 == 0) even += res;
        else odd += res;
    }
    cout << odd - even << '\n';
    return MONKE;
}