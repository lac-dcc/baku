#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    unsigned long long t, x, y, i;
    cin >> t;
    unsigned long long ans[t];
    for (i = 0; i < t; i++) {
        cin >> y >> x;
        if (x >= y) {
            if (x % 2 == 1) {
                ans[i] = x * x - y + 1;
            } else {
                ans[i] = (x - 1) * (x - 1) + y;
            }
        } else {
            if (y % 2 == 1) {
                ans[i] = (y - 1) * (y - 1) + x;
            } else {
                ans[i] = y * y - x + 1;
            }
        }
    }
    for (i = 0; i < t; i++)
        cout << ans[i] << "\n";
    return 0;
}
