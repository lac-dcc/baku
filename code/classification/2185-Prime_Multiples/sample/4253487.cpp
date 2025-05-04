#include <bits/stdc++.h>
using namespace std;
#define intt long long int
#define F first 
#define S second
#define pb push_back
const int N=1<<20;
const intt Maxx=1e18;
intt dp[N];
// CSES
int main()// inclusion exclusion ..
{
    intt n,k;cin>>n>>k;
    intt arr[k];
    for(int i=0;i<k;i++) cin>>arr[i];
    
    intt q=1<<k;
    
    for(int i=1;i<q;i++)
    {
        double pp=1;
        bool overflow =false;
        for(int j=0;j<k;j++)
        {
            if(i & (1<<j))
            // overflow.. despite long long int... Hence used double..
            {
                pp*=arr[j];
            }
        }
        
        if(pp>Maxx) overflow=true;
 
 
        if(!overflow)
        dp[i]=n/(long long int)pp;
    }
 
    intt ans=0;
 
    for(int i=1;i<q;i++)
    {
        int cnt=0;
        for(int j=0;j<k;j++)
        {
            if(i&(1<<j)) cnt++;
        }
        if(cnt%2) ans+=dp[i];
        else ans-=dp[i];
    }
    cout<<ans<<endl;
    
    return 0;
}