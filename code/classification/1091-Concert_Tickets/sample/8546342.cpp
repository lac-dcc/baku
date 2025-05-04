#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    multiset<int> prices;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        prices.insert(h);
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        auto it = prices.upper_bound(t);
        if (it == prices.begin()) {
            cout << "-1\n";
        } else {
            --it;
            cout << *it << '\n';
            prices.erase(it);
        }
    }
    
    return 0;
}
