#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <string.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0);
// ================ ON TAP ================
 
int main()
{
    ll n; cin >> n;
    int k; cin >> k;
    ll primes[k];
    for (int i=0; i<k; ++i) {
        cin >> primes[i];
    }
    
    // inclusion-exclusion principles
    ll ans = 0;
    for (int i=1; i<1<<k; ++i) {
        ll num = n;
        int cnt = 0;
        for (int j=0; j<k; ++j) {
            if (i>>j&1) {
                ++cnt;
                num /= primes[j];
            }
        }
        if (cnt&1) {
            ans += num;
        } else {
            ans -= num;
        }
    }
    cout << ans;
    return 0;
}