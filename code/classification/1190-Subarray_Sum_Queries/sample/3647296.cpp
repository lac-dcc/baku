 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <cassert>
#include <cmath>
#define ll long long
 
using namespace std;
 
const int mx = 1e9 + 1;
int n, q, sz = 1;
vector<ll> p, t1, t2, t3, t4;
 
void update(int i, ll x) {
  int node = i + sz;
 
  t1[node] = x;
  t2[node] = max(0LL, x);
  t3[node] = max(0LL, x);
  t4[node] = max(0LL, x);
 
  node /= 2;
 
  while (node) {
    int left = 2*node, right = 2*node + 1;
 
    t1[node] = t1[left] + t1[right];
    t2[node] = max(t2[left], t1[left] + t2[right]);
    t3[node] = max(t3[left] + t1[right], t3[right]);
    t4[node] = max(max(t4[left], t4[right]), t3[left] + t2[right]);
 
    node /= 2;
  }
}
 
void solve() {
  cin >> n >> q;
  while (sz<n) sz *= 2;
 
  t1 = vector<ll>(2*sz);
  t2 = vector<ll>(2*sz);
  t3 = vector<ll>(2*sz);
  t4 = vector<ll>(2*sz);
 
  ll x;
  for (int i=0; i<n; i++) {
    cin >> x;
 
    t1[sz + i] = x;
    t2[sz + i] = max(0LL, x);
    t3[sz + i] = max(0LL, x);
    t4[sz + i] = max(0LL, x);
  }
 
  for (int node=sz-1; node>0; node--) {
    int left = 2*node, right = 2*node + 1;
 
    t1[node] = t1[left] + t1[right];
    t2[node] = max(t2[left], t1[left] + t2[right]);
    t3[node] = max(t3[left] + t1[right], t3[right]);
    t4[node] = max(max(t4[left], t4[right]), t3[left] + t2[right]);
  }
 
  int k;
  while (q--) {
    cin >> k >> x; k--;
 
    update(k,x);
    cout << t4[1] << "\n";
  }
}
 
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  solve();
}
