 #include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const long long MAXN = 1e9+7;
const int N = 1000000;
const long long MOD = 1000000007;
 
struct node{
    long long pref, suf, mx, sum;
};
 
vector<node> tree;
int sz;
 
node conc(node a, node b){
    ll mx = max(a.mx, max(b.mx, a.suf + b.pref));
    ll pref = max(a.pref, a.sum + b.pref);
    ll suf = max(b.suf, b.sum + a.suf);
    ll sum = a.sum + b.sum;
    return {pref, suf, mx, sum};
}
 
void init(int n){
    sz = 1;
    while(sz < n) sz *= 2;
    tree.assign(2*sz-1, {0, 0, 0, 0});
}
 
void build(vector<long long> &a, int x = 0, int lx = 0, int rx = sz){
    if(lx + 1 == rx){
        if(lx < a.size()){
            tree[x] = {a[lx], a[lx], a[lx], a[lx]};
        }
        return;
    }
    int m = (lx + rx) / 2;
    build(a, 2*x+1, lx, m);
    build(a, 2*x+2, m, rx);
    tree[x] = conc(tree[2*x+1], tree[2*x+2]);
}
 
void upd(int l, long long d, int x = 0, int lx = 0, int rx = sz){
    if(lx + 1 == rx){
        tree[x] = {d, d, d, d};
        return;
    }
    int m = (lx + rx) / 2;
    if(l < m) upd(l, d, 2*x+1, lx, m);
    else upd(l, d, 2*x+2, m, rx);
    tree[x] = conc(tree[x+x+1], tree[x+x+2]);
}
 
int main(){
    ios::sync_with_stdio(false);
    init(N);
    int n,q;
    cin >> n >> q;
    vector<long long> p(n);
    init(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    build(p);
    while(q--){
        int l, d;
        cin >> l >> d;
        l--;
        upd(l, d);
        cout << max(tree[0].mx, 0ll) << "\n";
    }
}
