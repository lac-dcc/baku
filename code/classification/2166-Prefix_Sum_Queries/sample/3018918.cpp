/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>
 
using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vi=vector<int>;
using vl=vector<ll>;
using pii=pair<int,int>;
char el = '\n';
char esp = ' ';
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";
 
struct item{
    ll pref, suf, sum, seg;
    item(){}
    item(ll val): pref(val), suf(val), sum(val), seg(val){}
};
 
item merge(item a, item b){
    item ans;
    ans.pref = max(a.pref, a.sum + b.pref);
    ans.suf = max(b.suf, b.sum + a.suf);
    ans.seg = max({a.seg, b.seg, a.suf + b.pref});
    ans.sum = a.sum + b.sum;
    return ans;
}
 
const item neutro = item(0LL);
 
struct segtree{
    int l, r;
    item value;
    segtree *left, *right;
    
    segtree(int l, int r, vl &v) : l(l), r(r){
        if(l == r){
            value = item(v[l]);
            return;
        }
        int m = (l + r) / 2;
        left = new segtree(l, m, v);
        right = new segtree(m + 1, r, v);
        value = merge(left->value, right->value);
    }
    
    item query(int &a, int &b){
        if(r < a || b < l) return neutro;
        if(l >= a && r <= b) return value;
        
        return merge(left->query(a, b), right->query(a, b));
    }
    
    void update(int &idx, int &val){
        if(idx > r || idx < l) return;
        if(l == r){
            value = item(val);
            return;
        }
        
        left->update(idx, val);
        right->update(idx, val);
        value = merge(left->value, right->value);
    }
};
 
int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n, q, idx, val, type, a, b;
    cin>>n>>q;
    vl v(n);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    segtree st(0, n - 1, v);
    
    while(q--){
        cin>>type;
        if(type == 1){
            cin>>idx>>val;
            idx--;
            st.update(idx, val);
        }else{
            cin>>a>>b;
            a--, b--;
            cout<<max(0LL, st.query(a,b).pref)<<el;
        }
    }
}
 
/*
 
*/


