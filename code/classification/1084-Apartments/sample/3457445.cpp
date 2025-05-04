#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
 
int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m, k; cin >> n >> m >> k;
    vector<int> app(n), apt(m);
    for (auto &x : app) cin >> x;
    for (auto &x : apt) cin >> x;
    sort(app.begin(), app.end());
    sort(apt.begin(), apt.end());
    
    int ans = 0;
    auto it = app.begin(), jt = apt.begin();
    while (it != app.end() && jt != apt.end()) {
        if (*it - k <= *jt && *jt <= *it + k) {
            ans++, it++, jt++;
        } else if (*it < *jt) {
            it++;
        } else {
            jt++;
        }
    }
    cout << ans << "\n";
}
 