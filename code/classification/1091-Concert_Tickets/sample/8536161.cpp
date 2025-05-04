//Concert Tickets - https://cses.fi/problemset/task/1091
 
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
 
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (s.empty()) {
            cout << -1 << '\n';
            continue;
        }
        auto it = s.lower_bound(x);
        if (it == s.begin() && *it > x) {
            cout << -1 << '\n';
            continue;
        }
        if (it == s.end() || *it > x) {
            it--;
        }
        if (*it <= x) {
            cout << *it << '\n';
            s.erase(it);
        } else {
            cout << -1 << '\n';
        }
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
