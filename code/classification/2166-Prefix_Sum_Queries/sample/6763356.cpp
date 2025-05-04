#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 2e5;
const int S = (1<<19);
ll xs[N]={};
ll st[S*2+1]={};
ll st_[S*2+1]={};
ll bit[N+1]={};
int n,q;
 
void bit_update(int i, int v){
    for(++i; i<=n; i+=(-i&i))
        bit[i] += v;
}
ll bit_query(int i){
    ll tot = 0;
    for(++i; i>0; i-=(-i&i))
        tot += bit[i];
    return tot;
}
 
void push(int idx){
    st_[idx*2] += st_[idx];
    st_[idx*2+1] += st_[idx];
    st[idx*2] += st_[idx];
    st[idx*2+1] += st_[idx];
    st_[idx] = 0;
}
 
void update_(int tl, int tr, int v, int idx, int l, int r){
    if(l>tr || r<tl) return;
    if(tl<=l && r<=tr){
        st_[idx] += v;
        st[idx] += v;
        return;
    }
    if(l!=r) push(idx);
    int m = l+(r-l)/2;
    update_(tl,tr,v,idx*2,l,m);
    update_(tl,tr,v,idx*2+1,m+1,r);
    st[idx] = max(st[idx*2], st[idx*2+1]);
}
 
void update(int tl, int tr, int v){
    update_(tl,tr,v,1,0,n-1);
}
 
ll query_(int tl, int tr, int idx, int l, int r){
    if(l>tr || r<tl) return -1e18;
    if(tl<=l && r<=tr){
        return st[idx];
    }
    if(l!=r) push(idx);
    int m = l+(r-l)/2;
    return max(
            query_(tl,tr,idx*2,l,m),
            query_(tl,tr,idx*2+1,m+1,r)
            );
}
 
ll query(int tl, int tr){
    return query_(tl,tr,1,0,n-1);
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> q;
    for(int i=0; i<n; ++i){
        int x; cin >> x;
        bit_update(i, x);
        update(i,n-1,x);
        xs[i] = x;
    }
 
    for(int i=0; i<q; ++i){
        int a,b,c; cin >> a >> b >> c;
        if(a==1){
            b--;
            int diff = c-xs[b];
            bit_update(b, diff);
            update(b, n-1, diff);
            xs[b] = c;
        } else if(a==2){
            b--;c--;
            cout << max<ll>(0, query(b,c) - bit_query(b-1)) << "\n";
        }
    }
 
}
