#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7;
void solve() {
    int n, m; cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    } 
    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int x : a) {
        for (int i = x; i <= m; i++) {
            dp[i] = (dp[i] + dp[i - x]) % MOD;
        }
    }
    cout << dp[m] << endl;
}
int main() {
    solve();
}