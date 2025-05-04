#include <bits/stdc++.h>
using namespace std;
 
vector<pair<int64_t,int64_t>> st(1e6);
 
pair<int64_t,int64_t> find(int a, int b, int l, int r, int n = 1)
{
    if (b < l || a > r)
        return {0, 0};
    if (a <= l && b >= r)
        return st[n];
 
    auto [lp, ls] = find(a, b, l, (l+r)/2, 2*n);
    auto [rp, rs] = find(a, b, (l+r)/2 + 1, r, 2*n + 1);
    return {max(lp, ls+rp), ls + rs};
}
 
pair<int64_t,int64_t> update(int t, int v, int l, int r, int n = 1)
{
    if (t == l && t == r) {
        st[n] = {max(0, v), v};
    } else if (t >= l && t <= r) {
        auto [lp, ls] = update(t, v, l, (l+r)/2, 2*n);
        auto [rp, rs] = update(t, v, (l+r)/2 + 1, r, 2*n + 1);
        st[n] = {max(lp, ls+rp), ls + rs};
    }
    return st[n];
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q;
    cin >> n >> q;
 
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        update(i, v, 1, n);
    }
 
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            update(a, b, 1, n);
        } else {
            cout << find(a, b, 1, n).first << '\n';
        }
    }
}
