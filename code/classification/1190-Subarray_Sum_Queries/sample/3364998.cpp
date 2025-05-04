#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
struct node{
	ll sum;
	ll val;
	ll pref;
	ll suf;
	node(){
		sum = 0;
		val = 0;
		pref = 0;
		suf = 0;
	}
};
vector<node> segtree;
void maketree(int pos,ll val,int now,int l,int r){
	if(l == r){
		segtree[now].val = max((ll)0,val);
		segtree[now].sum = val;
		segtree[now].pref = max((ll)0,val);
		segtree[now].suf = max((ll)0,val);
		return;
	}
	int mid = (l+r)/2;
	if(mid>=pos){
		maketree(pos,val,now*2+1,l,mid);
	}
	else maketree(pos,val,now*2+2,mid+1,r);
	segtree[now].val = max(segtree[now*2+1].val,segtree[now*2+2].val);
	segtree[now].val = max(segtree[now].val,segtree[now*2+1].suf+segtree[now*2+2].pref);
	segtree[now].pref = max(segtree[now*2+1].pref,segtree[now*2+2].pref+segtree[now*2+1].sum);
	segtree[now].suf = max(segtree[now*2+1].suf+segtree[now*2+2].sum,segtree[now*2+2].suf);
	segtree[now].sum = segtree[now*2+1].sum+segtree[now*2+2].sum;
	return;
}
int main(){
	int n,m;
	cin>>n>>m;
	segtree = vector<node>(n*4,node());
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		maketree(i,k,0,0,n-1);
	}
	for(int i = 0;i<m;i++){
		int a;
		ll b;
		cin>>a>>b;
		maketree(a-1,b,0,0,n-1);
		cout<<segtree[0].val<<'\n';
	}
}
