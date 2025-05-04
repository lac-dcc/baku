#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using i64 = long long;
using p2i = pair<int, int>;
using p2l = pair<i64, i64>;
 
template<size_t bufsz = (1 << 18)>
struct fastFR //fread()
{
    char buf[bufsz], *p, *q;
    const size_t mx = bufsz;
    fastFR() :buf(), p(buf), q(buf) {}
    inline char operator() () {
        return (p == q && (q = (p = buf) + fread_unlocked(buf, 1, mx, stdin)), p == q ? -1 : *p++);
    }
};
 
template <class RD>
struct fastin
{
    char c;
    bool neof;
    RD gc;
    fastin() :c(), neof(true), gc() {}
    inline void skip_space() {
        while (c <= ' ' && c != -1) c = gc();
    }
    inline fastin& operator>> (char& _c) {
        skip_space();
        _c = c;
        return (*this);
    }
    template <class _Int, typename = enable_if_t<is_integral_v<_Int>>>
    inline fastin& operator>> (_Int& _x) {
        if (!neof) return (*this);
        skip_space();
        if (c == -1) {
            neof = false;
            return (*this);
        }
        int sign = (c == '-' ? (c = gc(), -1) : 1);
        if (!isdigit(c)) return (*this);
        _x = (c ^ 48);
        for (c = gc(); (c >= 48 && c <= 57); c = gc()) {
            (_x *= 10) += (c ^ 48);
        }
        _x *= sign;
        return (*this);
    }
    explicit inline operator bool() const {
        return neof;
    }
};
 
using input = fastin<fastFR<>>;
 
struct int_to_str
{
    char digit[40000];
    static constexpr unsigned b1 = 10, b2 = 100, b3 = 1000, b4 = 10000;
    constexpr int_to_str() :digit() {
        for (int i = 0, n = 0; i < 10000; i++) {
            n = i;
            for (int j = 3; j >= 0; j--) {
                digit[j + (i << 2)] = (n % 10) ^ 48;
                n /= 10;
            }
        }
    }
    template <class _Int, typename = enable_if_t<is_unsigned_v<_Int>>>
    inline constexpr unsigned to_str_len(_Int __x) const {
        unsigned ret = 0;
        do {
            (  __x < b1 ? ret += 1
            : __x < b2 ? ret += 2
            : __x < b3 ? ret += 3
            : __x < b4 ? ret += 4 : ret += 4);
            __x /= b4;
        } while (__x);
        return ret;
    }
    template <class _Int, typename = enable_if_t<is_unsigned_v<_Int>>>
    inline constexpr void operator() (char* _str, _Int __x, unsigned __len) const {
        unsigned cpylen = 0;
        do {
            cpylen = (4 < __len ? 4 : __len);
            memcpy(_str + __len - cpylen, digit + (((__x % 10000) + 1) << 2) - cpylen, cpylen);
            __len -= cpylen;
            __x /= b4;
        } while (__x);
    }
} constexpr const conv;
 
struct fastFW
{
    inline size_t operator() (const char* _buf, const size_t& _size) {
        return fwrite_unlocked(_buf, 1, _size, stdout);
    }
};
 
template <class WT = fastFW, size_t bufsz = (1 << 18)>
struct fastout
{
    char buf[bufsz];
    const size_t mx = bufsz;
    size_t size;
    WT writer;
    fastout() :buf(), size(0), writer() {}
    ~fastout() {flush();}
    inline void flush() {
        if (!size) return;
        writer(buf, size);
        size = 0;
    }
    inline fastout& operator<< (const char& _c) {
        if (size == mx) flush();
        buf[size++] = _c;
        return (*this);
    }
    template <class _Int, typename = enable_if_t<is_integral_v<_Int>>>
    inline fastout& operator<< (const _Int& _x) {
        make_unsigned_t<_Int> __x = _x;
        static unsigned _len;
        if constexpr (is_signed_v<_Int>) {
            if (_x < 0) {
                (*this) << '-';
                __x = make_unsigned_t<_Int>(-_x);
            }
        }
        _len = conv.to_str_len(__x);
        if (size + _len >= mx) flush();
        conv(buf + size, __x, _len);
        size += _len;
        return (*this);
    }
};
 
static input in;
static fastout out;
 
#define cin in
#define cout out
 
struct segtree {
    int n;
    array<p2l, 400005> tree;
    segtree(int _n) :n(_n), tree({p2l()}) {
        for (int i = n; i < n * 2; i++) {
            cin >> tree[i].F;
            //cerr << tree[i].F << ' ';
            tree[i].S = max(0ll, tree[i].F);
        }
        //cerr << '\n';
        for (int i = n - 1; i; i--) {
            tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
        }
    }
    inline p2l
    combine(const p2l& x, const p2l& y) {
        p2l ret;
        ret.F = x.F + y.F;
        ret.S = max(x.S, x.F + y.S);
        return ret;
    }
 
    inline void
    modify(int pos, i64 val) {
        tree[pos += n] = p2l(val, max(0ll, val));
        for (pos >>= 1; pos; pos >>= 1)
            tree[pos] = combine(tree[pos << 1], tree[pos << 1 | 1]);
    }
 
    inline i64
    query(int l, int r) {
        p2l l_res, r_res;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) l_res = combine(l_res, tree[l++]);
            if (r & 1) r_res = combine(tree[--r], r_res);
        }
        return combine(l_res, r_res).S;
    }
};
 
int main() {
    //cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    //cout << n << ' ' << q << '\n';
    static segtree tree(n);
    int t = 0, x = 0, y = 0;
    for (; q--; ) {
        cin >> t >> x >> y;
        --x;
        if (t == 1) tree.modify(x, y);
        else cout << tree.query(x, y) << '\n';
    }
#undef cin
#undef cout
    return 0;
}
