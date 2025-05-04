#include <bits/stdc++.h>
#include <array>
#include <unordered_map>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
using ll = long long;
using ull = unsigned long long;
using vpi = vector<pair<int, int>>;
using pii = pair<ll, ll>;
 
using T = long double;
 
T pwr(T a, int b){
  if(b == 0) return T(1);
  if(b == 1) return T(a);
  T q = pwr(a, b / 2);
  q *= q;
  if(b & 1) q *= a;
  return q;
}
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; int x; cin >> n >> x;
  vector<int> a, b;
  for(int i = 0; i < n; i++){
    int v; cin >> v;
    if(i & 1) b.push_back(v);
    else a.push_back(v);
  }
  unordered_map<int, int> cnt;
  int len_a = a.size(), len_b = b.size();
  for(int i = 0; i < (1<<len_a); i++){
    int s = 0;
    for(int j = 0; j < len_a; j++){
      if(i & (1<<j)){
        s += a[j];
        s = min(s, x + 1);
      }
    }
    cnt[s]++;
  }
  ll res = 0;
  for(int i = 0; i < (1<<len_b); i++){
    int s = 0;
    for(int j = 0; j < len_b; j++){
      if(i & (1<<j)){
        s += b[j];
        s = min(s, x + 1);
      }
    }
    auto it = cnt.find(x - s);
    if(it != cnt.end()) res += it->second;
  }
  cout << res << '\n';
  return 0;
}
