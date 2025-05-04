#include <bits/stdc++.h>
using namespace std;
int n, q, u, v;
struct lmt {
    long long sum;
    long long ans;
    long long l;
    long long r;
} node[800005];
lmt merg(lmt A, lmt B) {
    lmt C;
    C.sum = A.sum + B.sum;
    C.ans = max(A.ans, B.ans);
    C.ans = max(C.ans, A.r + B.l);
    C.l = max({0LL, A.l, A.sum + B.l});
    C.r = max({0LL, B.r, B.sum + A.r});
    return C;
}
void update(int id, int l, int r, int u, int val) {
    if (l == r) {
        node[id].sum = val;
        node[id].ans = max(0LL, 1ll * val);
        node[id].l = max(0LL, 1ll * val);
        node[id].r = max(0LL, 1ll * val);
        return;
    }
    int mid = (l + r) / 2;
    if (u <= mid)
        update(id * 2, l, mid, u, val);
    else
        update(id * 2 + 1, mid + 1, r, u, val);
    node[id] = merg(node[id * 2], node[id * 2 + 1]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    cin >> n >> q;
    for (u = 1; u <= n; u++) {
        cin >> v;
        update(1, 1, n, u, v);
    }
    while (q--) {
        cin >> u >> v;
        update(1, 1, n, u, v);
        cout << node[1].ans << '\n';
    }
    return 0;
}
