#include <bits/stdc++.h>
#define ll long long
#define vi vector<long long>
#define si set<long long>
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define LSEQ(n, seq) for (int i = 0; i < n; i++) cin >> seq[i]
#define PSEQ(n, seq, sep, end) for(int i = 0; i < n; i++) cout << seq[i] << sep; cout << end;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 1e9+7;
const double pi = acos(-1);
 
ll ult = 0;
#define NULL_VALUE LLONG_MIN
template<class T> struct seg_tree {
    int n;
    seg_tree(vector<T> a) {
        n = a.size();
        tree.resize(n * 4);
        lazy.resize(n * 4);
    }
 
    struct node {
        T x = 0;
        int l = -1;
        int r = -1;
        const node operator + (const node& other) const {
            node ans;
            ans.x = max(other.x, x);
            return ans;
        }
        int left(){
            if(l != -1) return l;
            return this -> l = ++ult;
        }
        int right(){
            if(r != -1) return r;
            return this -> r = ++ult;
        }
    };
    
    vector<node> tree;
    vector<T> lazy;
    
    inline void push(int id, ll l, ll r){
        tree[id].x += lazy[id];
        if (l != r) {
            lazy[tree[id].left()] += lazy[id];
            lazy[tree[id].right()] += lazy[id];
        }
        lazy[id] = 0;
    }
 
    void update(ll l, ll r, ll ql, ll qr, ll id, T x){
        push(id, l, r);
        if(l > qr || r < ql) return;
        if(l >= ql && l <= qr && r <= qr){
            lazy[id] += x;
            push(id, l, r);
            return;
        }
    
        ll m = (l + r) >> 1;
        update(l, m, ql, qr, tree[id].left(), x);
        update(m + 1, r, ql, qr, tree[id].right(), x);
        ll ml = tree[id].l;
        ll mr = tree[id].r;
        tree[id] = tree[tree[id].left()] + tree[tree[id].right()];
        tree[id].l = ml;
        tree[id].r = mr;
    }
    void update(ll l, ll r, T x) {update(0,n - 1,l,r,0,x);}
    
    node query(ll l, ll r, ll ql, ll qr, ll id){
        push(id, l, r);
        if(l > qr || r < ql){
            node nil;
            nil.x = NULL_VALUE;
            return nil;
        }
        if(l >= ql && l <= qr && r <= qr) return tree[id];
        ll m = (l + r) >> 1;
        return query(l,m,ql,qr,tree[id].left()) + query(m + 1, r, ql, qr, tree[id].right());
    }
    
    T query(ll l, ll r) {return query(0,n - 1,l,r,0).x;}
};
 
 
void solve_test_case(){
    ll n, m; cin >> n >> m;
    ll nx = 0;
    ll vals[n];
    seg_tree<ll> tr(vector<ll>(n + 1));
    REP(i,1, n+1){
        ll x; cin >> x;
        nx += x;
        tr.update(i,i,nx);
        vals[i - 1] = x;
    }
    while(m--){
        ll tip; cin >> tip;
        if(tip == 2){
            ll a, b; cin >> a >> b;
            ll res = tr.query(a,b) - tr.query(a - 1, a - 1);
            cout << max(res, 0ll) << "\n";
        }else{
            ll a, x; cin >> a >> x;
            tr.update(a,n,x - vals[a - 1]);
            vals[a - 1] = x;
        }
    }
}
 
 
int main(){
    ios::sync_with_stdio(0);
    cout << setprecision(20) << fixed;
    cin.tie(0);
    cout.tie(0);
    int t = 1;
 
    while(t--) solve_test_case();
 
    return 0;
}
