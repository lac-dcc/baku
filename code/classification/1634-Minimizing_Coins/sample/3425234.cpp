#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; using ll=int64_t;
 
ll n, x, INF = 1e10;
ll dp[(ll)1e6+1];
vector<ll> v;
 
int main()
{
    cin >> n >> x;
    for(ll i=0, t; i<n;++i){
        cin >> t; v.push_back(t);
    }
    
    for(ll i=0; i<=x; ++i){
        dp[i] = INF;
    }
    
    dp[0] = 0;
    for(ll s=1; s<=x; ++s){
        dp[s] = INF;
        for(ll i=0; i<n; ++i){
            if(s >= v[i])
                dp[s] = min(dp[s], 1 + dp[s-v[i]]);
        }
    }
    
    if(dp[x] >= INF || dp[x] == 0) cout << "-1" << endl; 
    else cout << dp[x] << endl;
 
    
 
    return 0;
}