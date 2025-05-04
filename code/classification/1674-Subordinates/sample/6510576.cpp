#include <bits/stdc++.h>
 
 
#define ll long long
using namespace std;
ll calc_subs (vector<vector<ll>> &adj_list, vector<ll> &subs, ll start) {
if (adj_list[start].empty()) {
  return 1;
}
ll ans = 0;
for (auto &i : adj_list[start]) {
  ans += calc_subs(adj_list, subs
,i );
}
subs [start] = ans;
return ans + 1;
}
 
 
int main() {
ll n;
cin >> n;
vector<ll> parent (n + 1);
parent [1] = -1;
for (ll i = 2; i <= n; ++i) {
cin >> parent[i];
}
vector<vector<ll>> adj_list (n + 1);
for (ll i = 2; i <= n; ++i) {
if (parent[i] != -1) {
adj_list[parent[i]].push_back(i);
}
}
vector<ll> subs (n + 1, 0);
calc_subs (adj_list, subs, 1);
for (ll i = 1; i <= n; ++i) {
cout << subs [i] << " ";
}
cout << "\n";
}
