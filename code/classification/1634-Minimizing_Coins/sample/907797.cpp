#include<bits/stdc++.h>
using namespace std;
long long int dp[1000009]={0};
long long int solve(vector<long long int> &v,long long int s)
{
    if(dp[s]!=0)
    return dp[s];
     if(s==0)
    return 0;
    else
    {
        long long int c=INT_MAX;
        for(int x:v)
        {
            if(x<=s)
            c=min(c,solve(v,s-x));
        }
        if(c!=INT_MAX)
        c=c+1;
        dp[s]=c;
    }
    return dp[s];  
}
int main()
{
    long long int n,s;
    cin>>n>>s;
    vector<long long int>v(n);
    for(long long int &x:v)
    cin>>x;
    long long int res=solve(v,s);
    if(res==INT_MAX)
    cout<<-1<<endl;
    else cout<<res<<endl;
    
}
