#include<bits/stdc++.h>
using namespace std;
string debug_string(const string& s) {
	return '"' + s + '"';
}
string debug_string(bool b) {
	return (b ? "true" : "false");
}
string debug_string(const char* s) {
	return debug_string((string)s);
}
template<class T, class U>
string debug_string(const pair<T, U>& p);
template<class U>
struct can_be_string {
	template<typename...>
	static int f(...) {
		return 0;
	}
	template<typename T>
	static char f(decltype(to_string(T()), char())) { 
		return 'a';
	}
	static const bool value = sizeof(f<U>(char())) == sizeof(char);
};
template<class T> 
typename enable_if<can_be_string<T>::value, string>::type debug_string(const T& a) {
	string s = to_string(a);
	return s;
}
template<class T>
typename enable_if<!can_be_string<T>::value, string>::type debug_string(const T& a) {
	bool first = true;
	string s = "{";
	for (const auto& x : a) {
		if(!first){
			s += ", ";
		}
		first = false;
		s += debug_string(x);
	}
	s += "}";
	return s;
}
template<class T, class U>
string debug_string(const pair<T, U>& p) {
	string s = "(";
	s += debug_string(p.first);
	s += ", ";
	s += debug_string(p.second);
	s += ")";
	return s;
}
void debug_out() {cerr << '\n';}
template<class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
	cerr << ' ' << debug_string(head);
	debug_out(tail...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
const int inf = 1e9 + 100;
const ll inf64 = 1e18l + 100;
vector<vector<int>> graph;
vector<int> visited;
vector<int> dist;
vector<int> p;
void dfs(int a) {
	visited[a] = 1;
	for (int x : graph[a]) {
		if (visited[x] == 0) {
			dfs(x);
		}
	}
}
void bfs(int a) {
	queue<int> q;
	q.push(a);
	p[a] = -1;
	dist[a] = 1;
	while (!q.empty()) {
		int node = q.front();
		int d = dist[node];
		q.pop();
		visited[node] = 1;
		for (auto x : graph[node]) {
			if (visited[x] == 0 && dist[x] > d + 1) {
				q.push(x);
				dist[x] = d + 1;
				p[x] = node;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(20);
	int n, m;
	cin >> n >> m;
	graph.resize(n);
	visited.resize(n);
	dist.resize(n, inf);
	p.resize(n);
	for (int i = 0;i < m;++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bfs(0);
	if (dist[n - 1] == inf) {
		cout << "IMPOSSIBLE" << '\n';
		return 0;
	}
	cout << dist[n - 1] << '\n';
	int node = n - 1;
	vector<int> answer;
	while (node != -1) {
		answer.push_back(node + 1);
		node = p[node];
	}
	reverse(answer.begin(), answer.end());
	for (int x : answer) {
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}
