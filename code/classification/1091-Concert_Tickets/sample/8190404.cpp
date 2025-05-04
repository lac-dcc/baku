#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int val;
    multiset<int> h;
    for (int i = 0; i < n; i++) {
        cin >> val;
        h.insert(val);
    }
    int t;
    for (int i = 0; i < m; i++) {
        cin >> t;
        auto it = h.upper_bound(t);
        if (it == h.begin()) {
            cout << -1 << "\n";
        } else {
            it--;
            cout << *it << endl;
            h.erase(it);
        }
    }
    return 0;
}
