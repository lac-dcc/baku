#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=1e3;
int n;
ll x, a[mxN], y;
 
int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	y=uniform_int_distribution<int>(69, 69696969)(rng);
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	unordered_map<int, ar<int, 2>> mp;
	mp.reserve(1<<20);
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j)
			if(mp.find((x-a[i]-a[j])^y)!=mp.end()) {
				ar<int, 2> p=mp[(x-a[i]-a[j])^y];
				cout << i+1 << " " << j+1 << " " << p[0]+1 << " " << p[1]+1;
				return 0;
			}
		for(int j=0; j<i; ++j)
			mp[(a[i]+a[j])^y]={i, j};
	}
	cout << "IMPOSSIBLE";
}