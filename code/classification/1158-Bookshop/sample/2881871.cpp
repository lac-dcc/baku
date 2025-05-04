#include<bits/stdc++.h>
using namespace std;
int n,x;
int prices[1001],pages[1001];
int dp[1001][(int)1e5+1];
 
int main()
{
    cin >> n >>x;
    for(int i=1 ; i<=n ; i++)
    {
        cin >> prices[i];
    }
    for(int i=1 ; i<=n ; i++)
    {
        cin >> pages[i];
    }
 
    for(int i=1 ; i<=n ; i++)
    {
        for(int cash=0 ; cash<=x ; cash++ )
        {
            if(cash==0) dp[i][cash]=0;
            else
            {
                int not_incl = (i==1)? 0 : dp[i-1][cash];
                int incl =(cash < prices[i])? 0 :  pages[i] + dp[i-1][cash-prices[i]];
                dp[i][cash] = max(not_incl,incl);
            }
        }
    }
 
    cout << dp[n][x] << endl;
 
 
    return 0;
}