#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define pb push_back
#define sz(s) (ll)s.size()
#define DEBUG cerr << ">>>Here<<<\n";
const ll maxn = 1e6 + 10;
ll dp[maxn], a[maxn], n;
ll solve(ll x) {
    for(ll i = 1; i <= x; i++) {
        dp[i] = INT_MAX;
        for(ll j = 0; j < n; j++) {
            if (i >= a[j]) dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    if (dp[x] >= INT_MAX) return -1;
    else return dp[x];
}
int main() {
    int x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];  
    }
    cout << solve(x);
    return 0;
}
