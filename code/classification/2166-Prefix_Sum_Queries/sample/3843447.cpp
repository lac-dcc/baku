#include <bits/stdc++.h>
using namespace std;
long long a[200009];
long long b[200009];
struct lena{
	long long lazy,sum;
};
lena st[800009];
void push(int id){
	st[id*2].lazy+=st[id].lazy;
	st[id*2+1].lazy+=st[id].lazy;
	st[id*2].sum+=st[id].lazy;
	st[id*2+1].sum+=st[id].lazy;
	st[id].lazy=0;
}
void build(int id,int l,int r){
	if (l==r){
		st[id].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id].sum=max(st[id*2].sum,st[id*2+1].sum);
}
void update(int id,int l,int r,int u,int v,long long val){
	if (l>v||u>v||r<u)return;
	if (u<=l&&r<=v){
		st[id].lazy+=val;
		st[id].sum+=val;
		return;
	}
	int mid=(l+r)/2;
	push(id);
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	st[id].sum=max(st[id*2].sum,st[id*2+1].sum);
}
long long query(int id,int l,int r,int u,int v){
	if (l>v||u>v||r<u)return -10000000000000000;
	if (u<=l&&r<=v)return st[id].sum;
	int mid=(l+r)/2;
	push(id);
	return max(query(id*2,l,mid,u,v),query(id*2+1,mid+1,r,u,v));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen(".INP","r",stdin);
   // freopen(".OUT","w",stdout);
   int n,q;
   cin>>n>>q;
   for (int i=1;i<=n;i++){
   	cin>>a[i];
   	b[i]=a[i];
   	a[i]+=a[i-1];
   }
   build(1,1,n);
   for (int i=1;i<=q;i++){
   	int mode;
   	cin>>mode;
   	if (mode==1){
   		int k;
   		long long u;
   		cin>>k>>u;
   		update(1,1,n,k,n,u-b[k]);
   		b[k]=u;
   	}
   	else {
   		int l,r;
   		cin>>l>>r;
   		if (l==1)cout<<max(query(1,1,n,l,r),0ll)<<'\n';
   		else cout<<max(query(1,1,n,l,r)-query(1,1,n,l-1,l-1),0ll)<<'\n';
   	}
   }
   
}
