#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define pi pair<int,int>
#define ff first
#define ss second
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define td(v) v.begin(),v.end()
#define inf 1000000000 // 1e9
#define M   1000000007 // 1e9 + 7
using namespace std;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
int exp(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}
struct SegmentTree{ // best subarray sum
    struct node{
        int val = 0;
        int ans = 0;
        int prefix = 0;
        int suffix = 0;
        node(){}
        node(int val) : val(val) {
            ans = max(0LL,val);
            prefix = ans;
            suffix = ans;
        }
    };
    std::vector<node> st;
    int n;
    SegmentTree(){}
    SegmentTree(int sz){
        n = sz;
        st.resize(4*sz);
    }
    void rsz(int sz){
        n = sz;
        st.resize(4*sz);
    }
    node merge(node l,node r){
        node res;
        res.val = l.val + r.val;
        res.prefix = max(l.prefix, l.val + r.prefix);
        res.suffix = max(r.suffix, r.val + l.suffix);
        res.ans = max(max(l.ans, r.ans), l.suffix + r.prefix);
        return res;
    }
    void update(int p,int x){
        update(1,0,n-1,p,p,x);
    }
    void update(int cur,int l,int r,int a,int b,int x){ // l,r = atual
        if(r < a || l > b){
            return;
        }
        if(l==r){
            st[cur] = node(x);
            return;
        }
        int m = (l+r)>>1;
        update(cur*2,l,m,a,b,x);
        update(cur*2 + 1,m+1,r,a,b,x);
        st[cur] = merge(st[cur*2],st[cur*2 + 1]);
        return;
    }
    node query(int l,int r){
        return query(1,0,n-1,l,r);
    }
    node query(int cur,int l,int r,int a,int b){
        if(r<a || l>b){
            return node(0);
        }
        if(l>=a && r<=b){
            return st[cur];
        }
        int m = (l+r)>>1;
        return merge(query(2*cur,l,m,a,b),query(2*cur+1,m+1,r,a,b));
    }
};
int32_t main(){
    fastio;
    int n,q;
    cin >> n >> q;
    SegmentTree t(n);
    REP(i,0,n-1){
        int x;
        cin >> x;
        t.update(i,x);        
    }
    REP(i,0,q-1){
        int k,x;
        cin >> k >> x;
        k--;
        t.update(k,x);
        cout << t.query(0,n-1).ans << endl;
    }
}
