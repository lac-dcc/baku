// Coin Combinations I
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
#define ll long long
void solve(){
    ll n,target;
    cin>>n>>target;
    ll c[n];
    for(int i=0;i<n;++i){
        cin>>c[i];
    }
 
    vector<ll> dp(target+1,0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < n; j++) {
            if (i-c[j] >= 0) {
	            (dp[i] += dp[i-c[j]])%=MOD;
            }
        }
    }
    cout<<dp[target]<<'\n';
}
 
int main(){
// #ifndef ONLINE_JUDGE
 
//     freopen("input.txt", "r", stdin);
 
//     freopen("output.txt", "w", stdout);
 
// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
