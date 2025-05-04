#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
//int N=1000+1;
vector<int>pages,prices;
vector<vector<int>>dp;
int f(int i,int money)
{
    if(i==0)
    {
        if(money>=prices[0])return pages[0];
        else return 0;
    }
    if(dp[i][money]!=-1)return dp[i][money];
    int pick=0,notpick=0;
    if(money>=prices[i])
    pick=f(i-1,money-prices[i])+pages[i];
    notpick=f(i-1,money);
 
    return dp[i][money]=max(pick,notpick);
}
int main()
{
    int n,k;
    cin>>n>>k;
    pages=vector<int>(n);
    prices=vector<int>(n);
    //dp=vector<vector<int>>(n+1,vector<int>(k+1,0));
    for(int i=0;i<n;i++)cin>>prices[i];
    for(int i=0;i<n;i++)cin>>pages[i];
 
    // int ans=f(n-1,k);    
    // cout<<ans<<endl;
    vector<int>prev(k+1,0),curr(k+1,0);
    for(int money=0;money<=k;money++)
    {
        if(money>=prices[0])
       prev[money]=pages[0];
    }
 
    for(int i=1;i<n;i++)
    {
        for(int money=0;money<=k;money++)
        {
            int pick=0,notpick=0;
 
            if(money>=prices[i])
            pick=prev[money-prices[i]]+pages[i];
            notpick=prev[money];
 
            curr[money]=max(pick,notpick);
        }
        prev=curr;
    }
 
    cout<<prev[k]<<endl;
    
}