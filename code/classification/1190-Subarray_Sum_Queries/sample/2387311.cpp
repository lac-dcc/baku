#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ld long double
#define ar array
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vt vector
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
 
#define F_OR(i, a, b, s)                                                       \
    for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto &x : a)
#define RANGE(a) for (auto i = a.begin(); i != a.end(); ++i)
#define RRANGE(a) for (auto i = a.rbegin(); i != a.rend(); ++i)
 
template <class A> void read(vt<A> &v);
template <class A, size_t S> void read(ar<A, S> &a);
template <class T> void read(T &x) { cin >> x; }
void read(double &d) {
    string t;
    read(t);
    d = stod(t);
}
void read(long double &d) {
    string t;
    read(t);
    d = stold(t);
}
template <class A, class B> void read(pair<A, B> &p) {
    read(p.first);
    read(p.second);
}
template <class H, class... T> void read(H &h, T &...t) {
    read(h);
    read(t...);
}
template <class A> void read(vt<A> &x) {
    EACH(a, x)
    read(a);
}
template <class A, size_t S> void read(array<A, S> &x) {
    EACH(a, x)
    read(a);
}
 
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char *s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vt<bool> v) {
    string res;
    FOR(sz(v))
    res += char('0' + v[i]);
    return res;
}
 
template <size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)
    res += char('0' + b[i]);
    return res;
}
 
template <class A, class B> string to_string(pair<A, B> p) {
    string res;
    res += "{" + to_string(p.first) + ", " + to_string(p.second) + "}";
    return res;
}
 
template <class T> string to_string(T v) {
    bool f = 1;
    string res;
    EACH(x, v) {
        if (!f)
            res += ' ';
        f = 0;
        res += to_string(x);
    }
    return res;
}
 
template <class A> void write(A x) { cout << to_string(x); }
template <class H, class... T> void write(const H &h, const T &...t) {
    write(h);
    write(t...);
}
void print() { write("\n"); }
template <class H, class... T> void print(const H &h, const T &...t) {
    write(h);
    if (sizeof...(t))
        write(' ');
    print(t...);
}
 
template <typename node, typename update> struct Segment_Tree {
    int n;
    int h;
    vt<node> t;
    vt<update> d;
    vt<int> roots;
    update identity;
 
    Segment_Tree(int n) : n(n), t(2 * n, node()), d(n) {
 
        node identity;
        FOR(i, n)
        t[i + n] = node(identity.v, i);
 
        FOR(i, n - 1, 0, -1)
        t[i] = node::merge(t[i << 1], t[i << 1 | 1]);
 
        h = sizeof(int) * 8 - __builtin_clz(n);
    }
 
    template <class T> Segment_Tree(vt<T> a) : n(sz(a)), t(2 * n), d(n) {
 
        FOR(i, n)
        t[i + n] = node(a[i], i);
 
        FOR(i, n - 1, 0, -1)
        t[i] = node::merge(t[i << 1], t[i << 1 | 1]);
 
        h = sizeof(int) * 8 - __builtin_clz(n);
    }
 
    node query(int l, int r, bool lazy = true) { // sum on interval [l, r)
        node l_res, r_res;
 
        if (lazy)
            push(l, l + 1), push(r - 1, r);
 
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                l_res = node::merge(l_res, t[l++]);
            if (r & 1)
                r_res = node::merge(t[--r], r_res);
        };
 
        l_res = node::merge(l_res, r_res);
 
        return l_res;
    }
 
    void modify(int p, update &upd) {
 
        upd.apply(t[p + n]);
        for (p += n; p > 1; p >>= 1)
            if (p & 1)
                t[p >> 1] = node::merge(t[p ^ 1], t[p]);
            else
                t[p >> 1] = node::merge(t[p], t[p ^ 1]);
    }
 
    void lazy_modify(int l, int r, update &upd) {
        if (upd.is_identity())
            return;
        push(l, l + 1);
        push(r - 1, r);
        bool cl = false, cr = false;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (cl)
                calc(l - 1);
            if (cr)
                calc(r);
            if (l & 1)
                apply(l++, upd), cl = true;
            if (r & 1)
                apply(--r, upd), cr = true;
        }
        for (--l; r > 0; l >>= 1, r >>= 1) {
            if (cl)
                calc(l);
            if (cr && (!cl || l != r))
                calc(r);
        }
    }
 
    void push(int l, int r) {
        int s = h;
        for (l += n, r += n - 1; s > 0; --s)
            for (int i = l >> s; i <= r >> s; ++i)
                if (not d[i].is_identity()) {
                    apply(i << 1, d[i]);
                    apply(i << 1 | 1, d[i]);
                    d[i] = identity;
                }
    }
 
    void calc(int p) {
        if (d[p].is_identity())
            t[p] = node::merge(t[p << 1], t[p << 1 | 1]);
        else
            d[p].apply(t[p]);
    }
 
    void apply(int p, update &upd) {
        upd.apply(t[p]);
        if (p < n)
            d[p].combine(upd);
    }
 
    void init_roots() {
        vector<int> roots_r;
        for (auto l = n, r = n << 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                roots.push_back(l++);
            if (r & 1)
                roots_r.push_back(--r);
        }
        roots.insert(roots.end(), roots_r.rbegin(), roots_r.rend());
    }
 
    /**
     * @brief binary search in log(n), don't forget to call init_roots()
     *
     * @param x value to search for
     * @return index of found element
     */
    int binary_search(int x) {
 
        if (query(0, n).v < x)
            return -1;
 
        auto pred = [x, this](int i) {
            if (!d[i >> 1].is_identity()) {
                apply(i, d[i >> 1]);
                apply(i ^ 1, d[i >> 1]);
                d[i >> 1] = identity;
            }
            return this->t[i].v >= x;
        };
        int root = *find_if(all(roots), pred);
 
        while (root < n && t[root].v >= x) {
 
            root <<= 1; // go to left child
            if (!pred(root))
                root |= 1; // go to right child
        }
 
        return root - n;
    }
};
 
template <typename T> struct node {
 
    T v = 0, pref_sum = 0, suff_sum = 0, sum = 0, tl = -1, tr = -2;
 
    node() {}
    node(T x, T i) : tl(i), tr(i) {
        T val = max(x, (T)0);
        v = val, pref_sum = val, suff_sum = val, sum = x;
    }
    node(T v, T pre_sum, T suff_sum, T sum, T tl, T tr)
        : v(v), pref_sum(pre_sum), suff_sum(suff_sum), sum(sum), tl(tl),
          tr(tr) {}
 
    static node merge(const node &l_node, const node &r_node) {
        T tl, tr;
        if (l_node.tl >= 0 and r_node.tl >= 0)
            tl = min(l_node.tl, r_node.tl);
        else
            tl = max(l_node.tl, r_node.tl);
        tr = max(l_node.tr, r_node.tr);
 
        T v = max(max(l_node.v, r_node.v), l_node.suff_sum + r_node.pref_sum);
        T pref_sum = max(l_node.pref_sum, l_node.sum + r_node.pref_sum);
        T suff_sum = max(r_node.suff_sum, l_node.suff_sum + r_node.sum);
        T sum = l_node.sum + r_node.sum;
 
        return node(v, pref_sum, suff_sum, sum, tl, tr);
    }
};
 
template <typename T> struct update {
 
    T v = 0;
    update() {} // identity element
    update(int a) { v = a; }
 
    bool is_identity() {
        update identity;
        return v == identity.v;
    }
 
    void combine(const update &other) {
        // applied update from other(provided and parent)
        assert(false);
    }
    void apply(node<T> &s) { // apply lazy value on segment
        T val = max(v, (T)0);
        s.v = val;
        s.pref_sum = val;
        s.suff_sum = val;
        s.sum = v;
    }
};
 
void DBG() { std::cerr << "]" << std::endl; }
template <class H, class... T> void DBG(H h, T... t) {
    std::cerr << to_string(h);
    if (sizeof...(t))
        std::cerr << ", ";
    DBG(t...);
}
#ifdef _DEBUG
#define dbg(...)                                                               \
    std::cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [",    \
        DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 
void solve() {
    int n, q;
    read(n, q);
    vt<ll> v(n);
    read(v);
 
    Segment_Tree<node<ll>, update<ll>> sgt(v);
 
    dbg(sgt.query(0, n).v);
    FOR(q) {
        int a, b;
        read(a, b);
        --a;
 
        update<ll> upd = update<ll>(b);
 
        sgt.modify(a, upd);
        print(sgt.query(0, n).v);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
    FOR(t) { solve(); }
}
