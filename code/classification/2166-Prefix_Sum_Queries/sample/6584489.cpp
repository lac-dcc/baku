#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
const ll llmx = 1e18;
struct node{
	ll val = -llmx, tag = 0;
	ll add(){
		return val+tag;
	}
};
vector<ll> v,sum;
vector<node> tree;
 
void bui(int id,int l,int r){
	if(l==r){
		tree[id].val=sum[l];
		return;
	}
	int mid=l+r>>1;
	
	bui(id<<1 , l , mid);
	bui(id<<1|1 , mid+1 , r);
	tree[id].val=max(tree[id<<1].val,tree[id<<1|1].val);
	return;
	
}
void push(int id){
	tree[id<<1].tag+=tree[id].tag;
	tree[id<<1|1].tag+=tree[id].tag;
	tree[id].val+=tree[id].tag;
	tree[id].tag=0;
	return;
}
void modify(int id,int l,int r,int ql,int qr,int qv){
	if(ql<=l and r<=qr){
		tree[id].tag+=qv;
		return;
	}
	int mid=l+r>>1;
	push(id);
	if(ql<=mid)modify(id<<1,l,mid,ql,qr,qv);
	if(qr>mid)modify(id<<1|1,mid+1,r,ql,qr,qv);
	tree[id].val=max(tree[id<<1].add(),tree[id<<1|1].add());
	return;
}
ll query(int id,int l,int r,int ql,int qr){
	if(ql<=l and r<=qr){
		return tree[id].add();
	}
	ll re=-llmx;
	int mid=l+r>>1;
	push(id);
	if(ql<=mid)re=max(re,query(id<<1,l,mid,ql,qr));
	if(qr>mid)re=max( re , query(id<<1|1,mid+1,r,ql,qr) );
	return re;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,q;
	cin>>n>>q;
	v.resize(n+1);
	tree.resize(n<<2);
	sum.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
		sum[i]=sum[i-1]+v[i];
	}
	bui(1,0,n);
	
	while(q--){
		
		ll t,a,b;
		cin>>t>>a>>b;
		if(t&1){
			modify(1,0,n,a,n,b-v[a]);
			v[a]=b;
		}
		else{
			cout<<query(1,0,n,a-1,b)-query(1,0,n,a-1,a-1)<<"\n";
		}
	}
}
