#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define ll long long
typedef pair<int, int> pii;
 
int n, x, w[1005], c[1005], dp[1005][100010];
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-w[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + c[i]);
        }
    }
    cout << dp[n][x];
}
