#include<bits/stdc++.h>
using namespace std;
#define int long long
 
#define ff first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
 
const int mod = 1e9+7;
const int inf = -1e14;
const int mx  = 2e5+5;
 
#define left(p) (p<<1)
#define right(p) (p<<1)+1
#define mid(l,r) (l+r)/2
#define max3(a,b,c)     max(a, max(b, c))
 
int n, q;
int a[mx];
 
struct info{
    int sum, best;
    int lbest, rbest;
    void merge(info &a, info &b){
        sum = a.sum + b.sum;
        lbest = max(a.lbest, a.sum+b.lbest);
        rbest = max(b.rbest, b.sum+a.rbest);
        best = max3(a.best, b.best, a.rbest+b.lbest);
    }
    info(int v=0){sum=v; best=lbest=rbest=max(v,0LL);}
}tree[mx << 2];
 
void build(int p, int l, int r){
    if(l == r) tree[p] = info(a[l]);
    else{
        build(left(p), l, mid(l,r));
        build(right(p), mid(l,r)+1, r);
        tree[p] = info();
        tree[p].merge(tree[left(p)], tree[right(p)]);
    }
}
 
void update(int p, int l, int r, int idx, int v){
    if(l == r){
        tree[p] = info(v);
        return;
    }
    if(idx <= mid(l,r))
        update(left(p), l, mid(l,r), idx, v);
    else update(right(p), mid(l,r)+1, r, idx, v);
    tree[p] = info();
    tree[p].merge(tree[left(p)], tree[right(p)]);
}
 
info get(int p, int l, int r, int i, int j){
    if(l>j || r<i) {
        info temp(-1000000);
        temp.sum = 0;
        return temp;
    }
    if(l>=i && r<=j) return tree[p];
    info u = get(left(p), l, mid(l,r), i, j);
    info v = get(right(p), mid(l,r)+1, r, i, j);
    info ans; ans.merge(u, v); return ans;
}
 
signed main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    cin >> n >> q;
    for(int i=0; i<n; i++)
        cin >> a[i];
    build(1, 0, n-1);
 
    int l, r, x; while(q--){
        cin >> x >> l >> r;
        if(x == 1) update(1, 0, n-1, l-1, r);
        else cout << get(1, 0, n-1, l-1, r-1).lbest << "\n";
    }
 
    return 0;
}
