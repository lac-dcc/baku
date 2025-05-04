#include <bits/stdc++.h>
using namespace std;
 
long long n, x;
long long mxs = -1e18, ans = -1e18;
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mxs = max(x, mxs+x);
        ans = max(ans, mxs);
    }
 
    cout << ans;
}