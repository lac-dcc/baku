#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
 
 
int main(){
	ll n,x; scanf("%lld %lld",&n,&x);
	vector<ll> v(n);
	for(ll i=0;i<n;i++) scanf("%lld",&v[i]);
	sort(v.begin(),v.end());
	vector<ll> a,b;
	for(ll i=0;i<n;i++)
		if(i<n/2) a.push_back(v[i]);
		else b.push_back(v[i]);
	
	unordered_map<ll,ll> ma; ma[0]=1;
	vector<ll> sum(1<<a.size(),0);
	ll res=0;
	for(ll mask=1;mask<(1<<a.size());mask++){
		ll pos=__builtin_ctz(mask);
		sum[mask]=a[pos]+sum[mask^(1<<pos)];
		if(sum[mask]<x) ma[sum[mask]]++;
		if(sum[mask]==x) res++;
	}
 
	sum.clear();
	sum.assign(1<<b.size(),0);
	for(ll mask=1;mask<(1<<b.size());mask++){
		ll pos=__builtin_ctz(mask);
		sum[mask]=b[pos]+sum[mask^(1<<pos)];
		if(ma.find(x-sum[mask])!=ma.end())
			res+=ma[x-sum[mask]];
	}
	printf("%lld\n",res);
	
	return 0;
}
