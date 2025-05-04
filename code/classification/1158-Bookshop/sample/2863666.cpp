#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> pret(n);
    vector<int> pagini(n);
 
    for(int i = 0; i < n; i++)
        cin >> pret[i];
    for(int i = 0; i < n; i++)
        cin >> pagini[i];
    
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
 
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int ramas = j - pret[i - 1];
            if(ramas >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i -1][ramas] + pagini[i - 1]);
            }
        }
    }
 
    cout << dp[n][x];
    return 0;
}