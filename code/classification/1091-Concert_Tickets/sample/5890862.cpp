/*/ Author: Abhinav_m6174 /*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;
 
#define loop(i,n) for(ll i = 0 ; i<n ; ++i)
#define loopr(i,n) for(ll i = n-1 ; i>=0 ;--i)
#define mloop(i,n) for(ll i = 1; i<n ; ++i)
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define endl "\n"
#define vll vector<ll>
#define pll pair<ll,ll>
#define in insert
#define mpll map<ll,ll>
 
#define all(v) v.begin(),v.end()
#define mp make_pair
#define watch(x) cout << #x << " = " << x << endl
 
#define PI 3.141592653589793238462
const double epsilon = 1e-6;
const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9 + 7;
const int MxN = 2e5 + 5;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
void init_code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
#endif
}
void solve() {
    ll n, m; cin >> n >> m;
    multiset<ll> se;
    ll h[n], t[m];
    loop(i, n) {cin >> h[i]; se.in(h[i]);}
    loop(i, m)cin >> t[i];
    loop(i, m) {
        auto tz = se.lower_bound(t[i]);
        if (tz == se.end()) {
            if (tz == se.begin()) {
                cout << -1 << endl;
                continue;
            }
            tz--;
            if (*tz > t[i])
                cout << -1 << endl;
            else {
                cout << *tz << endl;
                se.erase(tz);
            }
        }
        else {
            ll tl = *se.lower_bound(t[i]);
            if (tl == t[i]) {
                cout << tl << endl;
                se.erase(se.find(tl));
            }
            else if (tl > t[i]) {
                auto itr = se.lower_bound(t[i]);
                if (itr == se.begin())
                    cout << -1 << endl;
                else
                {
                    itr--;
                    cout << *itr << endl;
                    se.erase(se.find(*itr));
                }
            }
            else
                cout << -1 << endl;
        }
 
    }
}
signed main() {
    init_code();
    IOS
    clock_t z = clock();
    solve();
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
 
}
