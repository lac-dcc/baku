#define ll long long
#define ull unsigned ll
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pii pair<int, int>
#define tiil tuple <int, int, ll>
#define tlii tuple <ll, int, int>
#define INF numeric_limits<ll>::max()/2
#define intINF numeric_limits<int>::max()/2
#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    string a, b;
    cin>>a>>b;
    int n = a.length();
    int m = b.length();
 
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for(int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }
 
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i-1][j-1];
            if(a[i-1] != b[j-1])
            {
                dp[i][j]++;
            }
            dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
        }
    }
 
    cout<<dp[n][m]<<endl;
 
 
    return 0;
}
