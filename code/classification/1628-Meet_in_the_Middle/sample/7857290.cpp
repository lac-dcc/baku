#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
#define ar array
#define sz(x) ((int)x.size())
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++) 
#define all(a) (a).begin(), (a).end()
 
// Optimized solution from O(2^n) to O(2^(n/2) * log(2^(n/2)))
 
void generate_subsets(const vector<int>& a, vector<ll>& subsets) {
    int n = sz(a);
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += a[i];
            }
        }
        subsets.push_back(sum);
    }
}
 
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;
 
    // Split the array into two halves
    int n1 = n / 2, n2 = n - n1;
    vector<int> a1(a.begin(), a.begin() + n1);
    vector<int> a2(a.begin() + n1, a.end());
 
    vector<ll> s1, s2;
    generate_subsets(a1, s1);
    generate_subsets(a2, s2);
 
    sort(all(s1));
    ll ans = 0;
    for (ll x : s2) {
        ans += upper_bound(all(s1), m - x) - lower_bound(all(s1), m - x);
    }
    cout << ans << "\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
