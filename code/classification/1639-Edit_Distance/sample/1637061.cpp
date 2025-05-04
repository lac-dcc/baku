#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>
#define INT_MAX 2147483647
using namespace std;
 
int brute(int i,int j,string a,string b,unordered_map<string,int>&memo)
{
   string key = to_string(i) + "," + to_string(j);
   if(memo.find(key) != memo.end()) return memo[key];
   if(i < 0) return (j + 1);
   else if(j < 0) return (i + 1);
   if(a[i] == b[j]) return brute(i-1,j-1,a,b,memo);
   int res = INT_MAX;
   res = min(1 + brute(i-1,j,a,b,memo),1 + brute(i,j-1,a,b,memo));
   res = min(res,1 + brute(i-1,j-1,a,b,memo));
   memo[key] = res;
   return memo[key];
}
 
int main(void)
{
   unordered_map<string,int>memo;
   string a,b;
   cin >> a >> b;
   int n = a.length();
   int m = b.length();
   int dp[n+1][m+1];
   for(int i = 0;i<=n;i++) dp[i][0] = i;
   for(int j = 0;j<=m;j++) dp[0][j] = j;
   for(int i = 1;i<=n;i++)
   {
      for(int j = 1;j<=m;j++)
      {
         if(a[i-1]==b[j-1])
            dp[i][j] = dp[i-1][j-1];
         else
         {
            int res = min(1 + dp[i-1][j],1 + dp[i][j-1]);
            res = min(res,1 + dp[i-1][j-1]);
            dp[i][j] = res;
         }
      }
   }
   cout << dp[n][m] << endl;
}
