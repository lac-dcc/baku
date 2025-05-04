#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MOD = 1000000007; // 998244353 - another common prime
struct mint{
  int v;
  int val() { return v; }
  mint() : v(0) {}
  mint(ll v) : v(v % MOD) { v += (v < 0) * MOD; }
};
 
mint& operator+=(mint& a, mint b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.v -= b.v) < 0) a.v += MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.v * b.v); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    vector<mint> dp(x + 5, 0);
 
    for (int i = 0; i < n; i++)
        cin >> coins[i];
 
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= x; j++){
            if (coins[i] <= j){
                dp[j] += dp[j - coins[i]];
            }
        }
    }
    cout << dp[x].v << endl;
}