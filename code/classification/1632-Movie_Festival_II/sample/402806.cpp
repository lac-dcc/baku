#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
 
    multiset<int> mp;
    for (int i = 0; i < k; i++)
        mp.insert(0);
 
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto x = mp.lower_bound(-v[i].first);
        if (x == mp.end())continue;
        ans++;
        mp.erase(x);
        mp.insert(-v[i].second);
    }
    cout << ans << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
//    cin >> t;
 
    while (t--)
        solve();
    return 0;
}