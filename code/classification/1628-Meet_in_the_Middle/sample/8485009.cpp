// Meet in the Middle
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x; cin >> n >> x;
    int an = n / 2, bn = n - an;
    vector<int> A(an), B(bn), as;
    for(auto & i : A) cin >> i;
    for(auto & i : B) cin >> i;
    for(int s = 0; s < 1 << an; s++) {
        int sum = 0;
        for(int i = 0; i < an; i++) if(s & (1 << i)) sum += A[i];
        if(sum <= x) as.push_back(sum);
    }
    sort(as.begin(), as.end());
    int ans = 0;
    for(int s = 0; s < 1 << bn; s++) {
        int sum = 0;
        for(int i = 0; i < bn; i++) if(s & (1 << i)) sum += B[i];
        if(sum <= x) {
            auto p = equal_range(as.begin(), as.end(), x - sum);
            ans += distance(p.first, p.second);
        }
    }
    cout << ans << '\n';
    return 0;
}
