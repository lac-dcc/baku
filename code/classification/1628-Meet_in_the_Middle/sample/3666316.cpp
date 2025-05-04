#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll maxn = 40;
ll n, x;
ll t[maxn];
ll lsum[1 << (maxn / 2)];
ll rsum[1 << (maxn / 2)];
 
void calcParticalSum (ll idx, ll cnt, ll dst[]) {
    for (ll i = 0; i < (1 << cnt); i++) {
        ll sum = 0;
        for (ll j = 0; j < cnt; j++) {
            if (i & (1 << j)) sum += t[idx + j];
        }
        dst[i] = sum;
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
    calcParticalSum(0, lsize, lsum);
    calcParticalSum(n / 2, rsize, rsum);
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
