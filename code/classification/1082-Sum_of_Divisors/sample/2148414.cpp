#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
 
int main() {
    ll n;
    cin >> n;
    ll total = 0;
    ll d = 1;
    while (d <= n) {
        ll div = n / d;
        ll maxd = n / div;
 
        ll diff = (maxd - d) % MOD;
 
        int partsum = (((d % MOD) * (diff + 1)) % MOD) + ((diff * (diff + 1) / 2) % MOD);
        partsum %= MOD;
        total += (div % MOD) * partsum;
        total %= MOD;
        d = maxd + 1;
    }
    cout << total << endl;
}
