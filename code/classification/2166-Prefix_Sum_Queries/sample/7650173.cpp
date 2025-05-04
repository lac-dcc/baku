////#include <bits/stdc++.h>
////using namespace std;
////using LL = long long;
////struct SegTree {
////    struct Node {
////        LL sum, pre;
////    };
////    Node merge (const Node &a, const Node &b) {
////        return {a.sum + b.sum, max({0ll, a.pre, a.sum + b.pre})};
////    }
////    vector<Node> T;
////    SegTree(int n) : T(n * 4 +2) {}
////    Node update(int o, int L, int R, int x, int v) {
////        int ls = o *2, rs =o*2+1, m=L+(R-L)/2;
////        if (L == R) return T[o] = {v, max(0, v)};
////        (x <=m) ? update(ls, L, m, x, v) : update(rs, m + 1, R, x, v);
////        return T[o] = merge(T[ls], T[rs]);
////    }
////    Node query(int o, int L, int R, int ql, int qr) {
////        int ls=o*2, rs=o*2+1, m=L+(R-L)/2;
////        if (ql <= L && R <= qr) return T[o];
////        if (ql > R || L > qr) return {0, (LL)-1e18};
////        return merge(query(ls, L, m, ql, qr), query(rs, m + 1, R, ql, qr));
////    }
////};
////int main(void) {
////    ios::sync_with_stdio(false), cin.tie(0);
////    int n,q;
////    cin>>n>>q;
////    SegTree S(n + 1);
////    for (int i = 1, x; i <= n; ++i) cin >> x, S.update(1, 1, n, i, x);
////    while (q--) {
////        int op, a, b;
////        cin >> op >> a >> b;
////
////        if (op ==1) S.update(1, 1, n, a, b);
////
////        else cout<<S.query(1, 1, n, a, b).pre<<"\n";
////    }
////    return 0;
////}
//
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define int long long
//#define F first
//#define S second
//#define mod 1000000007
//#define N (ll)2e5+9
//ll pre[N];
//struct node {
//    int mn;
//    int lazyflag=0, lazyval=0;
//    node() {
//        lazyflag=0;
//        lazyval=0;
//    }
//};
//node seg[8*N];
//void push(ll n) {
//    if(seg[n].lazyval==0)return;
//    seg[n].mn+=seg[n].lazyval;
//    ll lft=n*2;
//    ll rgt=lft+1;
//    seg[lft].lazyval+=seg[n].lazyval;
//    seg[rgt].lazyval+=seg[n].lazyval;
//    seg[n].lazyval=0;
//}
//int query(int idx, int st, int ed, int x, int y) {
//    if(x<1) return 0;
//    push(idx);
//    if(st==x && ed==y) {
//        return seg[idx].mn;
//    }
//    int mid = (st + ed)/2;
//    int lft = 2*idx;
//    int rgt = 2*idx + 1;
//    if(y<=mid) {
//        return query(lft,st,mid,x,y);
//    } else if(x>mid) {
//        return query(rgt,mid+1,ed,x,y);
//    } else {
//        ll a=query(lft,st,mid,x,mid);
//        ll b=query(rgt,mid+1,ed,mid+1,y);
//        return max(a,b);  //update me.
//    }
//    return 0;
//}
//
//void update(int idx,int st,int ed,int x,int y,int val) {
//    push(idx);
//    if(st==x&&ed==y) {
//        seg[idx].lazyval+=val;
//        push(idx);
//        return;
//    }
//    int mid = (st + ed)/2;
//    int lft = 2*idx;
//    int rgt = 2*idx + 1;
//    if(y<=mid) {
//        update(lft,st,mid,x,y,val);
//    } else if(x>mid) {
//        update(rgt,mid+1,ed,x,y,val);
//    } else {
//        update(lft,st,mid,x,mid,val);
//        update(rgt,mid+1,ed,mid+1,y,val);
//    }
//    seg[idx].mn=max(seg[lft].mn,seg[rgt].mn);
//}
//void solve() {
//    ll n,q; cin>>n>>q;
//    ll aa[n+2];
//    for(ll i=1;i<=n;i++){
//        cin>>aa[i];
//        update(1,1,n,i,n,aa[i]);
//    }
//    cout<<query(1,1,8,5,5)<<"\n";
//    while(q--){
//        ll t; cin>>t;
//        if(t==1){
//            ll k,u; cin>>k>>u;
//            ll val=u-aa[k];
//            aa[k]=u;
//            update(1,1,n,k,n,val);
//        }
//        else{
//            ll a,b; cin>>a>>b;
//            cout<<max(0LL,query(1,1,n,a,b)-query(1,1,n,a-1,a-1))<<"\n";
//        }
//    }
//}
//int32_t main() {
//    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//    ll t=1;
//    // cin>>t;
//    for(ll it=1; it<=t; it++) {
//        //cout<<"Case "<<it<<": "; //cout<<'\n';
//        solve();
//    }
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define inf INT_MAX
#define int long long
struct ST {
#define lc (n << 1)
#define rc ((n << 1) | 1)
    int t[4 * N], lazy[4 * N];
    ST() {
        fill(t, t + 4 * N, 0);
        fill(lazy, lazy + 4 * N, 0);
    }
    inline void push(int n, int b, int e) {
        if(lazy[n] == 0) return;
        t[n] = t[n] + lazy[n];
        if(b != e) {
            lazy[lc] = lazy[lc] + lazy[n];
            lazy[rc] = lazy[rc] + lazy[n];
        }
        lazy[n] = 0;
    }
    inline int combine(int a, int b) {
        return max(a, b); //merge left and right queries
    }
    inline void pull(int n) {
        t[n] = max(t[lc], t[rc]); //merge lower nodes of the tree to get the parent node
    }
    void upd(int n, int b, int e, int i, int j, int v) {
        push(n, b, e);
        if(j < b || e < i) return;
        if(i <= b && e <= j) {
            lazy[n] += v;
            push(n, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(n);
    }
    int query(int n, int b, int e, int i, int j) {
        push(n, b, e);
        if(i > e || b > j) return LLONG_MIN;
        if(i <= b && e <= j) return t[n];
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
} t;
 
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,q; cin>>n>>q;
    int aa[n+2];
    for(int i=1;i<=n;i++){
        cin>>aa[i]; t.upd(1,1,n,i,n,aa[i]);
    }
    //cout<<"F "<<t.query(1,1,n,1,1)<<"\n";
    while(q--){
        int a,b,c; cin>>a>>b>>c;
        if(a==1){
            int val=c-aa[b]; t.upd(1,1,n,b,n,val);
            aa[b]=c;
        }
        else{
                if(b>1){
                    cout<<max(0ll,t.query(1,1,n,b,c)-t.query(1,1,n,b-1,b-1))<<"\n";
                }
                else{
                    cout<<max(0ll,t.query(1,1,n,b,c))<<"\n";
                }
        }
    }
}
