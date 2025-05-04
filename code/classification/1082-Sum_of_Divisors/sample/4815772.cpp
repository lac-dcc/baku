#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const ll INF = 2e18;
 
ll inv = 500000004;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll cur = 1;
    ll resp = 0;
    while(cur != n) {
        ll l = n / cur, r = n / (cur + 1);
        //cout << cur << ' ' << l << ' ' << r << endl;
        ll at = (l + r + 1) % MOD;
        at *= ((l - r)) % MOD;
        at %= MOD;
        at *= inv;
        at %= MOD;
        at *= cur;
        at %= MOD;
        //cout << at << endl;
        resp += at;
        resp %= MOD;
        cur = n / (n / (cur + 1));
    }
    resp += n;
    resp %= MOD;
    cout << resp << '\n';
    return 0;
}
