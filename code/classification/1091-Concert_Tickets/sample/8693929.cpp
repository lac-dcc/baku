#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    multiset<int, greater<int>> s;
 
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        s.insert(x);
    }
    for (int i = 0, x; i < m; ++i) {
        cin >> x;
        auto it = s.lower_bound(x);
        if (it == s.end()) {
            cout << -1 << "\n";
        } else {
            cout << *it << "\n";
            s.erase(it);
        }
    }
}
