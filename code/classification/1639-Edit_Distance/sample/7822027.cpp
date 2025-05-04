#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long int
 
int const nmax = 1e6;
int const mod = 1e9+7;
 
 
signed main() {
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    
    for (int i = 0; i < n+1; i++) dp[i][0] = i;
    for (int j = 0; j < m+1; j++) dp[0][j] = j;
 
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < m+1; j++){
            dp[i][j] = dp[i-1][j-1];
            if(s1[i-1]!=s2[j-1]) dp[i][j] = 1+min(dp[i][j], min(dp[i-1][j], dp[i][j-1]));
        }
    }
    cout<<dp[n][m];
}
