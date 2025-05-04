#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+1;
ll n,k,m,q;
int timer=1;
int trs[sz],dp[sz];
int id[sz],top[sz],a[sz];
int up[17][sz];
array<ll,2> val[sz];
vector<ll>adj[sz];
const int mod=998244353;
struct node{
    ll mxval;
    ll mxl;
    ll mxr;
    ll sum;
    ll lzadd;
    node(){};
} tree[sz<<2];
node null;
void build(int l=1 , int r=n, int p=1){
    if(l==r){
        tree[p].mxval=tree[p].sum=tree[p].mxl=tree[p].mxr=a[l];
        return;
    } 
        int mid=(l+r)>>1;
        build(l,mid,2*p);
        build(mid+1,r,2*p+1);
        tree[p].mxval=max(tree[2*p].mxval,tree[2*p+1].mxval);
        tree[p].mxval=max(tree[p].mxval,tree[2*p].mxr+tree[2*p+1].mxl);
        tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
        tree[p].mxl=max(tree[2*p].sum+tree[2*p+1].mxl,tree[2*p].mxl);
        tree[p].mxr=max(tree[2*p+1].sum+tree[2*p].mxr,tree[2*p+1].mxr);
}
node query(int L,int R,int l=1,int r=n,int p=1){
    if(l>R or r<L) return null;
    if(L<=l and r<=R) return tree[p];
    int mid=(l+r)>>1;
    node z;
    node x=query(L,R,l,mid,2*p);
    node y=query(L,R,mid+1,r,2*p+1);
    z.sum=x.sum+y.sum;
    z.mxl=max(x.sum+y.mxl,x.mxl);
    z.mxr=max(y.sum+x.mxr,y.mxr);
    return z;
}
void update(ll val, int L,int R,int l=1, int r=n,int p=1){
    if(l>R or r<L) return;
    if(L<=l and r<=R){
        tree[p].mxval=tree[p].sum=tree[p].mxl=tree[p].mxr=val;
        return;
    }
        int mid=(l+r)>>1;
        update(val,L,R,l,mid,2*p);
        update(val,L,R,mid+1,r,2*p+1);
        tree[p].mxval=max(tree[2*p].mxval,tree[2*p+1].mxval);
        tree[p].mxval=max(tree[p].mxval,tree[2*p].mxr+tree[2*p+1].mxl);
        tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
        tree[p].mxl=max(tree[2*p].sum+tree[2*p+1].mxl,tree[2*p].mxl);
        tree[p].mxr=max(tree[2*p+1].sum+tree[2*p].mxr,tree[2*p+1].mxr);
}
int main(){
    cin>>n>>q; ll x=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    build();
    for(int i=0;i<q;i++){
        ll t,u,v;cin>>t>>u>>v;
        if(t==2){
           node p=query(u,v);
           ll res=max(p.mxl,x);
           cout<<res<<endl;
        }
        else update(v,u,u);
    }
}
 
 
 
