#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define L ((pos << 1) + 1)
#define R ((pos << 1) + 2)
using namespace std;
const int maxn = 2e5 + 5;
 
struct S_T{
    struct Node{
        ll sum, pre;
    };
    vector<Node> seg;
    vector<int> a;
 
    Node pull(int pos){
        Node ret;
        ret.sum = seg[L].sum + seg[R].sum;
        ret.pre = max({0LL, seg[L].sum + seg[R].pre, seg[L].pre});
        return ret;
    }
 
    void build(int l, int r, int pos){
        if(l == r){
            seg[pos] = {a[l], max(a[l], 0)};
            return;
        }
        int mid = (l + r) >> 1;
 
        build(l, mid, L);
        build(mid + 1, r, R);
        seg[pos] = pull(pos);
    }
 
    void modify(int l, int r, int q, int pos, int val){
        if(l == r){
            seg[pos] = {val, max(val, 0)};
            return;
        }
        int mid = (l + r) >> 1;
 
        if(q <= mid) modify(l, mid, q, L, val);
        else modify(mid + 1, r, q, R, val);
        seg[pos] = pull(pos);
    }
    
    Node query(int l, int r, int ql, int qr, int pos){
        if(ql <= l && r <= qr) return seg[pos];
        int mid = (l + r) >> 1;
 
        if(qr <= mid){
            return query(l, mid, ql, qr, L);
        }else if(mid < ql){
            return query(mid + 1, r, ql, qr, R);
        }else{
            Node ln = query(l, mid, ql, qr, L);
            Node rn = query(mid + 1, r, ql, qr, R);
            Node ret;
            ret.sum = ln.sum + rn.sum;
            ret.pre = max({0LL, ln.sum + rn.pre, ln.pre});
            return ret;
        }
    }
 
    S_T(int n, vector<int> arr){
        a = arr;
        seg.resize((n << 2), {0, 0});
        build(0, n - 1, 0);
    }
};
 
signed main(){OuO
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
 
    S_T tree(n, a);
 
    while(q--){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int k, u;
            cin >> k >> u;
            --k;
            tree.modify(0, n - 1, k, 0, u);
        }else{
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << tree.query(0, n - 1, l, r, 0).pre << endl;
        }
    }
}
