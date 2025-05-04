/* Atul_Ratnawat*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
#define fastIO ios_base::sync_with_stdio(0 && cin.tie(0) && cout.tie(0));
 
#define mp make_pair
#define pb push_back
#define gcd(a, b) __gcd(a, b);
#define lcm(a, b) ((a * b) / __gcd(a, b));
#define cases(t)               \
    for (LL i = 0; i < t; i++) \
    {                          \
        solve(i);              \
    }
#define exit return 0;
 
LL mod=1e9+7;
 
int editDistance(int i,int j,int &m,int &n,string &a,string &b,vector<vector<int>> &dp)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
 
    if(dp[i][j]!=-1) return dp[i][j];
 
    if(a[i]==b[j]) 
    {
        return dp[i][j]=0+editDistance(i-1,j-1,m,n,a,b,dp);
    }
            
    int insert=1+editDistance(i,j-1,m,n,a,b,dp);
    int del=1+editDistance(i-1,j,m,n,a,b,dp);
    int rep=1+editDistance(i-1,j-1,m,n,a,b,dp);
 
    return dp[i][j]=min({insert,del,rep});
}
void solve(LL t)
{
    string a,b;
    cin>>a>>b;
 
    int m=a.length();
    int n=b.length();
 
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
 
    cout<<editDistance(m-1,n-1,m,n,a,b,dp);
}
 
int main()
{
    fastIO;
        
    int t = 1;
    // cin >> t;
    cases(t);
    exit;
}
