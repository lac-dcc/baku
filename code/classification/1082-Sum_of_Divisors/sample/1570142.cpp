#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
#define ll long long
#define MD (ll)1000000007
 
map<ll,ll> mp;
/*
void calcP(ll x){
    mp.clear();
    for(ll i = 2;i*i <= x;i++){
        while(x%i==0){
            x/=i;
            mp[i]++;
        }
    }
    if(x>1){
        mp[x]++;
    }
}
 
ll power(ll x,ll y){
    //(x^y)%mod
    int res = 1;
    x %= mod;
    if(x == 0) return 0;
    while(y>0){
        if(y&1)
            res = (res*x)%mod;
        y >>= 1;
        x = (x*x)%mod;
    }
    return res;
}
*/
 
 
int main() {
    long long n, a, p, q, k, ans;
    
    scanf("%lld", &n);
    ans = 0;
    for (a = 1; a <= n / a; a++) {
        q = n / a;
        ans = (ans + a * q) % MD;
        if (a != q) {
            p = n / (a + 1);
            p %= MD;
            q %= MD;
            k = (q - p) * (q + p + 1) / 2 % MD;
            ans = (ans + k * a) % MD;
        }
    }
    if (ans < 0)
        ans += MD;
    printf("%lld\n", ans);
    return 0;
}
