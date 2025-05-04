#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1, s2;
int dp[5005][5005];
ll go(int i, int j) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;
    if (dp[i][j] != -1) return dp[i][j];
    ll ans = 0;
    if (s1[i] == s2[j])  ans = go(i - 1, j - 1);
    else {
        ll q1 = 1 + go(i - 1, j - 1);
        ll q2 = 1 + go(i, j - 1);
        ll q3 = 1 + go(i - 1, j);
        ans = min({q1, q2, q3});
    }
    return dp[i][j] = ans;
}
 
int main()
{
    memset(dp, -1, sizeof dp);
    cin >> s1 >> s2;
    cout << go((ll) s1.size() - 1, (ll) s2.size() - 1);
 
    return 0;
}