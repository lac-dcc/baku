#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define frfr  freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define endl "\n"
#define loop(i,n) for(int i=0;i<n;i++)
#define ll long long int
 
void solve(){
	ll n,m;
	cin >> n >> m;
	multiset<ll , greater<ll>> mu;
	while(n--){
		ll x ; cin >> x;
		mu.insert(x);
	}
	while(m--){
		ll x ; cin >> x;
		auto it = mu.lower_bound(x);
		if(it != mu.end()){
			cout << *it << endl;
			mu.erase(it);
		}else{
			cout << -1 << endl;
		}
	}
}
int main()
{
	//IOS;
	//frfr;
	//int te;
	//cin >> te;
	//while(te--){
		solve();
	//}
	return 0;
}
