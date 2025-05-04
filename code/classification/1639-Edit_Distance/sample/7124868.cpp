#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
 
string n, m;
 
void solution() {
    vector<vector<int>> dp(n.size()+1, vector<int>(m.size()+1,1e9));
    dp[0][0] = 0;
 
    for (int i = 0; i <= n.size(); i++)
    {
        for (int j = 0; j <= m.size(); j++)
        {
            if (i != 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
 
            if (j != 0)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
 
            if (i != 0 && j != 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (n[i - 1] != m[j - 1]));
        }
    }
 
    cout << dp[n.size()][m.size()];
}
 
int main() {
    fastio;
//    freopen(".INP", "r", stdin);
//    freopen(".OUT", "w", stdout);
 
    cin >> n >> m;
    solution();
 
    return 0;
}
