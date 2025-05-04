#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
 
using namespace std;
using namespace __gnu_pbds;
 
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
 
typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): find_by_order(0) returns an iterator to the smallest element
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, c = 1;
    cin >> n;
    vector<array<ll, 3>> v(n);
    map<ll, ll> m;
    for(int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        m[v[i][0]], m[v[i][1]];
    }
    for(auto &u: m) {
        u.ss = c++;
    }
    vector<pair<ll, ll>> ending[c];
    for(int i = 0; i < n; i++) {
        v[i][0] = m[v[i][0]];
        v[i][1] = m[v[i][1]];
        ending[v[i][1]].pb({v[i][0], v[i][2]});
    }
    vector<ll> dp(c, 0);
    ll ans = 0;
    for(ll i = 1; i < c; i++) {
        dp[i] = dp[i - 1];
        for(auto &u: ending[i]) {
            dp[i] = max(dp[i], dp[u.ff - 1] + u.ss);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}