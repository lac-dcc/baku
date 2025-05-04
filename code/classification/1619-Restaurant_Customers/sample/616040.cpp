#include <bits/stdc++.h>
using namespace std;
 
#define for1(i, n) for (ll i = 1; i <= n; ++i)
#define for0(i, n) for (ll i = 0; i < n; ++i)
#define vll vector<ll>
#define fast std::ios_base::sync_with_stdio(false);
#define ll long long int
#define etc \
  ll t;     \
  cin >> t; \
  while (t--) solve();
#define ntc solve();
#define pb push_back
#define mp make_pair
 
void solve() {
  vector<pair<ll, bool>> v;
 
  ll n;
  cin >> n;
 
  for0(i, n) {
    ll a, b;
    cin >> a >> b;
    v.pb({a, 1});
    v.pb({b, 0});
  }
 
  sort(v.begin(), v.end());
  ll curr = 0, maxx = 0;
 
  for0(i, (ll)v.size()) {
    curr += v[i].second ? 1 : -1;
    maxx = max(maxx, curr);
  }
 
  cout << maxx;
}
 
int main() { fast ntc return 0; }
