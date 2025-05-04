#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int min_edit_distance(string str_a, const string str_b) {
    ll n = str_a.size();
    ll m = str_b.size();
 
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1)
    ); // dp[i][j] is the minimum number of operations required to transfer the prefix str_a[0:i) into the prefix str_b[0:j)
 
    dp[0][0] = 0;
    for (ll i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + 1;
    }
    for (ll i = 1; i <= m; i++) {
        dp[0][i] = dp[0][i - 1] + 1;
    }
 
    for (int i = 1; i <= n; i++) {
        char curr_a = str_a[i - 1];
 
        for (int j = 1; j <= m; j++) {
            char curr_b = str_b[j - 1];
 
            dp[i][j] =
                    min(
                            // str_a[0, i - 1) <-> str_b[0, j - 1), + 1 if curr_a != curr_b
                            dp[i - 1][j - 1] + (curr_a == curr_b ? 0 : 1),
                            min(
                                    // str_a[0, i) <-> str_b[0, j - 1) + 1
                                    dp[i][j - 1] + 1,
 
                                    // str_a[0, i - 1) <-> str_b[0, j) + 1
                                    dp[i - 1][j] + 1
                            )
                    );
        }
    }
 
    // you can find the operations used in the minimal edit by jumping back from dp[n][m] into the smallest box out of dp[n - 1][m - 1], dp[n][m - 1], dp[n - 1][m], until reaching dp[0][0]
 
    return dp[n][m];
}
 
int main() {
    string str_a;
    string str_b;
    cin >> str_a >> str_b;
 
    cout << min_edit_distance(str_a, str_b);
}
