#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define scan(v,n) for(ll i=0;i<n;i++){ cin>>v[i];}
#define fyn if(flag){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
const ll MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    string a,b;
    cin>>a>>b;
    n = a.length();
    m = b.length();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1,0));
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=m;j++)
        {
            if(!i || !j) {
                dp[i][j] = i+j;
                continue;
            }
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
    }
    cout<<dp[n][m];
}
