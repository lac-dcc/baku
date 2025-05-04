#include <bits/stdc++.h>
 
using namespace std;
 
int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<int> apps(n);
    for (int i = 0; i < n; ++i) cin >> apps[i];
    sort(apps.begin(), apps.end());
 
    int a;
    multiset<int> st;
    for (int i = 0; i < m; ++i) {
        cin >> a;
        st.insert(a);
    }
 
    int res = 0;
    for (auto x : apps) {
        auto it = st.lower_bound(x - k);
        if (it == st.end()) continue;
        if (*it > x + k) continue;
        st.erase(it);
        ++res;
    }
    cout << res << "\n";
 
}