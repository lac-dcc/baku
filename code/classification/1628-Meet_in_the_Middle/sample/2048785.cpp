#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) i(int) x.size()
#define endl "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
vector <ll> v;
ll n, x, ans = 0;
 
struct custom{
    static uint64_t splitmix64(uint64_t x) {
    	x += 0x9e3779b97f4a7c15;
      x = (x^(x>>30))*0xbf58476d1ce4e5b9;
    	x = (x^(x>>27))*0x94d049bb133111eb;
      return x^(x>>31);
    }
    size_t operator()(uint64_t x) const{
      static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x+FIXED_RANDOM);
    }
};
 
unordered_map <ll, ll, custom> sts;
 
void getAll(int n1, int c, int fg){
	int cnt = 0;
	for(int i = 0; i < (1<<n1); i++){
		ll s = 0;
		for(int j = 0; j < n1; j++){
			if(i&(1<<j)){
				s += v[j+c];
			}
		}
		if(fg == 0)
			sts[s]++;
		else if(sts.count(x-s))
			ans += sts[x-s];
	}
}
 
void solve(){
	getAll(n/2, 0, 0);
	getAll(n-n/2, n/2, 1);
}
 
int main(){
	cin >> n >> x;
	v.resize(n);
	for(auto &i : v)
		cin >> i;
	ans = 0;
	solve();
	cout << ans << endl;
	return 0;
}
