#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
 
struct node{
    ll pre, suf, total, best;
    node(ll pre, ll suf, ll total, ll best) : pre(pre), suf(suf),
    total(total), best(best){}
    node(ll val){
        best = suf = pre = max(0LL, val);
        total = val;
    }
    node(){
 
    }
};
 
template<class T> struct IterativeSegmentTree{
    int n; vector<T> ST; T (*merge)(T, T);
    IterativeSegmentTree(vector<T> &a, T (*merge)(T, T)) : merge(merge){
        n = a.size(); ST.resize(n << 1);
        for (int i = n; i < (n << 1); i ++)
            ST[i] = a[i - n];
        for (int i = n - 1; i > 0; i --)
            ST[i] = merge(ST[i << 1], ST[i << 1 | 1]);
    }
    void update(int pos, T val){
        ST[pos += n] = val;
        for (pos >>= 1; pos > 0; pos >>= 1)
            ST[pos] = merge(ST[pos << 1], ST[pos << 1 | 1]);
    }
    T query(int l, int r){
        T ansL, ansR; bool hasL = 0, hasR = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) 
                (hasL ? ansL = merge(ansL, ST[l ++]) : (ansL = ST[l ++], hasL = 1));
            if (r & 1) 
                (hasR ? ansR = merge(ST[ --r], ansR) : (ansR = ST[ --r], hasR = 1));
        }
        if (!hasL) return ansR;
        if (!hasR) return ansL;
        return merge(ansL, ansR);
    }
};
 
node merge(node a, node b){
    return node({
        max({a.pre, a.total + b.pre}),
        max({b.suf, b.total + a.suf}),
        a.total + b.total,
        max({a.best, b.best, a.suf + b.pre})
    });
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<node> a(n);
    for (int i = 0; i < n; i ++){
        ll val;
        cin >> val;
        a[i] = node(val);
    }
    IterativeSegmentTree<node> S(a, merge);
    for (int i = 0; i < q; i ++){
        int k;
        ll x;
        cin >> k >> x;
        S.update(k - 1, node(x));
        cout << S.query(0, n - 1).best << "\n";
    }
    return 0;
}
