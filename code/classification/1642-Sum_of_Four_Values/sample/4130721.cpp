#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,k; cin>>n>>k;
	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];
	map<ll,pair<ll,ll>>sum;
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++)
		{
			if(sum.count(k-a[i]-a[j]))
			{
				cout<<i+1<<" "<<j+1<<" "
				    <<sum[k-a[i]-a[j]].first+1<<" "
				    <<sum[k-a[i]-a[j]].second+1;
				    return 0;
			}
		}
		for(ll j=0;j<i;j++) sum[a[i]+a[j]]={j,i};
	}
	cout<<"IMPOSSIBLE";
	return 0;
}
