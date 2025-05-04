#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
 
ll count(ll coin[], ll n, ll sum) {
    //ll t[sum + 1] = {0};
    vector<ll> t(sum + 1, 0);  
    ll i, j;
    t[0] = 1;
 
    for (i = 0; i < n; i++) {
        for (j = coin[i]; j <= sum; j++) {
            t[j] += t[j - coin[i]];
            t[j] %= mod;
        }
    }
    return t[sum] % mod;
}
 
int main() {
    ll n, x;
    cin >> n >> x;
    ll a[n], i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << count(a, n, x) << endl;
    return 0;
}
