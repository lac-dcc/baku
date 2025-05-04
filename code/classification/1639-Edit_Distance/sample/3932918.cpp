#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
typedef long long ll;
 
#ifndef ONLINE_JUDGE
#define deb(x) cout<<#x<<" "<<x<<"\n"
#define deb2(x,y) cout<<"[ "<<#x<<"="<<x<<","<<#y<<"="<<y<<" ]\n"
#define deba(x,n) cout<<#x<<": [ ";for(int i=0;i<n;i++){cout<<x[i]<<" ";}cout<<"]\n"; 
#define deba2(x,n,m) cout<<#x<<":\n";for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<x[i][j]<<" ";cout<<"\n";}; 
#define debe(x) cout<<#x<<":[ ";for(auto i:x){cout<<i<<" ";}cout<<"]\n"; 
#else
#define deb(x) 
#define deb2(x,y) 
#define deba(x,n) 
#define deba2(x,n,m) 
#define debe(x) 
#endif
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s,t;
    cin>>s>>t;
    int n1=s.length(),n2=t.length();
 
    int inf=1e9;
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,inf));
 
    // dp[i][j] -> answer for s[i..n1-1] and t[j..n2-1]
 
    for(int j=n2;j>=0;j--)
        dp[n1][j]=n2-j;
    for(int i=n1;i>=0;i--)
        dp[i][n2]=n1-i;
 
    for(int i=n1-1;i>=0;i--)
    {
        for(int j=n2-1;j>=0;j--)
        {
            if(s[i]==t[j])
            {
                dp[i][j]=min(dp[i][j],dp[i+1][j+1]);
            }
            else
            {
                // remove s[i]
                dp[i][j]=min(dp[i][j],1+dp[i+1][j]);
                // remove t[i]
                dp[i][j]=min(dp[i][j],1+dp[i][j+1]);
                // replace s[i] with t[i]
                dp[i][j]=min(dp[i][j],1+dp[i+1][j+1]);
            }
        }
    }
 
    cout<<dp[0][0];
 
    return 0;
}
