#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, t;
ll dp[5005][5005];
 
int main() {
 
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();
 
 
    for(ll i = 0; i <= n; i++) {
        for(ll j = 0; j <= m; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
            }
        }
    }
 
 
 
    cout << dp[n][m] << endl;
}
