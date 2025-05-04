#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define s second
#define f first
#define MOD 1000000007
#define MOD2 998244353
using namespace std;
int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n,x;
cin>>n>>x;
int *a=new int[n];
for(int i=0;i<n;i++)
        cin>>a[i];
int dp[x+1];
dp[0]=1;
for(int i=1;i<=x;i++)
{       dp[i]=0;
        for(int j=0;j<n;j++)
        {
              if(i-a[j] >=0)
                        dp[i]=(dp[i]+(dp[i-a[j]]))%(MOD);
        }
}
cout<<dp[x];
return 0;}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 