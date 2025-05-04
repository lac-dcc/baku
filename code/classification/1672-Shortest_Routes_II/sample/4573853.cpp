#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define YES cout<<"YES"<<endl
#define NO cout<<"NO" <<endl
#define pq priority_queue
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
 
 
int main()
{
	fastIO;
	ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,1e18));
    for(int i=0;i<m;i++)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        dp[u][v]=min(dp[u][v],c);
        dp[v][u]=min(dp[v][u],c);
 
    }
    for(ll i=0;i<=n;i++)dp[i][i]=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dp[i][k]!=1e18 and dp[k][j]!=1e18 and dp[i][k]+dp[k][j]<=dp[i][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                }
            }
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        if(dp[x][y]==1e18)cout<<-1<<endl;
        else cout<<dp[x][y]<<endl;
    }
 
	
	return 0;
}
