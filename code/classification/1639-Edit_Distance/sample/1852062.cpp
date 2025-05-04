#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define all(x) (x).begin(),(x).end
#define rall(x) (x).rbegin(),(x).rend
 
const int MOD=(int)1e9+7;
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); //remove when using scanf
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    int dp[n+1][m+1];
    dp[0][0]=0;
    for(int i=1;i<=n;i++) dp[i][0]=i;
    for(int i=1;i<=m;i++) dp[0][i]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x=1;
            if(a[i-1]==b[j-1]) x=0;
            dp[i][j]=min({dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]+x});
        }
    }
    cout<<dp[n][m];
    return 0;
}