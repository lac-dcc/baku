#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define long ll
#define endl "\n"
 
int ini() {int i; cin >> i; return i;}
long in()  {long l; cin >> l; return l;}
 
long *in(int n) {long *a = new long[n];for(int i=0;i<n;i++) a[i] = in();return a;}
 
void fill(map<long, long> &map, long val){map[val]++;}
void remove(map<long, long> &map, long val){map[val]--; if(map[val] == 0) map.erase(val);}
long lower(map<long, long> &map, long val){auto key = map.lower_bound(val);if(key == map.begin()) return -1;key--;return key->first;}
 
void pl(long l) {cout << l << endl;}
void pl(string s) {cout << s << endl;}
 
void solve() {
	int n = ini();
	int m = ini();
	map<long, long> map;
	for(int i=0;i<n;i++){
		long l = in();
		fill(map, l);
	}
	for(int i=0;i<m;i++){
		long val = in();
		if(map.count(val)){
			pl(val);
			remove(map, val);
		}
		else {
			auto key = lower(map, val);
			pl(key);
			remove(map, key);
		}
	}
}
 
int main () {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int t = 1;
	//cin>>t;
	
	for(int i=0; i<t; i++)
		solve();
}
