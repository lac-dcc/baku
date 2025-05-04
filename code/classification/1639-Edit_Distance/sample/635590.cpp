#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define pp4 pair<pp, pp>
#define pp3 pair<ll, pair<int, int> > 
#define fi first
#define se second
#define N  101
#define mod 1000000007
#define inf 2000000001
#define esp 1e-9
#define BLOCK 333
#define BITNUM 555
#define BASE 311097
typedef long long ll;
// const ll oo = (ll)1e18 + 1;
using namespace std;
string s, t;
 
int main() {
    ios::sync_with_stdio(false);
    // freopen("in.in", "r", stdin);    
    cin >> s;
    cin >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int> > dp(n + 1, vector<int>(m + 1));
    
    for (int i = 1; i <= m; i++) {
        dp[0][i] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
 
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
 
    cout << dp[n][m];
    return 0;
}
 