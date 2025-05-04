#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
ll n;
 
ll add(ll a, ll b) {
    a += b;
    while (a >= MOD) a -= MOD;
    while (a < 0) a += MOD;
    return a;
}
 
ll mul(ll a, ll b) {
    return a*b % MOD;
}
 
ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) res = mul(res, a);
        a = mul(a, a);
         b >>= 1;
    }
    return res;
}
 
ll sum(ll a, ll b) {
    ll res = 1;
    res = add(a, b);
    res = mul(res, add(b-a, 1));
    res = mul(res, power(2, MOD-2));
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll res = 0;
    ll left = 1;
    while (left <= n) {
        // so lan xuat hien
        ll cnt = n/left;
        // The largest number that still has the occurence of cnt
        ll right = n/cnt;
        res = add(res, mul(cnt, sum(left, right)));
        left = right+1;
    }
    cout << res;
    return 0;
}