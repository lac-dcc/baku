#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
 
using str = string;
using ll = long long;
using ld = long double;
using u64 = unsigned long long;
 
template<class T>
using pr = pair<T, T>;
template<class T>
using vt = vector<T>;
template<class T>
using vvt = vector<vt<T>>;
 
#define ar array
#define pb push_back
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define len(x) (int)(x).size()
#define elif else if
#define def function
 
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define rep(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define each(x, a) for (auto& x: a)
#define r_each(x,a) for(auto& x:a | views::reverse)
 
template<class T>
constexpr T inf = 0;
template<>
constexpr int inf<int> = 1'000'000'005;
template<>
constexpr long long inf<long long> = (long long) (inf<int>) * inf<int> * 2;
template<>
constexpr unsigned int inf<unsigned int> = inf<int>;
template<>
constexpr unsigned long long inf<unsigned long long> = inf<long long>;
template<>
constexpr double inf<double> = inf<long long>;
template<>
constexpr long double inf<long double> = inf<long long>;
 
template<class T, class S>
inline bool ctmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template<class T, class S>
inline bool ctmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
 
template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {os << p.first << " " << p.second;return os;}
template<typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {is >> p.first >> p.second;return is;}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {int s = (int) v.size();for (int i = 0; i < s; i++) os << (i ? " " : "") << v[i];return os;}
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {for (auto &x: v) is >> x;return is;}
void read() {}
template<typename T, class... U>
void read(T &t, U &...u) {cin >> t;read(u...);}
void print() { cout << "\n"; }
template<typename T, class... U, char sep = ' '>
void print(const T &t, const U &...u) {cout << t;if (sizeof...(u)) cout << sep;print(u...);}
void write() { cout << " "; }
template<typename T, class... U, char sep = ' '>
void write(const T &t, const U &...u) {cout << t;if (sizeof...(u)) cout << sep;write(u...);}
#define Int(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define Ll(...)   \
  long long __VA_ARGS__; \
  read(__VA_ARGS__)
#define Str(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define Vt(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define Die(...)             \
  do {                       \
    print(__VA_ARGS__); \
    return;                  \
  } while (0)
 
inline int lsb(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }
inline int ctz(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }
inline int msb(const u64 &a) { return a ? 63 - __builtin_clzll(a) : -1; }
template<typename T>
inline int gbit(const T &a, int i) {
    return (a >> i) & 1;
}
template<typename T>
inline void sbit(T &a, int i, bool b) {
    if (gbit(a, i) != b) a ^= T(1) << i;
}
constexpr long long Pw(int n) { return 1LL << n; }
constexpr long long Msk(int n) { return (1LL << n) - 1; }
 
template<typename T>
vector<int> argsort(const vector<T> &A) {
    vector<int> ids((int) A.size());
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(),
         [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
    return ids;
}
void color_em(int node,int cc,int color[],vector<int>adj[],bool im)
{   if(!color[node]) return;
    color[node]=cc;
    int nc=(cc==1)?2:1;
    for(auto u:adj[node])
    {
        if(color[u]==cc) {im=true;return;}
        if(color[u]==0){color_em(u,nc,color,adj,im);}
 
    }
}
void solve() {
 
}
int N, M;
vector<int> adj[200005];
int color[100005];
bool impossible = false;
 
void color_em (int node, int cc) {
    if (color[node] != 0) return;
    color[node] = cc;
    int nc = (cc == 1) ? 2 : 1;
    for (auto fr : adj[node]) {
        if (color[fr] == cc) {impossible = true; return;}
        if (color[fr] == 0) {color_em(fr, nc);}
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    Int(T);
//    rep(T){
//        solve();
//    }
//solve();
 
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    for (int i = 1; i <= N; i++) {
        if (color[0] == 0)
            color_em(i, 1);
    }
 
    if (impossible) cout << "IMPOSSIBLE";
    else
        for (int i = 1; i <= N; i++) cout <<  color[i] << ' ';
    cout << endl;
}
