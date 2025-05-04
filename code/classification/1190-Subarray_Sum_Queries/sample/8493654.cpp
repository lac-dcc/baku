#include <bits/stdc++.h>
using namespace std; 
#define sio ios_base::sync_with_stdio(0),cout.tie(0),cin.tie(0);
const int N=2e5+5; 
#define cl(x) (x<<1)
#define cr(x) (x<<1)+1
#define int long long  
struct node{
        int ans,pre,sur,sum;
}seg[4*N];
int n,m,arr[N];
void pull(int ind){
seg[ind].sum=seg[cl(ind)].sum+seg[cr(ind)].sum;
seg[ind].sur=max(seg[cr(ind)].sur,seg[cr(ind)].sum+seg[cl(ind)].sur);
seg[ind].pre=max(seg[cl(ind)].pre,seg[cl(ind)].sum+seg[cr(ind)].pre);
seg[ind].ans=max(max(seg[cr(ind)].ans,seg[cl(ind)].ans),seg[cl(ind)].sur+seg[cr(ind)].pre);
}
void build(int ind,int l,int r){
if(l==r){
    seg[ind].sum=seg[ind].sur=seg[ind].ans=seg[ind].pre=arr[l];
return  ;
}
int mid=(l+r)/2; 
build(cl(ind),l,mid);
build(cr(ind),mid+1,r);
pull(ind);
}//1-base
int query(int ind ,int l,int  r,int al,int ar){
    if(al<=l&&r<=ar){
        return seg[ind].ans; 
    }
    int mid=(l+r)/2 ,res=0 ; 
    if(al<=mid){
        res=max(res,query(cl(ind),l,mid,al,ar));
    }
    if(ar>mid){
        res=max(res,query(cr(ind),mid+1,r,al,ar));
    }
    return res;
}
void update(int ind ,int l,int r,int x,int v){
if(l==r){
   
        seg[ind].sum=seg[ind].pre=seg[ind].sur=seg[ind].ans=v;
        return  ; 
}
    int mid=(l+r)>>1;
    if(x<=mid){
        update(cl(ind),l,mid,x,v);
    }
    if(mid<x){
        update(cr(ind),mid+1,r,x,v);
    }
    pull(ind);
}
signed main(){
cin>>n>>m; 
for(int i=0;i<n;i++){
    cin>>arr[i];
}
build(1,0,n-1);
while(m--){
int a,b; 
cin>>a>>b ; 
update(1,0,n-1,a-1,b);
cout<<max(0LL,query(1,0,n-1,0,n-1))<<'\n';
}
}
