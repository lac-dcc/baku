/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
 
#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif
 
 
 
int main() {
    vamos;
 
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){return a[i] < a[j];});
 
    for (int i = 0; i < n; i++) {
        for (int l = i + 1; l < n; l++) {
            for (int j = l + 1, k = n - 1; j < k;) {
                ll s = a[idx[i]] + a[idx[l]] + a[idx[j]] + a[idx[k]];
                if(s > x) k--;
                else if(s < x) j++;
                else {
                    cout << idx[i] + 1 << " " << idx[l] + 1 << " " << idx[j] + 1 << " " << idx[k] + 1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
