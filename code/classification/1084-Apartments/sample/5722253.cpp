#include<bits/stdc++.h>
using namespace std;
 
void __print(int x) {cerr << x;} void __print(long x) {cerr << x;} void __print(long long x) {cerr << x;} void __print(unsigned x) {cerr << x;} void __print(unsigned long x) {cerr << x;} void __print(unsigned long long x) {cerr << x;} void __print(float x) {cerr << x;} void __print(double x) {cerr << x;} void __print(long double x) {cerr << x;} void __print(char x) {cerr << '\'' << x << '\'';} void __print(const char *x) {cerr << '\"' << x << '\"';} void __print(const string &x) {cerr << '\"' << x << '\"';} void __print(bool x) {cerr << (x ? "true" : "false");} template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';} template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";} void _print() {cerr << "]\n";} template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
 
void test_case(){
	int n, m, k;
	cin >> n >> m >> k;
	
	vi a(n);
	for(int &i : a) cin >> i;
	
	map<int, int> cnt;
	set<int> b;
	
	for(int i = 0;i < m;i++){
		int x;
		cin >> x;
		cnt[x]++;
		b.insert(x);
	}
	
	long long ans = 0;
	
	sort(a.begin(), a.end());
	
	for(int i = 0;i < n;i++){
		// find min possible b[i] such that its ok
		auto pick = b.lower_bound(a[i] - k); // first value >= a[i] - k
		if(abs(a[i] - *pick) <= k){
			ans++;
			cnt[*pick]--;
			if(!cnt[*pick]) b.erase(pick);
		}
	}
	
	cout << ans << "\n";
 
}
 
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
	
	int tt = 1;
	//cin >> tt;
	
	while(tt--){
		test_case();
	}
	
	return 0x0;
}
 
