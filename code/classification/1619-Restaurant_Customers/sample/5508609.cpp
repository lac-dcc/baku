/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
  	  			 ~ Andrew Tate
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
const ll mod = 1e9 + 7;
const ll maxn = 1e6;
const ll base = 31;
 
void file()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
}
 
int main()
{
	file();
	ll n; cin >> n;
	vector<pii> v;
	for(ll i=0;i<n;i++){
		ll x, y; cin >> x  >> y;
		v.push_back({x, 1});
		v.push_back({y, -1});
	}
	sort(v.begin(), v.end());
	ll ans = 0, cnt = 0;
	for(auto it: v){
		cnt += it.second;
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
 
