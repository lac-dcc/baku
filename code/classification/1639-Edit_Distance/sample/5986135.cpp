#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   
    int editDistance(string s,string t) 
    {
        int i,j;
        int a=s.size();
        int b=t.size();
        vector<vector<int>> dp(a+1,vector<int>(b+1,0));
        for(i=0;i<=a;i++)
        dp[i][0]=i;
        for(i=0;i<=b;i++)
        dp[0][i]=i;
        for(i=1;i<=a;i++)
        {
            for(j=1;j<=b;j++)
            {
                if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1];
                else
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[a][b];
    }
};
 
int main()
{
    string s,t;
    cin>>s>>t;
    Solution obj;
    int x=obj.editDistance(s,t);
    cout<<x<<endl;
}