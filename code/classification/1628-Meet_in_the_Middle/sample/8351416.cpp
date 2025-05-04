#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define sp << " " << 
//#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
const int inf = 2e9+1,N = 41;
 
struct chash {
	// any random-ish large odd number will do
	const uint64_t C = 6e18 + 71;
	// random 32-bit number
	const uint32_t RANDOM =
	    chrono::steady_clock::now().time_since_epoch().count();
	size_t operator()(uint64_t x) const {
		// see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
		return __builtin_bswap64((x ^ RANDOM) * C);
	}
};
 
void solve() {
    int n,x;
    cin >> n >> x;
    vi a(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];
    if (n == 1) {
        cout << (a[1] == x) << endl;
        return;
    }
 
 
    gp_hash_table<int, int, chash> mp;
    int n1 = n/2;
    int lim = (1<<n1);
    for (int i=0;i<lim;i++) {
        int sm = 0;
        for (int j=0;j<n1;j++) {
            if (i&(1<<j)) {
                sm+=a[j+1];
                if (sm > x) break;
            }
        }
        if (sm <= x) mp[sm]++;
    }
    long long ans = 0;
    int n2 = n-n1;
    lim = (1<<n2);
    for (int i=0;i<lim;i++) {
        int sm = 0;
        for (int j=0;j<n2;j++) {
            if (i&(1<<j)) sm+=a[n1+j+1];
        }
        ans+=mp[x-sm];
    }
    cout << ans << endl;
}   
    
                 
                             
signed main() { 
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef Local
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t = 1;
    //cin >> t; 
	while (t --> 0) solve();
}
