#include<bits/stdc++.h>
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define check(x) cout<<#x<<" = "<<x<<'\n'
#define pii pair<int,int>
#define ff first
#define ss second
#define th third
#define int long long
using namespace std;
int32_t main(){
    int n=0,target=0;
    cin>>n>>target;
    vi coins(n,0);
    for(auto&coin:coins)cin>>coin;
    vi dp(target+1,0);
    dp[0]=1;
    for(int amount=1;amount<=target;amount++){
        for(auto &coin:coins){
            if(amount-coin>=0)
                dp[amount]=(dp[amount]+dp[amount-coin])%MOD;
        }
    }
    cout<<dp[target];
    return 0;
}
