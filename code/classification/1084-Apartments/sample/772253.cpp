#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 55;
 
int n, m, k;
int a[maxN];
multiset<int> b;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >>  m >> k;
 
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    sort(a + 1, a + n + 1);
 
    for(int i = 0; i < m; i++) {
        int x;  cin >> x;
        b.insert(x);
    }
 
    int ans = 0;
 
    for(int i = 1; i <= n; i++) {
        int val = a[i];
        int lf = val - k, rt = val + k;
        auto it = b.lower_bound(lf);
 
        if(it == b.end()) {
            continue;
        }
 
        if(*it <= rt) {
            ans++;
            b.erase(it);
        }
    }
 
    cout << ans << '\n';
 
    return 0;
}