#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
 
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
 
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
 
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T> >;
 
 
template<class T> istream& operator >> (istream &is, vector<T>& V) {
  for (auto &e : V)
    is >> e;
  return is;
}
template<class T, size_t N> istream& operator >> (istream &is, array<T, N>& V) {
  for (auto &e : V)
    is >> e;
  return is;
}
#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 const& value) {
  static char buffer[64];
  int index = 0;
  __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
  if (value < 0)
    os << '-';
  else if (T == 0)
    return os << '0';
  for (; T > 0; ++index) {
    buffer[index] = static_cast<char>('0' + (T % 10));
    T /= 10;
  }
  while (index > 0)
    os << buffer[--index];
  return os;
}
istream& operator >> (istream& is, __int128& T) {
  static char buffer[64];
  is >> buffer;
  size_t len = strlen(buffer), index = 0;
  T = 0; int mul = 1;
  if (buffer[index] == '-')
    ++index, mul *= -1;
  for (; index < len; ++index)
    T = T * 10 + static_cast<int>(buffer[index] - '0');
  T *= mul;
  return is;
}
#endif
template<typename CharT, typename Traits, typename T>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, T const &val) {
  return (out << val << " ");
}
template<typename CharT, typename Traits, typename T1, typename T2>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, pair<T1, T2> const &val) {
  return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename CharT, typename Traits, template<typename, typename...> class TT, typename... Args>
ostream& operator << (std::basic_ostream<CharT, Traits> &out, TT<Args...> const &cont) {
  out << "[ ";
  for (auto && elem : cont) _containerprint(out, elem);
  return (out << "]");
}
template<class L, class R> ostream& operator << (ostream& out, pair<L, R> const &val) {
  return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename L, size_t N> ostream& operator << (ostream& out, array<L, N> const &cont) {
  out << "[ ";
  for (auto && elem : cont) _containerprint(out, elem);
  return (out << "]");
}
template<class T> ostream& operator<<(ostream &out, ordered_set<T> const& S) {
  out << "{ ";
  for (const auto& s : S) out << s << " ";
  return (out << "}");
}
template<class L, class R, class chash = std::hash<L> > ostream & operator << (ostream &out, gp_hash_table<L, R, chash> const& M) {
  out << "{ ";
  for (const auto& m : M) out << "(" << m.first << ":" << m.second << ") ";
  return (out << "}");
}
template<class P, class Q = vector<P>, class R = less<P> > ostream & operator << (ostream& out, priority_queue<P, Q, R> const& M) {
  static priority_queue<P, Q, R> U;
  U = M;
  out << "{ ";
  while (!U.empty())
    out << U.top() << " ", U.pop();
  return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M) {
  static queue<P> U;
  U = M;
  out << "{ ";
  while (!U.empty())
    out << U.front() << " ", U.pop();
  return (out << "}");
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
#else
#define trace(...) 1
#endif
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN, long long r = LLONG_MAX) {
  uniform_int_distribution<int64_t> generator(l, r);
  return generator(rng);
}
struct custom_hash {  // unordered_map<ll, int, custom_hash> safe_map;// use this
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
  template<typename L, typename R>
  size_t operator()(pair<L, R> const& Y) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
  }
};
 
#define ll long long
#define endl "\n"
#define all(v) (v).begin(),(v).end()
#define rep(i,x,y) for(long long i=x; i<=y; i++)
const int mod = 1e9 + 7;
unordered_map<ll, int, custom_hash> safe_map;
 
const int mxn = 1e6 + 5;
 
vector<int> adj[mxn], par(mxn), ans, dist(mxn);
vector<bool> visited(mxn);
 
 
void task() {
  int n, m, a, b;
  cin >> n >> m;
  rep(i, 0, m - 1) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
 
  queue<int>q;
  visited[1] = 1;
  par[1] = -1;
  q.push(1);
  dist[1] = 1;
  while (!q.empty()) {
 
    int node = q.front();
    q.pop();
 
    for (int child : adj[node]) {
 
      if (!visited[child]) {
        visited[child] = 1;
        par[child] = node;
        q.push(child);
        dist[child] = 1 + dist[node];
 
      }
 
    }
 
  }
  if (!visited[n])cout << "IMPOSSIBLE" << endl;
  else {
    cout << dist[n] << endl;
 
    for (int parent = n ; parent != -1; parent = par[parent]) {
      ans.push_back(parent);
    }
 
    reverse(all(ans));
    for (int i : ans)cout << i << " ";
 
  }
 
 
}
 
int main()
{
 
 
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int l = 1  ;
  // cin >> l;
  for (int i = 0; i < l; i++) task();
}
 
