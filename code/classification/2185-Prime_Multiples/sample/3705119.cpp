#include <iostream>
#include <vector>
 
using namespace std;
 
using ll = long long;
 
const ll MOD = 1e9 + 7;
 
ll binPow(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    int k;
    cin >> n >> k;
    vector<ll> a(k);
    for (ll &i : a) cin >> i;
    ll res = 0;
    for (int i = 1; i < (1 << k); ++i)
    {
        ll prod = 1;
        int counter = 0;
        for (int j = 0; j < k; ++j)
        {
            if (i & (1 << j))
            {
                ++counter;
                if (__int128(prod) * a[j] > n)
                {
                    prod = n + 1;
                    break;
                }
                prod *= a[j];
            }
        }
        if (counter & 1) res += n / prod;
        else res -= n / prod;
    }
    cout << res;
    return 0;
}