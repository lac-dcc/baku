#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
 
ll svb[1100000];
struct chash { // large odd number for C
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
__gnu_pbds::gp_hash_table<ll,int,chash> ina({},{},{},{},{1<<16});
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    ll x;
    cin >> n >> x;
 
    vector<ll> va((n+1)>>1), vb(n>>1);
 
    for (int i = 0; i < ((n+1)>>1); ++i) {
        cin >> va[i];
    }
 
    for (int i = 0; i < (n>>1); ++i) {
        cin >> vb[i];
    }
 
    int ib = 0;
    for (int mask = 0; mask < (1<<va.size()); ++mask) {
        ll sa = 0;
        ll sb = 0;
        for (int i = 0; i < va.size(); ++i) {
            if ((mask >> i)&1) {
                sa += va[i];
                if (i < vb.size()) {
                    sb += vb[i];
                }
            }
        }
        if (va.size() == vb.size() || (!((mask >> ((int)vb.size()))&1))) {
            if(sb <= x) {
                svb[ib++] = sb;
            }
        }
        if (sa <= x)++ina[sa];
    }
 
    ll ans = 0;
    for (int i = 0; i < ib; ++i) {
        ans += ina[x - svb[i]];
    }
    cout << ans << endl;
    return 0;
}
