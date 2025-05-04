#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
 
#define Long       long long
 
const int Nn = 1e6 + 5;
 
 
void solve() {
    Long n, k;
    cin >> n >> k;
 
    Long A[k];
    for (int i = 0; i < k; ++i) cin >> A[i];
 
    Long ans = 0;
    for (int i = 1; i < (1 << k); ++i) {
        Long temp = 1, cc = 0;
        for (int j = 0; j < k; ++j) if (i & (1 << j)) {
            if (temp <= n / A[j]) temp *= A[j];
            else                  temp = 0;
            cc++;
        }
        if (temp <= 0) continue;
        if (cc % 2) ans += n / temp;
        else        ans -= n / temp;
    }
 
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
 
    while (t--) {
        solve();
    }
 
    return 0;
}