#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <tuple>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
 
vector<ll> D(ll st, const vector<vector<ll>>& E) {
  vector<ll> ANS(E.size(), -1);
  deque<pll> Q;
  Q.push_back(make_pair(st, 0));
  while(!Q.empty()) {
    ll x,d;
    std::tie(x,d) = Q.front(); Q.pop_front();
    if(ANS[x]>=0) { continue; }
    ANS[x] = d;
    for(ll y : E[x]) {
      Q.push_back(make_pair(y, d+1));
    }
  }
  return ANS;
}
 
int main() {
  ll n;
  cin >> n;
  vector<vector<ll>> E(n, vector<ll>{});
  vector<ll> SEEN(n, 0);
  for(ll i=1; i<n; i++) {
    ll a,b;
    cin >> a >> b;
    a--; b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vector<ll> D0 = D(0, E);
  ll far0 = 0;
  for(ll i=0; i<n; i++) {
    if(D0[i] > D0[far0]) {
      far0 = i;
    }
  }
  vector<ll> D1 = D(far0, E);
  ll far1 = 0;
  for(ll i=0; i<n; i++) {
    if(D1[i] > D1[far1]) {
      far1 = i;
    }
  }
  vector<ll> D2 = D(far1, E);
 
  for(ll i=0; i<n; i++) {
    ll score = max(D1[i], D2[i]);
    cout << score << " ";
  }
  cout << endl;
}
