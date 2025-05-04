#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;
 
/*
 * Problem: https://cses.fi/problemset/task/1632
*/
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int a, b;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    multiset<pair<int, int>> st;
    int ct = 0;
    for (auto p : v) {
        auto f = st.upper_bound({ p.second, INT_MAX });
        if (f != st.begin()) {
            f--;
            st.erase(f);
            st.insert(p);
            ct++;
        } else if (st.size() < k) {
            st.insert(p);
            ct++;
        }
    }
    cout << ct << endl;
    return 0;
}
