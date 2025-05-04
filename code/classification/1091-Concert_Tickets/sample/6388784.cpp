#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
void solve(){
	ll n, m; cin>>n>>m;
	ll arr[m];
	set <ll> s;
	map <ll, ll> mm;
 
	for(int i=0; i<n; i++){
		ll t; cin>>t;
		s.insert(t);
		mm[t]++;
	}
 
	s.insert(LLONG_MAX);
	s.insert(-1);
 
	for(int i=0; i<m; i++){
		ll key; cin>>key;
		auto it = s.upper_bound(key);
		it--;
		
		cout << *it << "\n";
		mm[*it]--;
		if(mm[*it] == 0){
			s.erase(*it);
		}
	}
}
 
int main(){
 
	ll q=1; 
	// cin>>q;
	while(q--){
		solve();
	}
 
	return 0;
}
