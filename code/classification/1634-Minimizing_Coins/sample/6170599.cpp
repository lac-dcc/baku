#include<bits/stdc++.h>
using namespace std;
 
const int INF = 1e9 + 5;
const int MX = 1e6 + 5;
int dp[MX];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0; i<n; i++)
        cin >> coins[i];
 
    dp[0] = 0;
    for(int i=1; i<=x; i++) {
        dp[i] = INF;
        for(int j=0; j<n; j++) {
            if(i-coins[j] >= 0) {
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
    }
    if(dp[x] == INF)
        cout << -1 << "\n";
    else
        cout << dp[x] << "\n";
 
    return 0;
}
