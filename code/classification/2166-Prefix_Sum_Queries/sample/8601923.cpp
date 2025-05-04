#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=-1e18;
const int N=8e5+5;
struct node
{
	int l,r;
	int sum;//???к? 
	int maxl;//????? 
	int maxr;//????? 
	int ans;//?????κ? 
}veg[N];
int a[N];
void pushup(int id)
{
	veg[id].sum=veg[id*2].sum+veg[id*2+1].sum;
	veg[id].maxl=max(veg[id*2].maxl,veg[id*2].sum+veg[id*2+1].maxl);
	veg[id].maxr=max(veg[id*2+1].maxr,veg[id*2+1].sum+veg[id*2].maxr);
	veg[id].ans=max(max(veg[id*2].ans,veg[id*2+1].ans),veg[id*2].maxr+veg[id*2+1].maxl);
}
void build(int id,int l,int r)
{
	veg[id]={l,r};
	if(l==r)
	{
		veg[id].sum=a[l];
		veg[id].maxl=a[l];
		veg[id].maxr=a[l];
		veg[id].ans=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	pushup(id);
}
void change(int id,int x,int k)
{
	if(veg[id].l==veg[id].r)
	{
		veg[id].sum=k;
		veg[id].maxl=k;
		veg[id].maxr=k;
		veg[id].ans=k;
		return ;
	}
	int mid=(veg[id].l+veg[id].r)/2;
	if(x<=mid) change(id*2,x,k);
	else change(id*2+1,x,k);
	pushup(id);
};
node find1(int id,int l,int r)
{
	if(l<=veg[id].l&&veg[id].r<=r) return veg[id];
	int mid=(veg[id].l+veg[id].r)/2;
	node ans=(node){0,0,INF,INF,INF,INF};
	node x,y;
	x=(node){0,0,INF,INF,INF,INF};
	y=(node){0,0,INF,INF,INF,INF};
	if(l<=mid&&r<=mid)
	{
		return x=find1(id*2,l,r);
	 } 
	if(r>mid&&l>mid) return y=find1(id*2+1,l,r);
	x=find1(id*2,l,r);
	y=find1(id*2+1,l,r);
	ans.maxl=max(0LL,max(x.maxl,x.sum+y.maxl));
	ans.sum=x.sum+y.sum;
	return ans;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1,1,n);
	while(m--)
	{
		int op;
		scanf("%lld",&op);
		int x,y;
		scanf("%lld%lld",&x,&y);
		if(op==1)
		{
			change(1,x,y);
		}
		else
		{
			printf("%lld\n",max(0LL,find1(1,x,y).maxl));
		}
	}
	return 0;
}
 
