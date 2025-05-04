#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using pll=std::pair<ll,ll>;
using namespace std;
const int N=200050;
pll tree[N<<2];
ll lazy[N<<2];
ll arr[N];
pll combine(pll a,pll b){
    return make_pair(a.first+b.first,max(a.second,b.second));
}
void build(int start,int end,int node=1){
    if(start==end){
        tree[node].first=tree[node].second=arr[start];
    }else{
        int mid=(start+end)>>1;
        build(start,mid,node<<1);
        build(mid+1,end,node<<1|1);
        tree[node]=combine(tree[node<<1],tree[node<<1|1]);
    }
}
void push(int node,int start,int end){
    tree[node].first+=(end-start+1)*lazy[node];
    tree[node].second+=lazy[node];
    if(start!=end){
        lazy[node<<1]+=lazy[node];
        lazy[node<<1|1]+=lazy[node];
    }
    lazy[node]=0;
}
void upd(int node,int start,int end,int left,int right,ll val){
    push(node,start,end);
    if(start==left and end==right){
        tree[node].first+=(end-start+1)*val;
        tree[node].second+=val;
        if(start!=end){
            lazy[node<<1]+=val;
            lazy[node<<1|1]+=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    if(right<=mid){
        upd(node<<1,start,mid,left,right,val);
        push(node<<1|1,mid+1,end);
    }else if(mid<left){
        upd(node<<1|1,mid+1,end,left,right,val);
        push(node<<1,start,mid);
    }else{
        upd(node<<1,start,mid,left,mid,val);
        upd(node<<1|1,mid+1,end,mid+1,right,val);
    }
    tree[node]=combine(tree[node<<1],tree[node<<1|1]);
}
pll ans(int node,int start,int end,int left,int right){
    push(node,start,end);
    if(start==left and right==end){
        return tree[node];
    }
    int mid=(start+end)>>1;
    if(right<=mid){
        return ans(node<<1,start,mid,left,right);
    }else if(mid<left){
        return ans(node<<1|1,mid+1,end,left,right);
    }else{
        return combine(ans(node<<1,start,mid,left,mid),ans(node<<1|1,mid+1,end,mid+1,right));
    }
}
int main(){
    int n,q;cin>>n>>q;
    ll brr[n];
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    arr[0]=brr[0];
    for(int i=1;i<n;i++){
        arr[i]=arr[i-1]+brr[i];
    }
    build(0,n-1);
    while(q--){
        int choice;cin>>choice;
        if(choice==1){
            int a;ll val;cin>>a>>val;
            a--;
            upd(1,0,n-1,a,n-1,val-brr[a]);
            brr[a]=val;
        }else{
            int a,b;cin>>a>>b;
            a--,b--;
            ll x=ans(1,0,n-1,a,b).second;
            if(a){
                x-=ans(1,0,n-1,a-1,a-1).first;
            }
            cout<<max(x,0LL)<<endl;
        }
    }
}
 
