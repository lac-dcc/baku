/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/
 
//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~
 
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,x=0;
    cin>>n>>x;
    int c[n];
    for(int i=0;i<n;++i)
    	cin>>c[i];
    //int dp[x+1]={0};
    vector<ll> dp(x + 1, 0);
    dp[0]=1;
    for(int i=1;i<=x;++i)
    	for(int j=0;j<n;++j)
    	{
    		if(c[j]<=i)
    		{
    			dp[i]+=dp[i-c[j]];
    			dp[i]%=MOD;
    		}
    	}
    cout<<dp[x]<<endl;
}
