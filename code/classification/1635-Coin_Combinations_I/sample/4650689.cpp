#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define loop(i, l, n) for (ll i = l; i < ll(n); i++)
#define bloop(i, n, l) for (ll i = n; i > ll(l); i--)
#define INF ll(1e18)
#define MOD ll(1e9+7)
//#define MOD ll(1e9+9)
#define F first
#define S second
#define pll pair<ll, ll>
typedef long long ll;
 
//  ---------------------  //
 
 
void solve() {
    ll n, t; cin >> n >> t;
    vector<ll> a(n);
    loop(i, 0, n) {cin >> a[i];}
    vector<ll> d(t + 1);
    d[0] = 1;
    loop(i, 0, t + 1){
        for(auto x: a) {
            if (x <= i) d[i] = (d[i] + d[i - x]) % MOD;
        }
    }
    cout << d[t] % MOD << endl;
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Love; //cin >> Love;
    Love = 1;
    while (Love--) solve();
    return 666/1337;
}