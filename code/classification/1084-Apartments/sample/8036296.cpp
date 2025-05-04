#include <bits/stdc++.h>
 
const int NMAX = 2e5 + 5;
 
int n, m, k, a[NMAX], b[NMAX];
 
int main() {
    std :: cin >> n >> m >> k;
 
    for (int i = 1; i <= n; ++ i) {
        std :: cin >> a[i];
    }
 
    for (int j = 1; j <= m; ++ j) {
        std :: cin >> b[j];
    }
 
    std :: sort(a + 1, a + n + 1);
    std :: sort(b + 1, b + m + 1);
 
    int ans = 0;
 
    for (int i = 1, j = 1; i <= n && j <= m;) {
        if (a[i] - k <= b[j] && b[j] <= a[i] + k) {
            ++ ans;
 
            ++ i;
            ++ j;
 
            continue;
        }
 
        if (a[i] + k < b[j]) {
            ++ i;
 
            continue;
        }
 
        if (b[j] < a[i] - k) {
            ++ j;
 
            continue;
        }
    }
 
    std :: cout << ans << "\n";
 
    return 0;
}
