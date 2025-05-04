#include <bits/stdc++.h>
#define MOD 1000000007
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ull unsigned long long int
#define ll long long int
#define V vector
#define pb push_back
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
using namespace std;
 
int coins[101]={0};
 
int solve(int n, int x){
    int dp[n+1][x+1];                            //dp[n][x] = ways when we have n coins and required sum is x
    loop(k,0,x+1) dp[0][k] = 0;
    loop(k,1,n+1) dp[k][0] = 1;
 
    loop(i,1,n+1){
        loop(j,1,x+1){
            dp[i][j] = dp[i-1][j]%MOD;                                   // when ith the coin is not included
            if(j-coins[i]>=0) dp[i][j] += dp[i][j-coins[i]]%MOD;         // when ith the coin is included
        }
    }
    return dp[n][x]%MOD;
}
 
int main(){     
    FAST    
    int n, x;
    cin>>n>>x;
    loop(i,1,n+1) cin>>coins[i];
    cout<<solve(n,x);
}
