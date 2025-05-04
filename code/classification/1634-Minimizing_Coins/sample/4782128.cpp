/* #include <bits/stdc++.h>
 
using namespace std;
 
const char nl = '\n';
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n,x; cin>>n>>x;
    vector<int> c(n); for(int i = 0; i < n; i++) cin>>c[i];
    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;
    for(int i = 1; i < x + 1; i++){
        for(int j = 0 ; j < n; j++){
            if(i - c[j] >= 0){
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    cout<<(dp[x] == 1e9 ? -1 : dp[x])<<nl;
} */
 
#include <bits/stdc++.h>
 
using namespace std;
 
const char nl = '\n';
 
typedef long long ll;
 
const int MOD = 1e9 + 7;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n,x; cin>>n>>x;
    vector<ll> c(n); 
    for(int i = 0; i < n; i++) cin>>c[i];
    vector<ll> f( x + 1, 1e9);
    f[0] = 0;
 
    for(int i = 1; i < x + 1; i++){
        for(auto & coin : c){
            if(i - coin >=0) f[i] = min(f[i], f[i - coin] + 1);
        }
    }
    if(f[x] == 1e9) cout<<-1<<nl;
    else cout<<f[x]<<nl;
}
