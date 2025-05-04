#include <bits/stdc++.h>
 
#define int long long
#define float long double
 
using namespace std;
 
const int P = 1e9 + 7;
 
vector<int> dp;
 
int f (int x, vector<int>& v)
{
    if (dp[x] == -1)
    {
        if (x == 0)
        {
            dp[x] = 1;
        }
        else
        {
            dp[x] = 0;
            for (auto coinValue : v)
            {
                if (x - coinValue >= 0)
                {
                    dp[x] = (dp[x] + f (x - coinValue, v))%P;
                }
            }
        }
    }
    return dp[x];
}
 
void solve()
{
    int n, x;
    cin >> n >> x;
    
    vector<int> v (n);
    for (auto& coinValue : v)
    {
        cin >> coinValue;
    }
    
    for (int i = 0; i <= x; ++i)
    {
        dp.push_back (-1);
    }
    
    cout << f (x, v) << endl;
}
 
int32_t main()
{
    int t = 1;
    //cin >> t;
    
    while (t--) solve();
    
    return 0;
}