#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 25;
ll ar[N], n;
int k;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> ar[i];
    }
    ll ans = 0;
    for (int i = 1; i < (1 << k); i++) {
        ll prod = 1;
        for (int j = 0; j < k; j++) {
            if (i >> j & 1) {
                if (n / prod < ar[j]) {
                    prod = n + 1;
                    break;
                }
                prod *= ar[j];
            }
        }
        if (__builtin_popcount(i) & 1) ans += n / prod;
        else ans -= n / prod;
    }
    cout << ans << '\n';
}