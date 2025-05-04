#include<iostream>
#include <vector>
using namespace std;
int m=1e9+7;
int main()
{
    int n,x;
    cin>>n>>x;
    int a[n+1];
    //int dp[n+1][x+1]={0};
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int i=0;i<=x;i++)dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<=x)
        dp[i][a[i]]=1;
    }
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            int f=0,s=0;
            if(i>1)f=dp[i-1][j];
            if(j-a[i]>0)s=dp[i][j-a[i]];
            dp[i][j]+=f+s;
            dp[i][j]%=m;
        }
        //out<<"\n";
    }
    
    cout<<dp[n][x];
return 0;
}
