# include <bits/stdc++.h>
using namespace std; typedef long long ll; void setIO(string file="") {if (!file.empty()) {freopen((file + ".in").c_str(), "r", stdin); freopen((file + ".out").c_str(), "w", stdout);}}
template<typename A, typename B> ostream& operator<<(ostream &o, const pair<A, B> &p) {return o << '[' << p.first << ", " << p.second << ']';}
template<typename Y, typename = typename enable_if<!is_same<Y, string>::value, typename Y::value_type>::type> ostream& operator<<(ostream &o, const Y &y) {o << '['; ll a=0; for (auto yy : y) {o << yy << ((++a)==(ll)y.size()?"":", ");} return o << ']';}
void dbgoutyay() {cerr << ']' << endl;} template<typename C, typename... D> void dbgoutyay(C c, D... d) {cerr << "  " << c; dbgoutyay(d...);} 
# define endl '\n' // remove this when need to flush buffer
# define dbg(...) cerr << '[' << #__VA_ARGS__ << ":", dbgoutyay(__VA_ARGS__)
 
void testcase() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> movies(n);
	for (auto &x : movies)
		cin >> x.second >> x.first; // end time, start time
	sort(movies.begin(), movies.end());
 
	int ans = 0;
	multiset<int> endtimes;
	for (int i = 0; i < k; i++)
		endtimes.insert(0);
 
	for (int i = 0; i < n; i++) {
		auto it = endtimes.upper_bound(movies[i].second);
		// dbg(endtimes, movies[i].second);
		if (it == begin(endtimes)) 
			continue;
		endtimes.erase(--it);
		endtimes.insert(movies[i].first);
		// dbg(endtimes);
		++ans;
	}
 
	cout << ans << endl;
	
 
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); cerr.tie(0);
	
	setIO("");
	
	int t = 1; 
	while (t--) testcase();
}