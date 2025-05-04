#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll maxn = 40;
ll n, x;
ll t[maxn];
ll lsum[1 << (maxn / 2)];
ll rsum[1 << (maxn / 2)];
 
void calc (ll a[], ll asize, ll d[]) {
    d[0] = 0;
    ll idx = 1;
    for (ll i = 0; i < asize; i++) {
        ll dsize = idx;
        for (ll j = 0; j < dsize; j++) {
            d[idx++] = d[j] + a[i];
        }
    }
}   
 
int main() {
    (void)!scanf("%lld%lld", &n, &x);
    for (ll i = 0; i < n; i++) (void)!scanf("%lld", &t[i]);
    
    if (n == 1) {
        printf("%d\n", x == t[0]);
        return 0;
    }
 
    ll lsize = n / 2;
    ll rsize = n - n / 2;
    calc(t, lsize, lsum);
    calc(t + n / 2, rsize, rsum);
 
    lsize = 1 << lsize;
    rsize = 1 << rsize;
    sort(lsum, lsum + lsize);
    ll ans = 0;
    for (ll i = 0; i < rsize; i++) {
        ll target = x - rsum[i];
        ll idx1 = lower_bound(lsum, lsum + lsize, target) - lsum;
        if (idx1 != lsize && lsum[idx1] == target) {
            ll idx2 = upper_bound(lsum, lsum + lsize, target) - lsum;
            ans += idx2 - idx1;
        }
    }
    printf("%lld\n", ans);
}
