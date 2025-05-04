#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> indexed_set;
 
typedef tree<int, null_type, greater<int>, rb_tree_tag, 
tree_order_statistics_node_update> r_indexed_set;
 
// <value, idx>
// <value, 0> for lower_bound
// <value, idx> for find
// <value, INT_MAX> for upper_bound
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, 
tree_order_statistics_node_update> indexed_multiset;
 
// <value, idx>
// <value, INT_MAX> for lower_bound
// <value, idx> for find
// <value, 0> for upper_bound
typedef tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag, 
tree_order_statistics_node_update> r_indexed_multiset;
 
typedef long long ll;
const ll M = 1e9 + 7;
 
ll mul(ll a, ll b) {
    return ((a % M) * (b % M)) % M;
}
 
// Top, right, down, left
// const int DIR_LEN = 4;
// int dr[DIR_LEN] = {-1, 0, 1, 0};
// int dc[DIR_LEN] = {0, 1, 0, -1};
 
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    ll sum = 0;
    ll mx = LLONG_MIN;
 
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        if (sum + a[i] > 0) {
            sum += a[i];
            mx = max(mx, sum);
        }
        else {
            sum = 0;
        }
    }
 
    cout << mx;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    solve();
 
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
 
    return 0;
}
