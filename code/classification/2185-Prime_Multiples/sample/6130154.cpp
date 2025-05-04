#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define vt vector
#define pb push_back
#define ll long long
#define pi pair<int, int>
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
 
void solve() {
    ll n;
    int k;
    cin >> n >> k;
 
    vt<ll> p(k);
    for (auto &i : p) cin >> i;
 
    ll ans = 0;
    for (int i = 1; i < (1 << k); i++) {
        ll prd = 1;
        for (int j = 0; j < k; j++) {
            if (i >> j & 1) {
                if (prd > n / p[j]) prd = n + 1;
                else prd *= p[j];
            }
        }
        if (__builtin_popcount(i) & 1) {
            ans += n / prd;
        } else {
            ans -= n / prd; 
        }
    }
 
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}