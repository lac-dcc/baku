#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const ll INF = 5e18;
 
ll mult(ll a, ll b){
    ll res = a * b;
    if (b > INF / a)
        res = INF;
    if ((res / b) != a || (res / a) != b)
        res = INF;
    if (res < 0)
        res = INF;
    return res;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    ll n, k;
 
    cin >> n >> k;
 
    vector<ll> primes (k);
 
    for (ll i = 0; i < k; i++) cin >> primes[i];
 
    ll ans = 0;
    for (ll mask = 1; mask < (1 << k); mask++){
        ll prod = 1;
        ll coef = -1;
        for (ll c = 0; c < k; c++){
            if (mask & (1 << c)){
                // cout << primes[c] << " ";
                prod = mult(prod, primes[c]);
                // cout << "P " << prod << " ";
                coef *= -1;
            }
        }
        ll total = n / prod;
        // cout << "T " << total << " P " << prod << " ";
        ans += total * coef;
 
        // cout << ans << "\n";
    }
 
    cout << ans << "\n";
 
    return 0;
}