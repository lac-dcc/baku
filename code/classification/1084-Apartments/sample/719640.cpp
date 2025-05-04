#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <sstream>
 
using namespace std;
 
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while(!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx,
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss; ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
 
#ifndef ONLINE_JUDGE
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
 
#define MOD 1000000007
#define A first
#define B second
#define all(x) (x).begin(), (x).end
 
typedef long long ll;
 
inline int mulmd(ll a, ll b){
  ll ret = (a * b) % MOD;
  return (int) ret;
}
 
inline int power(ll x, ll y, int m){
  ll res = 1;
  x = x % m;
  while(y > 0){
    if(y & 1){
      res = mulmd(res, x);
    }
    y = y >> 1;
    x = mulmd(x, x);
  }
  return (int) res;
}
 
inline int submd(ll a, ll b){
  ll ret = (a - b);
  if(ret < 0) ret += MOD;
  return (int) ret;
}
 
inline int addmd(ll a, ll b){
  ll ret = (a + b) % MOD;
  return (int) ret;
}
 
inline int invPow(ll a){
  return power(a, MOD - 2, MOD);
}
 
inline int divmd(ll a, ll b){
  ll ret = mulmd(a, invPow(b));
  return (int) ret;
}
 
 
void solve(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for(int& i: a){
    cin >> i;
  }
  multiset<int> st;
  for(int& i: b){
    cin >> i;
    st.insert(i);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int cnt = 0;
  for(int i = 0; i < n; i++){
    auto v = st.lower_bound(max(a[i] - k, 0));
    if(v == st.end()) break;
    auto val = *v;
    if(abs(val - a[i]) <= k){
      cnt++;
      st.erase(st.lower_bound(max(a[i] - k, 0)));
    }
  }
  cout << cnt;
} 
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  //cin >> t;
  while(t--){
    solve();
  }
}
