#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
const int N = 1e6+10;
 
int dp[N];
int c[110];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <= x; i++) {
        dp[i] = MOD;
        for(int j = 1; j <= n; j++) {
            if(i >= c[j]) {
                dp[i] = min(dp[i], dp[i-c[j]]+1);
            }
        }
    }
    if(dp[x] == MOD) {
        dp[x] = -1;
    }
    cout << dp[x];
    return 0;
}
