#include "bits/stdc++.h"
 
using namespace std;
 
#define ll long long
const int N = 2e5 + 5, M = 2 * N, mod = 1e9 + 7, inf = 0x3f3f3f3f;
const ll infll = 1ll * inf * inf;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (auto &it : v)
        cin >> it.second >> it.first;
    sort(v.begin(), v.end());
    multiset<int> finish;
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        finish.insert(0);
    }
    for (int i = 0; i < n; ++i) {
        auto it = finish.lower_bound(v[i].second);
        if (it == finish.begin() and *it > v[i].second)
            continue;
        if (it == finish.end() or *it != v[i].second)
            it--;
        finish.erase(it);
        ++ans;
        finish.insert(v[i].first);
    }
    cout << ans << "\n";
}
