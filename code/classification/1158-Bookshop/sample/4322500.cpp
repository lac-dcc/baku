#include <bits/stdc++.h>
 
typedef long long ll;
using namespace std;
const int NMAX=1005;
const int XMAX=100005;
 
int N, X, price[NMAX], val[NMAX], sol, dp[NMAX][XMAX];
 
int main()
{
    cin>>N>>X;
    for(int i=1;i<=N;i++)
        cin>>price[i];
    for(int i=1;i<=N;i++)
        cin>>val[i];
 
    for(int i=1;i<=N;i++){
        for(int j=1;j<=X;j++){
            dp[i][j]=dp[i-1][j];
            if(price[i]<=j)
                dp[i][j]=max(dp[i][j],dp[i-1][j-price[i]]+val[i]);
            sol=max(sol,dp[i][j]);
        }
    }
 
    cout<<sol;
 
    return 0;
}