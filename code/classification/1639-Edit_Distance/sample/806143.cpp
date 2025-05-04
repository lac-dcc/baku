#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll;
// ll mod=1000000007,BS,k;
int main(){
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // #ifndef ONLINE_JUDGE
        //     freopen("input.txt","r",stdin);
        //     freopen("output.txt","w",stdout);
        // #endif
        string a,b;
        cin>>a>>b;
        ll n,m;
        n=a.length();m=b.length();
        ll dp[n+1][m+1];memset(dp,0,sizeof(dp));
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=m;j++){
            	if(i==0&&j==0)continue;
            	if(i==0)
            	dp[i][j]=j;
            	else if(j==0)
            	dp[i][j]=i;
            	else
                dp[i][j]=min(dp[i-1][j-1]+(a[i-1]!=b[j-1]),min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
        }
        cout<<dp[n][m];
 
}
