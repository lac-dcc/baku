#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> a(200005);
vector<pair<ll,ll>> st(800005);
void build(ll z,ll l,ll r){
	if (l==r){
		st[z].first=a[l];
		st[z].second=max(0ll,st[z].first);
		return;
	}
	build(z*2,l,(l+r)/2);
	build(z*2+1,(l+r)/2+1,r);
	st[z].first=st[z*2].first+st[z*2+1].first;
	st[z].second=max(st[z*2].second,st[z*2].first+st[z*2+1].second);
}
void change(ll z,ll l,ll r,ll ind,ll val){
	if (l==r && l==ind){
		st[z]={val,max(0ll, val)};
		return;
	}else if(l>ind||r<ind){
		return;
	}else{
		ll m=(l+r)/2;
		change(z*2,l,m,ind,val);
		change(z*2+1,m+1,r,ind,val);
		st[z].first=st[z*2].first+st[z*2+1].first;
		st[z].second=max(st[z*2].second,st[z*2].first+st[z*2+1].second);
	}
}
pair<ll,ll> ans(ll z,ll l,ll r,ll p,ll q){
	if (l>=p && r<=q) return st[z];
	if (l>q||r<p) return {0,0};
	ll m=(l+r)/2;
	pair<ll,ll> p1=ans(z*2,l,m,p,q);
	pair<ll,ll> p2=ans(z*2+1,m+1,r,p,q);
	return {p1.first+p2.first,max(p1.second,p2.second+p1.first)};
}
int main(){
	ll n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>a[i];
	build(1,0,n-1);
	while(q--){
		ll x,y,z;
		cin>>x>>y>>z;
		if (x==1){
			y--;
			change(1,0,n-1,y,z);
		}else{
			y--;z--;
			cout<<ans(1,0,n-1,y,z).second<<endl;
		}
	}
}
