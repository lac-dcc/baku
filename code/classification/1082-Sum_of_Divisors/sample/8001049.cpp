#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll twoInverse = ((1e9+8)/2);
ll getSum(ll l, ll r){
    ll sz = (r-l+1)%mod;
    ll other = (l+r)%mod;
    ll res = (sz*other)%mod;
    res*=twoInverse; res%=mod;
    return res;
}
 
 
int main(){
 
    ll n; cin >> n;
    ll sum = 0;
    ll curDiv = 1;
    while(curDiv <= n){
        ll adding = n/curDiv;
        ll lastsame = n/adding;
        sum+=((adding*getSum(curDiv,lastsame)) % mod);
        sum%=mod;
        curDiv = lastsame+1;
    }
 
    cout << sum << "\n";
 
 
 
    return 0;
}
