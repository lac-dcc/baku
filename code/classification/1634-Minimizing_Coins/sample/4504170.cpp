// Author: Shivank
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define tc int t; cin >> t; while(t--)
#define all(v) v.begin(), v.end()
int n, x;
vector<int> v(1000013);
vector<int> dp(1000013, -1);
 
int rec(int x) {
    if (x < 0) return INT_MAX;
    if (x == 0) return 0;
    if (dp[x] != -1) return dp[x];
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(rec(x - v[i]) + 1, ans);
    }
    return dp[x] = ans;
 
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    
    cin >> n >> x;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (rec(x) == INT_MAX) cout << -1 << endl;
    else
    cout << rec(x);
 
}
