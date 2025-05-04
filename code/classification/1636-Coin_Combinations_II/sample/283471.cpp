#include<bits/stdc++.h>
#define ll long long
#define f(i,l,r) for(int i=l;i<=r;i++)
#define debug(x) cout<<#x<<'='<<(x)<<endl
using namespace std;
int mod=1000000007;
template<class T> bool maxs(T& a,T& b)
{
    if(a<b)
    {
        T t;
        t=a;
        a=b;
        b=t;
        return true;
    }
    return false;
}
template<class T> bool maxi(T& a,T b)
{
    if(a<b)
    {
        a=b;
        return true;
    }
    return false;
}
template<class T> bool mini(T& a,T b)
{
    if(a>b)
    {
        a=b;
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
#endif
    int n,x;
    cin>>n>>x;
    vector<int>c(n),dp(x+1);
    for(int i=0;i<n;i++)    cin>>c[i];
    dp[0]=1;
    for(auto i:c)
    {
        for(int j=1;j<=x;j++)
            if(i<=j)
                dp[j]=(dp[j]+dp[j-i])%mod;
            
    }
    cout<<dp[x];
    return 0;
}
