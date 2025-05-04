#include <bits/stdc++.h>
using namespace std;
 
#define F first
#define S second
#define ll long long
 
using pii = pair <int, int>;
 
const int oo = 1e9 + 4;
const int SZ = 2e5 + 4;
 
int n, r[SZ];
ll res[SZ], ans;
vector <pair <int, pii>> f;
ll s;
 
void read() {
    scanf("%d", &n);
    f.resize(n * 2);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &f[i * 2].F, &f[i * 2 + 1].F, &r[i]);
        f[i * 2].S = make_pair(0, i);
        f[i * 2 + 1].S = make_pair(1, i);
    }
}
 
void solve() {
    sort(f.begin(), f.end());
    for (auto k : f) {
        int ind = k.S.S;
        if (k.S.F) {
            s = max(s, res[ind]);
            continue;
        }
        res[ind] = s + r[ind];
        ans = max(ans, res[ind]);
    }
    printf("%lld", ans);
}
 
signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
 
    read();
    solve();
}