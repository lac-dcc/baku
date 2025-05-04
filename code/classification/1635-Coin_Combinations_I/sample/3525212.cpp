#include <bits/stdc++.h>
using namespace std;
using LL = long long;
 
LL n, x, p[110], dp[int(1e6+10)];
const LL mod = 1e9+7;
 
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> n >> x;
    dp[0] = 1;
    for (int i=0; i<n; i++) cin >> p[i];
    for (int i=1; i<=x; i++) {
        for (int j=0; j<n; j++) {
            if (i >= p[j]) dp[i] = (dp[i]+dp[i-p[j]])%mod;
        }
    }
    cout << dp[x] << endl;
}