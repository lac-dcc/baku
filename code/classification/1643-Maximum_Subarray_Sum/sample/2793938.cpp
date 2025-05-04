#include <bits/stdc++.h>
#define long long long
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define REP(i, b) for (int i = 0, _b = (b); i < _b; ++i)
#define FORE(i, a) for (__typeof((a).begin()) i = (a).begin(); i != a.end(); ++i)
#define EACH(x, a) for (auto& x : a)
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define taskname ""
#define file \
        freopen(taskname".inp", "r", stdin); \
        freopen(taskname".out", "w", stdout)
#define debug(...) cout << "#" << __LINE__ << ": [" << #__VA_ARGS__ \
<< "] = [" ,DBG(__VA_ARGS__)
 
using namespace std;
 
string to_string(const string& s) { return '"' + s + '"'; }
void DBG() { cout << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
        cout << to_string(h); if(sizeof...(t)) cout << ", "; DBG(t...);
}
 
template<class T> inline bool minimize(T &x, const T &y) {
    if (x > y) {x = y; return true;}
    return false;
}
 
template<class T> inline bool maximize(T &x, const T &y) {
    if (x <= y) {x = y; return true;}
    return false;
}
 
template<class A> void read(vector<A>& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class T> void read(T& x) {cin >> x;}
void read(double& d) {
    string t;
   	read(t);
  	d = stod(t);
}
 
template<class H, class... T> void read(H& h, T&... t) {
   	read(h);
   	read(t...);
}
template<class A> void read(vector<A>& x) {
   	EACH(a, x) read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
   	EACH(a, x) read(a);
}
     
string to_string(char c) {
  	return string(1, c);
}
string to_string(bool b) {
   	return b ? "true" : "false";
}
string to_string(const char* s) {
   	return string(s);
}
string to_string(string s) {
   	return s;
}
string to_string(vector<bool> v) {
  	string res;
   	REP(i, v.size()) res += char('0' + v[i]);
    	return res;
}
     
template<size_t S> string to_string(bitset<S> b) {
    string res;
   	REP(i, S)
   		res += char('0'+b[i]);
   	return res;
}
template<class T> string to_string(T v) {
    bool f = 1;
    string res;
    EACH(x, v) {
   		if(!f) res += ' ';
    	f = 0;
    	res += to_string(x);
    }
    return res;
}
     
template<class A> void write(A x) {cout << to_string(x);}
template<class H, class... T> void write(const H& h, const T&... t) { 
  	write(h);
   	write(t...);
}
void print() {write('\n');}
template<class H, class... T> void print(const H& h, const T&... t) { 
   	write(h);
   	if(sizeof...(t)) write(' ');
   	print(t...);
}
// ----------------------------------------------------------
 
typedef pair<int, int> ii;
const long inf = 1e18;
const int mod = 1e9+7;
#define left __lft
#define right __rght
#define maxn
 
// ----------------------------------------------------------
 
void init() {
}
 
void input() {
}
 
void output() {
}
 
#define val first
#define type second
 
signed main() {
    fastio;
    // file;
#ifndef ONLINE_JUDGE
    bool File = freopen("in", "r", stdin);
    if (!File) {
        cout << "FILE ERROR!" << endl;
        return 0;
    }
#endif
 
    int n; read(n);
    vector<long> ar(n+1); FOR(i, 1, n) read(ar[i]);
    vector<vector<long>> dp(n+1, vector<long>(2, 0));
    dp[0][0] = ar[1]; dp[0][1] = -inf;
    FOR(i, 1, n) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = max(ar[i], ar[i]+dp[i-1][1]);
    }
    print(max(dp[n][0], dp[n][1]));
    return 0;
}
 
