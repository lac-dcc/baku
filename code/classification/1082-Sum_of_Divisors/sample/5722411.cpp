#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
ll inv(ll i){
    if(i == 1) return 1;
    return MOD - (MOD / i) * inv(MOD % i) % MOD;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll ans = 0;
    for(ll i = 1; i * i <= n; i++){
        ans += (i * (n / i)) % MOD;
        ans %= MOD;
        ll l = max(n / (i + 1), (ll)sqrt(n)), r = n / i;
        ll range = ((((r%MOD)*((r+1)%MOD))%MOD)*inv(2))%MOD - ((((l%MOD)*((l+1)%MOD))%MOD)*inv(2))%MOD;
        //range = (range + MOD) % MOD;
        ans += (range * i) % MOD;
        ans %= MOD;
    }
    cout<<ans<<endl;
}
