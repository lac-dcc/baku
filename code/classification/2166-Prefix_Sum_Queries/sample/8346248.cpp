#include<bits/stdc++.h>
using namespace std;
 
const int N=2e5+10;
 
int n,q;
vector<int>arr(N,0);
 
struct node{
    long long sum,pref;
    node (long long sum,long long pref) : sum(sum),pref(pref) {}
    node(long long x=0) : sum(x),pref(max(0ll,x)){}
    friend node operator+(const node  &a,const node &b){
        return {a.sum+b.sum,max(a.pref,a.sum+b.pref)};
    }
 
} seg[4*N];
 
void build(int i,int low,int high){
    if(low==high){
        seg[i]=node(arr[low]);
        return;
    }
 
    int mid=(low+high)/2;
    build(2*i+1,low,mid);
    build(2*i+2,mid+1,high);
 
    seg[i]=seg[2*i+1]+seg[2*i+2];
}
 
void update(int ind,int val,int i,int low,int high){
    if(low==high){
        seg[i]=node(val);
        return ;
    }
 
    int mid=(low+high)/2;
 
    if(mid>=ind) update(ind,val,2*i+1,low,mid);
    else update(ind,val,2*i+2,mid+1,high);
 
    seg[i]=seg[2*i+1]+seg[2*i+2];
}
 
node query(int i,int low,int high,int l,int r){
    if(low>r || high<l) return 0;
    if(low>=l && high<=r) return seg[i];
 
    int mid=(low+high)/2;
 
    node lf=query(2*i+1,low,mid,l,r),rg=query(2*i+2,mid+1,high,l,r);
 
    return lf+rg;
}
 
 
int main(){
    int n,q;
    cin>>n>>q;
 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
 
    build(0,0,n-1);
 
    for(int i=0;i<q;i++){
        int opt;
        cin>>opt;
        if(opt==1){
            int k,u;
            cin>>k>>u;k--;
            update(k,u,0,0,n-1);
        }
        else{
            int x,y;
            cin>>x>>y;
            x--;y--;
            node ans=query(0,0,n-1,x,y);
            cout<<ans.pref<<endl;
        }
    }
 
    return 0;
}
