#include<bits/stdc++.h>
using namespace std;
#define int int64_t
//#define inf INT64_MAX
#define pii pair<int,int>
#define vi vector<int>
#define endl '\n'
#define pb push_back
int t, n, m, i, j, k,a, b,c,p,x,y,ans,n1;
string s1,s2;
const int M = 1e9+7;
bool bo;
 
int  binpow(int a, int  b, int  m) {
    a %= m;
    int  res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
struct item{
    int pre, sum;
};
 
item merge(item a,item b){
    if(a.pre>a.sum+b.pre)return {a.pre,a.sum+b.sum};
    else return {a.sum+b.pre,a.sum+b.sum};
}
 
struct segtree{
    vector<item> arr;
    int size;
    void init(int n){
        size=1;
        while(size<n)size*=2;
        arr.assign(2*size,{0,0});
    }
 
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            arr[x]={max(v,(int64_t)(0)),v};
            return;
        }
        int m=(lx+rx)/2;
        if(i<m)set(i,v,2*x+1,lx,m);
        else set(i,v,2*x+2,m,rx);
        arr[x]=merge(arr[2*x+1],arr[2*x+2]);
    }
 
    void set(int i,int v){
        set(i,v,0,0,size);
    }
 
    item calc(int l,int r,int x,int lx,int rx){
        if(lx>=r||rx<=l)return {0,0};
        if(lx>=l&&rx<=r)return arr[x];
        int m=(lx+rx)/2;
        return merge(calc(l,r,2*x+1,lx,m),calc(l,r,2*x+2,m,rx));
    }
 
    item calc(int l,int r){
        return  calc(l,r,0,0,size);
    }
};
 
void solve() {
    int n,m;
    cin>>n>>m;
    segtree st;
    st.init(n);
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        st.set(i,v);
    }
    while(m--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1)st.set(l-1,r);
        else{
            auto x=st.calc(l-1,r);
            cout<<x.pre<<endl;
        }
    }
 
}
 
 
 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    t = 1;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
//  cin >> t;
    while (t--) solve();
}
 
 
