// Consider a money system consisting of n
//  coins. Each coin has a positive integer value. Your task is to produce a sum of money x
//  using the available coins in such a way that the number of coins is minimal.
 
// For example, if the coins are {1,5,7}
//  and the desired sum is 11
// , an optimal solution is 5+5+1
//  which requires 3
//  coins.
 
// Input
 
// The first input line has two integers n
//  and x
// : the number of coins and the desired sum of money.
 
// The second line has n
//  distinct integers c1,c2,…,cn
// : the value of each coin.
 
// Output
 
// Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print −1
// .
 
// Constraints
// 1≤n≤100
 
// 1≤x≤106
 
// 1≤ci≤106
 
// Example
 
// Input:
// 3 11
// 1 5 7
 
// Output:
// 3
 
#include <bits/stdc++.h>
using namespace std;
 
vector<int>v,dp;
int n,x,inf=1e8;
 
int fun(int r)
{
    if(r<0)     return inf;
    if(r==0)    return 0;
    int &ans=dp[r];
    if(~ans)    return ans;
    ans=inf;
    for(int i=0;i<n;i++)    ans=min(ans,1+fun(r-v[i]));
    return ans;
}
 
int fun()
{
    cin>>n>>x;
    v.clear(),v.resize(n);
    dp.clear(),dp.resize(x+1,-1);
    for(int i=0;i<n;i++)    cin>>v[i];
    int ans=fun(x);
    if(ans>=inf)            return -1;
    return ans;
}
 
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);   
    
    int t=1;
    //cin>>t;
    while(t--)
    {
        cout<<fun();
        cout<<'\n';
    }
    
    return 0;
}