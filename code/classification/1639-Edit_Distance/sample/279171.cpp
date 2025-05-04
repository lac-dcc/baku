#include <bits/stdc++.h>
using namespace std;
 
int dp[5001][5001];
 
int main()
{
    string s1, s2; cin >> s1 >> s2;
    int N = s1.length(), M = s2.length();
    for(int i = 0; i < 5001; i++)
    {
        for(int j = 0; j < 5001; j++)
        {
            dp[i][j] = 1e9;
        }
    }
    for(int i = 0; i <= N; i++) dp[i][0] = i;
    for(int j = 0; j <= M; j++) dp[0][j] = j;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
        }
    }
    cout << dp[N][M];
}