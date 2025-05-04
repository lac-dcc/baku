#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
 
signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    int mx = a[0];
    for (int i = 0, mv = 0; i < n; i++) {
        mv = mv + a[i];
        mx = max(mx, mv);
        if (mv < 0) mv = 0;
    }
    cout << mx << '\n';
}
