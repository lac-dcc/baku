#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for (ll i = a; i < b; i++)
#define inf pow(2,31)-1
 
using namespace std;
 
class segtree {
    private:
    ll n;
    vector<ll> a,st,lazy,pref;
 
    ll l(ll p){ return p*2; }
    ll r(ll p){ return p*2+1; }
 
    void build(ll p, ll L, ll R){
        if (L == R){
            st[p]= a[L];
            pref[p] = max(a[L],0ll);
        }else{
            ll mid = (L+R)/2;
            build(l(p), L, mid);
            build(r(p), mid+1,R);
            st[p] = (st[l(p)]+st[r(p)]);
            pref[p] = max(pref[r(p)]+st[l(p)],pref[l(p)]);
        }
    }
 
    void propagate(ll p,ll L,ll R){
        if (lazy[p] != -1){
            st[p] = lazy[p];
            if (L!=R){
                lazy[l(p)] = lazy[p];
                lazy[r(p)] = lazy[p];
            }
            lazy[p] = -1;
        }
    }
 
    pair<ll,ll> rmq(ll p, ll L,ll R,ll i,ll j){
        propagate(p,L,R);
        if (i > j) return {0,0};
        if ((i<=L) and (R<=j)) return {st[p],pref[p]};
        ll mid = (R+L)/2;
        pair<ll,ll> left = (rmq(l(p),  L  ,mid,i,min(j,mid)));
        pair<ll,ll> right = (rmq(r(p),mid+1,  R,max(i,mid+1),j));
        return {left.first+right.first,max(left.second,left.first+right.second)};
    }
 
    void runn(){
        rep(i,1,2*n+2){
            cout<<st[i]<<" "<<pref[i]<<"\n";
        }
    }
 
    void update(ll p, ll L, ll R, ll i, ll j, ll val){
        propagate(p,L,R);
        if (i>j) return;
        if (i<=L and R<=j){
            lazy[p] = val;
            propagate(p,L,R);
        }else{
            ll mid = (L+R)/2;
            update(l(p),L  ,mid,i,min(j,mid),val);
            update(r(p),mid+1,R,max(mid+1,i),j,val);
            ll left = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
            ll right = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
            st[p] = (left+right);
        }
    }
    
    void updatee(ll i,ll change){
        i--;
        st[i+n+1]=change;
        pref[i+n+1] = max(change,0ll);
        ll strt = (i+n+1)/2;
        while (strt>=1){
            pref[strt] = max(pref[l(strt)],st[l(strt)]+pref[r(strt)]);
            st[strt] = st[l(strt)]+st[r(strt)];
            strt/=2;
        }
    }
 
    
 
    public:
    segtree(ll sz): n(sz), st(4*n), lazy(4*n,-1), pref(4*n) {}
    segtree(vector<ll> A): segtree((ll) A.size()){
        a = A;
        build(1,0,n-1);
    }
    ll RMQ(ll i,ll j){ return rmq(1,0,n-1,i,j).second; }
    void upd(ll i,ll j, ll v){ update(1,0,n-1,i,j,v); }
    void upd2(ll i,ll change){
        updatee(i,change);
    }
    void run() {runn();}
};
 
void solve(){
    ll n,q; cin>>n>>q;
    ll k = 1;
    while(k<n){
        k*=2;
    }
    vector<ll> x(k,0);
    rep(i,0,n) cin>>x[i];
    segtree sg(x);
    // sg.run();
    // cout<<"\n";
    rep(_,0,q){
        ll type; cin>>type;
        if (type == 1){
            //update
            ll k,u; cin>>k>>u;
            sg.upd2(k-1,u);
            // sg.run();
            // cout<<"\n";
        }else{
            //query
            ll a,b; cin>>a>>b;
            cout<<sg.RMQ(a-1,b-1)<<"\n";
        }
    }
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
