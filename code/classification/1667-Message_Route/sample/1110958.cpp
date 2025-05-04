#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define umap unordered_map
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 
#define printVerdict(verdict) cout << (verdict ? "Yes": "No") << '\n'
#define printDecimal(d) cout << setprecision(d) << fixed
#define inrange(val, start, end) (val >= start && val <= end)
#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
 
template <class T1, class T2, class T3> 
void printTuple(tuple<T1, T2, T3> t) { cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n'; }
template <class T1, class T2>
void printPair(pair<T1, T2> p) { cout << p.first << " " << p.second << '\n'; }
template <class T>
void printArray(vector<T> arr) { for (int i = 0; i<size(arr); i++) {cout << arr[i] << " ";} cout << '\n'; }
template<class T>
void read(vector<T> &a, int n) { for (int i= 0; i<n; i++) cin >> a[i]; }
template<class T> 
void read(T* a, int n) { for (int i= 0; i<n; i++) cin >> a[i]; }
template<class T>
void readIdx(vector<pair<T, int>> &a, int n) { for (int i = 0; i<n; i++) { cin >> a[i].first; a[i].second = i; }}
 
int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin >> n >> m;
	vector<vector<int>> graph(n);
	for (int i = 0; i<m; i++) {
		int u,v; cin >> u >> v;
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<pair<int, int>> dist(n, make_pair(inf, -1));
	dist[0] = make_pair(1, 0);
	deque<int> Q;
	Q.push_back(0);
	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop_front();
		for (int neighbor : graph[curr]) {
			if (dist[neighbor].first > dist[curr].first + 1) {
				dist[neighbor] = make_pair(dist[curr].first + 1, curr);
				Q.push_back(neighbor);
			}
 		}
	}
	if (dist[n-1].first == inf) cout << "IMPOSSIBLE" << '\n';
	else {
		cout << dist[n-1].first << '\n';
		int curr = n-1;
		vector<int> ret;
		for (int i= 0; i<dist[n-1].first; i++) {
			ret.push_back(curr+1);
			curr = dist[curr].second;
		}
		reverse(ret.begin(), ret.end());
		printArray(ret);
	}
 }   
