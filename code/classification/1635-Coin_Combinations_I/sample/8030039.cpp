#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sl cout << "\n";
#define out(ank, a, i) for (ll i = 0; i < a; i++) { cout << ank[i] << " "; }
#define inn(k, a, i) for (ll i = k; i < a; i++)
#define in(ank, a) for (ll i = 0; i < a; i++) { cin >> ank[i]; }
#define vec(ank) vector<ll> ank;
bool comp(pair<ll, ll> p1, pair<ll, ll> p2) {
    return p1.first > p2.first;
}
const ll mod = 1e9 + 7;
ll solve(vector<ll>& coins, ll a, ll sum, vector<ll>& dp) {
    if (sum == 0) {
        return 1;
    }
    if (sum < 0 || a <= 0) {
        return 0;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    ll ans = 0;
    for (ll i = 0; i < a; i++) {
        if (coins[i] <= sum) {
            ans+= (solve(coins, a, sum - coins[i], dp))%mod;
        }
    }
    return dp[sum] = ans;
}
 
int main() {
    ll a; cin >> a; ll sum; cin >> sum;
    vector<ll> dp(sum + 1, -1);
    vector<ll> coins(a);
    in(coins, a);
    cout << (solve(coins, a, sum, dp))%mod;
}
