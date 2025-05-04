#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int P=1e9+7,Inv=(P+1)/2;
int main(void){
	ios::sync_with_stdio(false),cin.tie(0);
	LL n,ans=0;cin>>n;
	auto segSum=[&](LL i,LL j){
		return (j-i+1)%P*((i+j)%P)%P*Inv%P;
	};
	for(LL d=1;d<=n;d++){
		LL k=n/d,ld=n/k;
		(ans+=k*segSum(d,ld))%=P;
		d=ld;
	}
	printf("%lld\n",ans);
	return 0;
}