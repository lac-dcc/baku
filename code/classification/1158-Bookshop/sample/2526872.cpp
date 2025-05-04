#include"bits/stdc++.h"
 
using namespace std;
 
#define int long long
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n, x;
    cin >> n >> x;
    int price[n], pages[n];
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];
    vector<int> a(x + 1), b(x + 1, 0);
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= x; i++) {
            if (i < price[j]) a[i] = b[i];
            else a[i] = max(b[i], b[i - price[j]] + pages[j]);
        }
        b = a;
    }
    cout << a[x];
}
