#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define mod 1000000007
using namespace std;
typedef long long ll;
 
const ll mex = 1e6 + 6;
ll dp[mex], coins[100];
 
int main()
{
	FIO;
	ll n, v; cin >> n >> v;
    for(ll i = 0; i < n; i++) cin >> coins[i];
 
    dp[0] = 1;
    for(ll i = 1; i <= v; i++) {
        for(ll j = 0; j < n; j++)
            if(i - coins[j] >= 0)
                dp[i] += dp[i - coins[j]] , dp[i] %= mod;
    }
    cout << dp[v] << '\n';
	return 0;
}
