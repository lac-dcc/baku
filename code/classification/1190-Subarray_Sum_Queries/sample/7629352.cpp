#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
template<typename T> bool ckmin(T& x, const T& y) { return x > y ? x = y, 1 : 0; }
template<typename T> bool ckmax(T& x, const T& y) { return x < y ? x = y, 1 : 0; }
 
const int MX = (int) 2e5 + 5;
const int INF = (int) 1e9;
const int LG = __lg(MX) + 1;
 
struct node {
    int sum;
    int minLeft, maxLeft, minRight, maxRight;
    int Max, Min;
    
    node(int _sum = 0, int _minLeft = INF, int _maxLeft = 0, int _minRight = INF, int _maxRight = 0, int _Max = 0, int _Min = INF) {
        sum = _sum;
        minLeft = _minLeft; maxLeft = _maxLeft;
        minRight = _minRight; maxRight = _maxRight;
        Max = _Max; Min = _Min;
    }
};
 
node comb(const node& x, const node& y) {
    node res;
    res.sum = x.sum + y.sum;
    // max
    res.Max = max({x.Max, y.Max, x.maxRight + y.maxLeft});
    res.maxLeft = max(x.maxLeft, x.sum + y.maxLeft);
    res.maxRight = max(y.maxRight, y.sum + x.maxRight);
    // min
    res.Min = min({x.Min, y.Min, x.minRight + y.minLeft});
    res.minLeft = min(x.minLeft, x.sum + y.minLeft);
    res.minRight = min(y.minRight, y.sum + x.minRight);
    return res;
}
 
struct segtree {
    int n;
    vector<node> st;
    
    segtree(int _n = 0) {
        n = _n;
        st.assign(4 * n + 5, node());
    }
    
    void update(int id, int l, int r, int p, int val) {
        if (p < l || p > r) return;
        if (l == r) {
            st[id].sum = st[id].minLeft = st[id].minRight = st[id].maxLeft = st[id].maxRight = st[id].Max = st[id].Min = val;
            return;
        }
        
        int mid = (l + r) >> 1;
        int x = id << 1, y = x | 1;
        update(x, l, mid, p, val); update(y, mid + 1, r, p, val);
        st[id] = comb(st[x], st[y]);
    }
    
    void update(int p, int val) {
        update(1, 1, n, p, val);
    }
    
    node get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return node();
        if (u <= l && r <= v) return st[id];
        int mid = (l + r) >> 1;
        int x = id << 1, y = x | 1;
        return comb(get(x, l, mid, u, v), get(y, mid + 1, r, u, v));
    }
    
    node get(int l, int r) {
        node res = get(1, 1, n, l, r);
        ckmax(res.Max, 0LL);
        return res;
    }
};
 
// struct Query {
//     char c;
//     int x, y, k;
    
//     Query(char _c = 0, int _x = 0, int _y = 0, int _k = 0) {
//         c = _c; x = _x; y = _y; k = _k;
//     }
// };
 
// int n, numNode, c[MX];
// vector<int> adj[MX];
// Query queries[MX];
// int par[MX][LG + 1], dep[MX];
 
// void dfs(int u, int p) {
//     for (int v : adj[u]) if (v != p) {
//         dep[v] = dep[u] + 1;
//         par[v][0] = u;
//         dfs(v, u);
//     }
// }
 
// void run_case(void) {
//     numNode = 1;
//     cin >> n;
//     for (int i = 1; i <= n; ++i) {
//         char c; cin >> c;
//         int x, y, k = 0; cin >> x >> y;
//         if (c == '?') cin >> k;
//         queries[i] = Query(c, x, y, k);
//         if (c == '+') {
//             ++numNode;
//             adj[x].push_back(numNode);
//             adj[numNode].push_back(x);
//             c[numNode] = y;
//         }
//     }
    
//     dfs(1, 1);
//     for (int j = 1; j < LG; ++j) for (int i = 1; i <= n; ++i) par[i][j] = par[par[i][j - 1]][j - 1];
    
//     for (int i = 1; i <= numNode; ++i) adj[i].clear();
// }
 
signed main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    // int test_case; cin >> test_case;
    // while (test_case--) run_case();
    int n, m; 
    cin >> n >> m;
    segtree seg(n);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        seg.update(i, x);
    }
    while (m--) {
        int k, x; cin >> k >> x;
        seg.update(k, x);
        cout << seg.get(1, n).Max << '\n';
    }
    return 0;
}
