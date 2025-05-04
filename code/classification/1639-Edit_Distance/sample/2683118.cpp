#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long int
 
const int N = 5e5 + 5;
int A[N];
 
int solve(string a, string b) {
    int n = a.length();
    int m = b.length();
    int dp[n+2][m+2];
 
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else {
                if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
        }
    }
    return dp[n][m];
}
 
int32_t main()
{
    string a, b;
    cin>>a>>b;
    int ans = solve(a, b);
    cout<<ans<<endl;
    return 0;
}