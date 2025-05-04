#include<bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
 
const int N = 2e5 + 5;
 
int n, x;
pair<int, int> a[N];
 
int bs(int l, int r, int x) {
    int res = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (a[mid].fi <= x) {
            if (a[mid].fi == x) res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    if (res == -1) return -1;
    return a[res].se;
}
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) {
        int k = bs(1, n, x - a[i].fi);
        if (k > -1 && a[i].se != k) return cout << a[i].se << ' ' << k, 0;
    }
    cout << "IMPOSSIBLE";
}