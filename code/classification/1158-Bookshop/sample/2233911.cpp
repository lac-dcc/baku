#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack> 
#include <queue>
#include <numeric>
#include <iomanip>
#include <iterator>
#include <map>
#include <set>
typedef long long ll;
 
using namespace std;
 
bool sortcol( const vector<long long>& v1, 
               const vector<long long>& v2 ) { 
 return v1[0] < v2[0]; 
}
ll myceil(ll num,ll den)
{
    if ((num >= 0 and den > 0) or ( num <= 0 and den < 0))
        return num%den == 0 ? num/den : num/den + 1;
    return num / den;
}
ll myfloor(ll num,ll den)
{
    if ((num >= 0 and den > 0) or ( num <= 0 and den < 0))
        return num%den == 0 ? num/den : num/den;
    int ans = num / den;
    return num % den == 0 ? ans : ans - 1;
}
 
/* #define MAX 100
#define NIL -1
ll dp[MAX];
void _initialize() 
{ 
    ll i; 
    for (i = 0; i < MAX; i++) 
        dp[i] = NIL; 
} */
int main() {
      int n,x;
    cin>>n>>x;
    vector<int>w;
    vector<int>val;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        w.push_back(ele);
    }
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        val.push_back(ele);
    }
    //int dp[n+1][x+1]={0}; //rows=weights which have values amd columns=0 to W capacity
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));  
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(w[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][x]<<endl; 
}
