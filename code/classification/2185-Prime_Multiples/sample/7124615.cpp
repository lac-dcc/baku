#include <iostream>
#define ll unsigned long long
using namespace std;
 
const int KMAX = 20;
 
ll n;
int k;
ll primes[KMAX + 1];
 
int main()
{
    cin >> n >> k;
    for(int i = 1; i <= k; i++)
        cin >> primes[i];
 
    ll ans = 0;
    for(int mask = 1; mask < (1 << k); mask++)
    {
        ll prod = 1;
        int bits = 0;
        for(int i = 1; i <= k; i++)
            if((mask >> (i - 1)) & 1)
            {
                bits++;
                if(prod <= n / primes[i])
                    prod *= primes[i];
                else
                    prod = 0;
            }
        if(prod > 0)
        {
            if(bits % 2 == 1)
                ans += n / prod;
            else
                ans -= n / prod;
        }
    }
 
    cout << ans;
 
    return 0;
}