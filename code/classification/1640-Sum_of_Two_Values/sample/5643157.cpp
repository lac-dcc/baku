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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    set<pair<int, int>> s;
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert({a[i], i});
    }
 
    for (int i = 0; i < n; i++) {
        int b = x - a[i];
        auto it = s.lower_bound({b, 0});
        if (it != s.end()) {
            pair<int, int> p = *it;
            if (p.second == i) {
                if ((++it) == s.end()) {
                    continue;
                }
            }
 
            p = *it;
            if (p.first + a[i] == x && p.second != i) {
                cout << (i + 1) << " " << (p.second + 1);
                return;
            }
        }
    }
 
    cout << "IMPOSSIBLE";
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