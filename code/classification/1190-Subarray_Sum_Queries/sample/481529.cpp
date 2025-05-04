#pragma GCC optimize("Ofast")
#pragma GCC target("fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
    
#define endl '\n'
#define int long long
 
using namespace std;
 
int mod = 998244353;
const int MAXN = 2e+5;
 
int a[MAXN];
 
// 0 - sum
// 1 - prefix sum 
// 2 - suffix sum 
// 3 - answer
int t[3*MAXN][4];
 
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v][0] = a[tl];
        t[v][1] = max(a[tl], 0LL);
        t[v][2] = t[v][1];
        t[v][3] = t[v][2];
    } else {
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v + 1, tm + 1, tr);
        t[v][0] = t[2*v][0] + t[2*v + 1][0];
        t[v][1] = max(t[2*v][1], t[2*v][0] + t[2*v + 1][1]);
        t[v][2] = max(t[2*v + 1][2], t[2*v + 1][0] + t[2*v][2]);
        t[v][3] = max({t[2*v][3], t[2*v + 1][3], t[2*v][2] + t[2*v + 1][1]});
    }
}
 
void update(int v, int tl, int tr, int ind) {
    if (tl == tr) {
        t[v][0] = a[tl];
        t[v][1] = max(a[tl], 0LL);
        t[v][2] = t[v][1];
        t[v][3] = t[v][2];
    } else {
        int tm = (tl + tr) / 2;
        if (ind <= tm) update(2*v, tl, tm, ind);
        else update(2*v + 1, tm + 1, tr, ind);
        t[v][0] = t[2*v][0] + t[2*v + 1][0];
        t[v][1] = max(t[2*v][1], t[2*v][0] + t[2*v + 1][1]);
        t[v][2] = max(t[2*v + 1][2], t[2*v + 1][0] + t[2*v][2]);
        t[v][3] = max({t[2*v][3], t[2*v + 1][3], t[2*v][2] + t[2*v + 1][1]});
    }
}
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, Q;
    cin >> n >> Q;
 
    for (int i = 0; i < n; i++) cin >> a[i];
 
    build(1, 0, n - 1);
 
    while (Q--) {
        int k, x;
        cin >> k >> x;
        k--;
        a[k] = x;
        update(1, 0, n - 1, k);
        cout << t[1][3] << endl;
    }
}
