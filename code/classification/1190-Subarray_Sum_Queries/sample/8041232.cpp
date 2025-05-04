#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
mt19937 rng;
struct S{
    ll mx, L, R, sum;
};
typedef struct item{
    int cnt, prior;
    ll val;
    S meta;
    item *l, *r;
    item() {}
    item(ll v) : val(v), prior(rng()), l(0), r(0) {}
} *pitem;
int cnt(pitem t) { return t?t->cnt:0; }
S meta(pitem t) { return t?t->meta:(S){0,0,0,0}; }
void upd(pitem t) {
    if (!t) return;
    t->cnt = cnt(t->l) + cnt(t->r) + 1;
    S lmeta = meta(t->l);
    S rmeta = meta(t->r);
    t->meta = {
        max({lmeta.mx, rmeta.mx,
            lmeta.R + t->val + rmeta.L
        }),
        max({lmeta.L, lmeta.sum + t->val, lmeta.sum + t->val + rmeta.L}),
        max({rmeta.R, rmeta.sum + t->val, lmeta.R + t->val + rmeta.sum}),
        lmeta.sum + t->val + rmeta.sum
    };
}
void split(pitem t, pitem& l, pitem& r, int k) {
    if (!t) {l=r=0;return;}
    int ck = cnt(t->l);
    if (k <= ck) split(t->l, l, t->l, k), r=t;
    else split(t->r, t->r, r, k-ck-1), l=t;
    upd(t);
}
void merge(pitem& t, pitem l, pitem r) {
    if (!l || !r) t=l?l:r;
    else if (l->prior > r->prior) merge(l->r, l->r, r), t=l;
    else merge(r->l, l, r->l), t=r;
    upd(t);
}
void setL(pitem t, ll v) {
    if (!t) return;
    if (t->l) setL(t->l, v);
    else t->val = v;
    upd(t);
}
 
pitem root;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        ll v; cin >> v;
        merge(root, root, new item(v));
    }
    for (int i = 0; i < m; ++i) {
        pitem a, b;
        int k; ll v; cin >> k >> v;
        split(root, a, b, k-1);
        setL(b, v);
        merge(root, a, b);
        cout << root->meta.mx << '\n';
    }
}
