#include <bits/stdc++.h>
using ll = long long;
using namespace std;
 
ll n, x;
 
void populate(vector <ll>& v, ll t[], ll number, ll displacement){
	for(int i = 0; i < (1 << number); ++i){
		ll sum = 0;
		for(int j = 0; j < number; ++j){
			if(((i >> j) & 1) == 1){
				sum += t[j + displacement];
			}
		}
		v.push_back(sum);
	}
}
 
void populate_recursive(vector <ll>& v, ll t[], ll number, ll displacement, int ix = 0, ll sum = 0){
	if(ix == number){
		v.push_back(sum);
		return;
	}
	populate_recursive(v, t, number, displacement, ix + 1, sum + t[ix + displacement]);
	populate_recursive(v, t, number, displacement, ix + 1, sum);
}
 
int main(){
	cin >> n >> x;
	ll t[n];
	for(int i = 0; i < n; ++i) cin >> t[i];
	
	vector <ll> v1;
	populate_recursive(v1, t, n / 2, 0);
	
	vector <ll> v2;
	populate_recursive(v2, t, n - n / 2, n / 2);
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	ll ans = 0;
	for(const ll& a: v1){
		ans += (upper_bound(v2.begin(), v2.end(), x - a) 
				- lower_bound(v2.begin(), v2.end(), x - a)); 
	}
	
	cout << ans;
	return 0;
}
 
 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do something instead of nothing and stay organized
*/
