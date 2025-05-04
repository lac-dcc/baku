#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define s 202020
 
vector<vector<vector<ll>>> v(s);
vector<bool> Seen(s);
vector<ll> res(s);
 
int main() {
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		ll a,b,l;
		cin>>a>>b>>l;
		v[a].push_back({b,l});
	}
	priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> q;
	q.push({0,1});
	while(!q.empty()) {
		ll dist = q.top()[0];
		ll x = q.top()[1];
		q.pop();
		if(Seen[x]==false) {
			res[x] = dist;
			Seen[x] = true;
			for(auto t:v[x]) {
				if(Seen[t[0]]==false) {
					q.push({dist+t[1],t[0]});
				}
			}
		}
	}
	for(ll i=1;i<=n;i++) {
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}
