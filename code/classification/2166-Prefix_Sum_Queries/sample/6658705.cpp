#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ar array
#define vt vector
#define pq priority_queue
#define pu push
#define pub push_back
#define em emplace
#define emb emplace_back
#define mt make_tuple
 
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define allp(x, l, r) x.begin() + l, x.begin() + r
#define len(x) (int)x.size()
#define uniq(x) unique(all(x)), x.end()
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;
 
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template <class T, size_t N>
 
void re(array <T, N>& x);
template <class T> 
void re(vt <T>& x);
 
template <class T> 
void re(T& x) {
    cin >> x;
}
 
template <class T, class... M> 
void re(T& x, M&... args) {
    re(x), re(args...);
}
 
template <class T> 
void re(vt <T>& x) {
    for(auto& it : x) re(it);
}
 
template <class T, size_t N>
void re(array <T, N>& x) {
    for(auto& it : x) re(it);
}
 
template <class T, size_t N>
void wr(const array <T, N>& x);
template <class T> 
void wr(const vt <T>& x);
 
template <class T> 
void wr(const T& x) {
    cout << x;
}
 
template <class T, class ...M>  
void wr(const T& x, const M&... args) {
    wr(x), wr(args...);
}
 
template <class T> 
void wr(const vt <T>& x) {
    for(auto it : x) wr(it, ' ');
}
 
template <class T, size_t N>
void wr(const array <T, N>& x) {
    for(auto it : x) wr(it, ' ');
}
 
template<class T, class... M>
auto mvt(size_t n, M&&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, mvt<T>(args...));
}
 
void set_fixed(int p = 0) {
    cout << fixed << setprecision(p);
}
 
void set_scientific() {
    cout << scientific;
}
 
void Open(const string& name) {
#ifndef ONLINE_JUDGE
    (void)!freopen((name + ".in").c_str(), "r", stdin);
    (void)!freopen((name + ".out").c_str(), "w", stdout);
#endif
}
 
struct ST {
    #define vl v * 2 + 1
    #define vr v * 2 + 2
 
    const int inf = 1e9 + 1;
 
    struct node {
        ll sum, pref;
    };
 
    int n;
    vt <node> t;
 
    ST() {}
    ST(int _n) {
        n = _n;
        t.resize(4 * n + 10);
    }
 
    void init(int _n) {
        n = _n;
        t.resize(4 * n + 10);
    }
 
    node comb(const node& l, const node& r) {
        return {l.sum + r.sum, max(l.pref, l.sum + r.pref)};
    }
 
    void build(const vt <int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = {a[tl], max(a[tl], 0)};
            return;
        }
 
        int tm = (tl + tr) / 2;
        build(a, vl, tl, tm);
        build(a, vr, tm + 1, tr);
        t[v] = comb(t[vl], t[vr]);
    }
 
    void build(const vt <int>&a) {
        build(a, 0, 0, n - 1);
    }
 
    void upd(int v, int tl, int tr, int pos, int val) {
        if (tl > pos or tr < pos) {
            return;
        }
 
        if (tl == pos and pos == tr) {
            t[v] = {val, max(val, 0)};
            return; 
        }
 
        int tm = (tl + tr) / 2;
        upd(vl, tl, tm, pos, val);
        upd(vr, tm + 1, tr, pos, val);
        t[v] = comb(t[vl], t[vr]);
    }
 
    void upd(int pos, int val) {
        upd(0, 0, n - 1, pos, val);
    }
 
    node query(int v, int tl, int tr, int l, int r) {
        if (tl > r or tr < l) {
            return {0, 0};
        }
 
        if (l <= tl and tr <= r) {
            return t[v];
        }
 
        int tm = (tl + tr) / 2;
        node L = query(vl, tl, tm, l, r);
        node R = query(vr, tm + 1, tr, l, r);
        return comb(L, R);
    }
 
    ll query(int l, int r) {
        return query(0, 0, n - 1, l, r).pref;
    }
};
 
void solve() {
    int n, q; re(n, q);
    vt <int> v(n); re(v);
    ST T(n);
    T.build(v);
    for (int i = 0; i < q; ++i) {
        int task, a, b; re(task, a, b);
        if (task == 2) {
            wr(T.query(a - 1, b - 1), '\n');
            continue;
        }
        T.upd(a - 1, b);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    //Open("");
 
    int t = 1;
    for(;t;t--) {
        solve();
    }
    
    return 0;
}
