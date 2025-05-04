#include <bits/stdc++.h>
 
using namespace std;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
#define FOR(i,j,k) for(int i=j;i<k;++i)
#define ROF(i,j,k) for(int i=j;i>=k;--i)
#define FFOR(i,k) FOR(i,0,k)
#define ROFF(i,j) ROF(i,j,0)
#define feach(i,k) for(auto& i:k)
#define ll long long
#define int long long
#define ld long double
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define eb emplace_back
#define maxheap(x) priority_queue<x>
#define minheap(x) priority_queue<x,vec<x>,greater<x>>
#define all(x) (x).begin(), (x).end()
#define INF 1e17
#define MOD ((int)1e9+7)
#define endl "\n"
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define start ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int maxx(int a, int b){
	return a>b?a:b;
}
void solve(){
	int n;
	cin>>n;
	vii t;
	for(int i=0;i<n;++i){
		int a,b;
		cin>>a>>b;
		t.push_back({a,1});
		t.push_back({b,-1});
	}
	sort(all(t),[](auto a, auto b){return a.first>b.first;});
	debug(t);
	int cur = 0;
	int ret = 0;
	for(auto a : t){
		if(a.second>=0 || a.second<0 && cur>0)
			cur += a.second;
		ret = max(ret, cur);
		//debug(cur,ret);
	}
	cout<<ret;
}
 
int32_t main(){
    start;
    //freopen("input.in","r",stdin);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
