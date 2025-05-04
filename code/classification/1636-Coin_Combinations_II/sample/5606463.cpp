#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define all(x) x.begin(),x.end()
#define pub push_back
#define pob pop_back
#define fi first
#define se second
#define l(a) a.length()
#define sz(a) a.size()
#define coud(a,b) cout << fixed << setprecision((b)) << (a)
#define setbits(x) __builtin_popcount(x)
#define lbin(x) ceil(log2(x+1))
#define sp ' '
#define nl endl
const ll mod = 1000000007;
ll gcd(ll a, ll b) { if(b == 0) return a; return gcd(b, a%b); }
ll lcm(ll a, ll b) { return (a/gcd(a,b)*b); }
ll power(ll x, ll y, ll p) { ll res = 1; x = x % p; while (y > 0) { if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p; } return res; }
ll modInverse(ll n, ll p) { return power(n, p-2, p); }
 
void solve(){
    ll n, x; cin >> n >> x;
    vector<ll> coins(n);
    for(ll i = 0; i < n; i++) cin >> coins[i];
    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    for(ll i = 0; i < n; i++){
        for(ll j = 1; j <= x; j++){
            if(j-coins[i] >= 0){
                dp[j] += dp[j-coins[i]];
                dp[j] %= mod;
            }
        }
    }
    cout << dp[x] << nl;
}
 
int main(){
    FIO;
    solve();
    return 0;
}