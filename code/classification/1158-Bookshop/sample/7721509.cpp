#include<bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main()
{       
    int n,x;
    cin>>n>>x;
 
    int page[n],price[n];
    int a,b;
 
    for(int i=0;i<n;i++)
        cin>>price[i];
 
    for(int i=0;i<n;i++)
        cin>>page[i];
 
    int dp[n+1][x+1];
    memset(dp, 0, sizeof(dp));
 
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            //option1 = book number i-1 is not included, hence no pages added.
            //option2 = book number i-1 is included, hence pages are added.
            //option1 = dp[i-1][j] ...book not included so total price(j) remains same.
            //option2 = dp[i-1][j-price[i-1]] + page[i-1]....total price(j) decreased and pages are counted for book i-1.
            
            dp[i][j] = dp[i-1][j];
            if(j >= price[i-1])
            {
                dp[i][j] = max (dp[i][j],dp[i-1][j-price[i-1]] + page[i-1]); //max of both the boxes included in dp[i][j]. 
            }
        }
    }
 
    cout<< dp[n][x] <<endl;
 
    return 0;
 
}
