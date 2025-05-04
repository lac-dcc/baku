#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 1000005;
ll sq;
void solve() {
    ll n;
    cin >> n;
    sq = sqrt(n);
    ll up = n;
    ll ans = 0;
    for (ll i = 1 ; i <= sq ; i++) {
        ll nxt = n / (i + 1);
        ans += (up + nxt + 1) % mod * ((up - nxt) % mod) % mod * 500000004 % mod * i % mod;
        ans %= mod;
        up = nxt;
    }
    for (ll i = 1 ; i <= up ; i++) {
        ans += n / i * i;
        ans %= mod;
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        solve();
    }
}