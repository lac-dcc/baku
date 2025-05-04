#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
template<typename T1, typename T2> istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); } // cin >> pair<T1, T2>
template<typename T> istream& operator>>(istream &istream, vector<T> &v){ for (auto &it : v) cin >> it; return istream; } // cin >> vector<T>
template<typename T1, typename T2> ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }  // cout << pair<T1, T2>
template<typename T> ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; } // cout << vector<T>
 
const int mod = (int)(1e9+7);
const int inf = LONG_LONG_MAX;
const int PI = acos((long double)-1.0);
const int dx[4] = {1, 0,-1, 0}, dy[4] = {0, 1, 0,-1};
 
typedef tree<int, null_type, less<int>,
rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
int binpow(int a, int n){
	if(n==0) return 1;
	if(n%2==1) return binpow(a, n-1)*a;
	else{
		int b=binpow(a, n/2);
		return b*b;
	}
}
 
void setIO(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
 
void solve(void) {
	int n, m;
	cin >> n >> m;
	vector < pair <int,int>> g[n];
	for(int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --,v--;
		int w;
		cin >> w;
		g[u].push_back({v,w});
	}
	vector <int> d(n,inf);
	d[0] = 0;
	priority_queue <pair <int,int>> q;
	q.push({0,0});
	while(!q.empty()) {
		int v = q.top().second, cur = -q.top().first;
		q.pop();
		if(cur > d[v]) continue;
		for(int i = 0; i < g[v].size(); i ++) {
			int to = g[v][i].first;
			int len = g[v][i].second;
			if(d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push(make_pair(-d[to],to));
			}
		}
	}
	for(auto i : d) cout << i << " ";
}
 
signed main(void) {
	int t = 1;
	//cin >> t;
	while(t --) solve();
	return 0;
}
 
const int too_slow=[](){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	return 0;
}();
 
/*
   _____________
 //             \
 || Olymp Staff ||
 \             //
 
 */