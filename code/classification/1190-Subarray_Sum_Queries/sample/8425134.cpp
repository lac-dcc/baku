#include <bits/stdc++.h>
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef __float128 lld;
using namespace std;
 
//single modify, range query
template <typename T>
struct Segtree {
    //note that t[0] is not used
    int n;
    T* t;
    T uneut, qneut;
 
    //single element modification function
    function<T(T, T)> fmodify;
 
    //product of two elements for query and updating tree
    function<T(T, T)> fcombine;
 
    Segtree(int n, T updateNeutral, T queryNeutral, function<T(T, T)> fmodify, function<T(T, T)> fcombine) {
        this -> n = n;
        t = new T[2 * n];
 
        this -> fmodify = fmodify;
        this -> fcombine = fcombine;
 
        uneut = updateNeutral;
        qneut = queryNeutral;
 
        for(int i = 0; i < n; i++){
            t[i + n] = uneut;
        }
        build();
    }
 
    void build() { // build the tree after manually assigning the values.
        for (int i = n - 1; i > 0; i--) {   
            t[i] = fcombine(t[i * 2], t[i * 2 + 1]);
        }
    }
 
    void modify(int p, T value) { // set value at position p
        p += n;
        t[p] = fmodify(t[p], value);
        for (p /= 2; p > 0; p /= 2) {
            t[p] = fcombine(t[p * 2], t[p * 2 + 1]);
        }
    }
 
    T query(int l, int r) { // sum on interval [l, r)
        T l_res = qneut, r_res = qneut;
        bool l_none = true, r_none = true;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2 == 1) {
                if(l_none) {
                    l_none = false;
                    l_res = t[l];
                }
                else {
                    l_res = fcombine(l_res, t[l]);
                }
                l++;
            }
            if (r % 2 == 1) {
                r--;
                if(r_none) {
                    r_none = false;
                    r_res = t[r];
                }
                else {
                    r_res = fcombine(t[r], r_res);
                }
            }
        }
        if(l_none) {
            return r_res;
        }
        if(r_none) {
            return l_res;
        }
        return fcombine(l_res, r_res);
    }
 
    T query(int ind) {
        return this->query(ind, ind + 1);
    }
};
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    struct seg {
        ll max_pfx, max_sfx, max_sum, sum;
        seg() {};
        seg(ll sum) {
            this->sum = sum;
        }
        seg(ll max_pfx, ll max_sfx, ll max_sum, ll sum) {
            this->max_pfx = max_pfx;
            this->max_sfx = max_sfx;
            this->max_sum = max_sum;
            this->sum = sum;
        }
    };
    function<seg(seg, seg)> fmodify = [](const seg src, const seg val) -> seg{
        seg next;
        next.max_pfx = src.max_pfx + val.sum;
        next.max_sfx = src.max_sfx + val.sum;
        next.max_sum = src.max_sum + val.sum;
        next.sum = src.sum + val.sum;
        return next;
    };
    function<seg(seg, seg)> fcombine = [](const seg lhs, const seg rhs) -> seg{
        seg next;
        next.max_pfx = max(lhs.max_pfx, lhs.sum + rhs.max_pfx);
        next.max_sfx = max(rhs.max_sfx, rhs.sum + lhs.max_sfx);
        next.max_sum = max({lhs.max_sum, rhs.max_sum, lhs.max_sfx + rhs.max_pfx});
        next.sum = lhs.sum + rhs.sum;
        return next;
    };
    Segtree<seg> segt(n, {0, 0, 0, 0}, {0, 0, 0, 0}, fmodify, fcombine);
    for(int i = 0; i < n; i++){
        segt.modify(i, {a[i]});
    }
    for(int i = 0; i < m; i++){
        ll k, x;
        cin >> k >> x;
        k --;
        ll orig = segt.query(k).sum;
        segt.modify(k, {x - orig});
        cout << max(0ll, segt.query(0, n).max_sum) << "\n";
    }
    
    return 0;
}
