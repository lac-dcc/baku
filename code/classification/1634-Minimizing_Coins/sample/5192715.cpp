#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
int solve(int sum, vector<int> &v)
{
    if (sum == 0)
        return 0;
        if(dp[sum]!=-1 ) return dp[sum];
    
    int ans = INT_MAX-1;
    for (int i = 0; i < v.size(); i++)
    {
        if (sum - v[i] >= 0)
            ans = min(ans, solve(sum - v[i], v) +  1);
    }
        
    return dp[sum]=ans;
}
int main()
{
  
        for (int j = 0; j < 1000005; j++)
        {
            dp[j] = -1;
        }
    
 
    int n;
    cin >> n;
    int sum;
    cin >> sum;
 
    vector<int> a;
 
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
 
    int aa = solve(sum, a);
    if(aa==INT_MAX-1) cout<<-1;
    else cout<<aa;
}
