#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5005, INF = 1e9+9;
string s, t;
int n, m;
void inp(){
    cin >> s;
    cin >> t;
    n = s.size();
    m = t.size();
}
int dp[maxn][maxn];
void solve(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++){
        dp[i][0] = i;
    }
    for(int j = 1; j <= m; j++){
        dp[0][j] = j;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            dp[i][j] = min({dp[i][j], dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1});
        }
    }
    cout << dp[n][m];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	solve();
	return 0;
}
