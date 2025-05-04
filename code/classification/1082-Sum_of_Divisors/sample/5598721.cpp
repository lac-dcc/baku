#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
 
const ll mod = 1e9 + 7;
 
ll exgcd(ll a, ll b, ll& x, ll& y) {
    ll d = a;
    if (b != 0) {
        d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}
 
ll mod_inverse(ll a) {
    ll x, y;
    exgcd(a, mod, x, y);
    return (mod + x % mod) % mod;
}
 
int main() {
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll res = (n - 1LL) % mod;
    ll maxn = sqrt(n);
    ll inv2 = mod_inverse(2LL);
    //cout << "maxn: " << maxn << endl;
    for (ll x = 2LL; x <= maxn; x++) {
        ll cnt = n / x;
        if (cnt > maxn)  {
            ll tmp = ((((maxn + 1LL + cnt) % mod) * ((cnt - maxn) % mod)) % mod) * inv2;
            tmp %= mod;
            res = (res + tmp) % mod;
            //cout << cnt << ": " << tmp << endl;
        }
        ll tmp = (x * ((cnt - 1LL) % mod)) % mod;
        //cout << x << ": " << tmp << endl;
        res = (res + tmp) % mod;
    }
    ll sum = (((1LL + (n % mod)) * (n % mod)) % mod) * inv2;
    sum %= mod;
    res = (res + sum) % mod;
    cout << res << endl;
}
 
 
 
 
 