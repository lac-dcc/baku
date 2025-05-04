/*
    Author: WORTH
    Problem: Projects
*/
// Solution at end
 
#include <bits/stdc++.h>
 
using namespace std;
 
 
using Integer = int;
using Long = long long int;
using Character = char;
using boolean = bool;
using Boolean = bool;
using Float = float;
using Double = double;
using Void = void;
using String = string;
typedef unsigned long long ull;
typedef long double lld;
// #undef long
#define long int64_t
#define ArrayList vector
#define List vector
#define TreeMap map
#define HashMap unordered_map
#define MOD 0 // 1000000007 998244353
#define static
#define var auto
#define new
#define final constexpr
 
 
// Debugging template. Source: https://github.com/Priyansh19077/YouTube-links/blob/main/Debugging.cpp
#ifndef ONLINE_JUDGE
#define debug(x); cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
void _print(long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(T t) {cerr << t;}
 
 
class Scanner {
public:
 
	inline int nextInt() {
		int x;
		cin >> x;
		return x;
	}
 
	inline long nextLong() {
		long x;
		cin >> x;
		return x;
	}
 
	inline string next() {
		string x;
		cin >> x;
		return x;
	}
 
	inline double nextDouble() {
		double x;
		cin >> x;
		return x;
	}
 
	inline vector<int> nextIntArray(int n) {
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		return v;
	}
 
	template<typename UnaryMap>
	inline vector<int> nextIntArray(int n, UnaryMap apply) {
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			apply(v[i]);
		}
		return v;
	}
 
	inline vector<long> nextLongArray(int n) {
		vector<long> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		return v;
	}
 
	template<typename UnaryMap>
	inline vector<long> nextLongArray(int n, UnaryMap apply) {
		vector<long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			apply(v[i]);
		}
		return v;
	}
 
	inline vector<double> nextDoubleArray(int n) {
		vector<double> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		return v;
	}
 
	inline vector<vector<int>> nextIntMatrix(int n, int m) {
		vector<vector<int>> v(n, vector<int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> v[i][j];
		return v;
	}
 
	template<typename UnaryMap>
	inline vector<vector<int>> nextIntMatrix(int n, int m, UnaryMap apply) {
		vector<vector<int>> v(n, vector<int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
				apply(v[i][j]);
			}
		return v;
	}
 
	inline vector<vector<long>> nextLongMatrix(int n, int m) {
		vector<vector<long>> v(n, vector<long>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> v[i][j];
		return v;
	}
 
	template<typename UnaryMap>
	inline vector<vector<long>> nextLongMatrix(int n, int m, UnaryMap apply) {
		vector<vector<long>> v(n, vector<long>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
				apply(v[i][j]);
			}
		return v;
	}
 
	inline vector<vector<double>> nextDoubleMatrix(int n, int m) {
		vector<vector<double>> v(n, vector<double>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> v[i][j];
		return v;
	}
 
	inline vector<vector<char>> nextCharMatrix(int n, int m) {
		vector<vector<char>> v(n, vector<char>(m));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++)
				v[i][j] = s[j];
		}
		return v;
	}
 
};
class Printer {
public:
 
	ostream* out;
 
	Printer(ostream& out) : out(&out) {
		// setPrecision(20);
	}
 
	template <class T>
	inline void print(T val) {
		*out << val;
	}
 
	template <class T>
	inline void println(T val) {
		*out << val << '\n';
	}
 
	template <class T>
	inline void printArray(vector<T> v) {
		printArray(v, " ");
	}
 
	template <class T>
	inline void printArray(vector<T> v, string separator) {
		for (int i = 0; i < v.size() - 1; i++)
			*out << v[i] << separator;
		*out << v.back() << '\n';
	}
 
	// template<class T, typename UnaryMap>
	// inline void printArray(std::vector<T>& v, UnaryMap apply) {
	// 	printArray(v, " ", apply);
	// }
 
	template<class T, typename UnaryMap>
	inline void printArray(std::vector<T> v, string separator, UnaryMap apply) {
		for (int i = 0; i < v.size() - 1; i++)
			*out << apply(v[i]) << separator;
		*out << apply(v.back()) << '\n';
	}
 
	inline void flush() {
		out->flush();
	}
 
};
Scanner sc;
Printer out(cout);
 
int lowerBound(vector<vector<int>>& p, int n, int x) {
	int l = 0, r = n, m;
	while (l < r) {
		m = (l + r) >> 1;
		if (p[m][1] >= x)
			r = m;
		else
			l = m + 1;
	}
	return r;
}
 
void solve() {
	int n = sc.nextInt();
	auto p = sc.nextIntMatrix(n, 3);
 
	auto compare = [](vector<int>& asd, vector<int>& jkl) {
		return asd[1] < jkl[1];
	};
	sort(p.begin(), p.end(), compare);
 
	vector<long> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
 
		int prev = lowerBound(p, n, p[i - 1][0]) - 1;
		if (prev >= 0)
			dp[i] = max(dp[i], dp[prev + 1] + p[i - 1][2]);
		else
			dp[i] = max(dp[i], (long)p[i - 1][2]);
	}
 
	out.println(dp[n]);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	solve();
	return 0;
}
