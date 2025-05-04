#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tt, tc;
 
void solve() {
    ll n;
    int k;
    cin >> n >> k;
    vector<ll> a(k);
    for (auto& u : a) cin >> u;
 
    ll ans = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        int cnt = __builtin_popcount(mask);
        double digits = 0;
        for (int j = 0; j < k; j++) if ((1 << j) & mask) digits += floor(log10(a[j]));
        if (digits > 18) continue;
        double db_prod = 1;
        for (int j = 0; j < k; j++) if ((1 << j) & mask) db_prod *= (double)a[j];
        if (db_prod > (double)n) continue;
        ll prod = 1;
        for (int j = 0; j < k; j++) if ((1 << j) & mask) prod *= a[j];
        ans += (cnt & 1 ? (n/prod) : -(n/prod));
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    tt = 1, tc = 1; // cin >> tt;
    while (tt--) solve(), tc++;
}
