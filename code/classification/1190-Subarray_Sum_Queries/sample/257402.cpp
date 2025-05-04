#include<bits/stdc++.h>
using namespace std;
 
 
#define ll long long
#define pb push_back
#define mp make_pair
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, a, b) for(int i = (a); i > (b); --i)
#define MAXN 200005
 
typedef pair <int,int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <ll> vl;
 
const int mod = 1e9+7;
const ll inf = 2e18+5;
 
ll n;
 
typedef struct infotag {
    ll sum, pref, suff, ans;
} info;
 
info tree[4*MAXN];
 
info combine(info l, info r) {
    info res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}
 
info make_info(int val) {
    info res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0, val);
    return res;
}
 
 
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = make_info(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        tree[v] = combine(tree[v*2], tree[v*2+1]);
    }
}
 
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = make_info(new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        tree[v] = combine(tree[v*2] , tree[v*2+1]);
    }
}
 
info query(int v, int tl, int tr, int l, int r) {
    if (l>tr ||  r<tl) 
        return make_info(0);
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return combine(query(v*2,tl,tm,l,min(tm,r)) , query(v*2+1,tm+1,tr,max(l,tm+1),r));
}
 
int main(){
    int q;
    cin>>n>>q;
    int a[n+1];
    
    for(int i=1; i<=n; i++)
        cin>>a[i];
        
    build(a,1,1,n);
    
    while(q--){
        int l,r;
        cin>>l>>r;
        update(1,1,n,l,r);
        info p = query(1,1,n,1,n);
        cout<<p.ans<<endl;
        
    }
    return 0;
}
