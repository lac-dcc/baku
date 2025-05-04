#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9
#define lc node<<1+1
#define rc node<<1+2
#define endl '\n'
 
ll n;
const int mod = 1e9+7;
 
ll binexp(ll a, int b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
 
    ll inverse = binexp(2, mod-2); // modular inverse of 2
 
    ll sum = 0;
 
    for(ll i = 1; i * i <= n; i ++){
 
        ll tmp = i; // this is for the i*i
 
        ll low = i + 1;
        ll high = n/i;
 
        if(high >= low){
            ll count = (high - low + 1) % mod;
 
            // this is the number of i's encountered
            tmp = (tmp + (count * i % mod)) % mod;
 
            // this is the number of x/i for each x encountered
            // start from low and end at high, so use sum formula
            ll tmp1 = (low + high) % mod;
            tmp = (tmp + (tmp1 * count % mod * inverse % mod)) % mod;
        }       
 
        sum = (sum + tmp) % mod;
    }
 
    cout << sum << endl;
 
    return 0;
}   