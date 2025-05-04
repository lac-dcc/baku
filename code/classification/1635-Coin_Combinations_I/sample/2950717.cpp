#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD 1000000007
#define MOD2 998244353
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, x; cin >> n >> x;
    vector<int> val(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    sort(val.begin(), val.end());
 
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for (int v = 1; v <= x; v++) {
        for (int i = 0; i < n; i++) {
            if (v - val[i] >= 0) {
                dp[v] += dp[v-val[i]];
                dp[v] %= MOD;
            } else {
                break;
            }
        }
    }
    cout << dp[x];
 
    return 0;
}
