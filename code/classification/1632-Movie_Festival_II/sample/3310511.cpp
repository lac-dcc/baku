#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull ;
typedef long double ld ;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define IMX INT_MAX
#define IMN INT_MIN
const unsigned int M = 1000000007;
#define fo(i,n) for (int i = 0; i < n; i++)
#define FO(i,a,n) for(int i= a ; i<n ; i++ )
#define all(x) x.begin(), x.end()
ll binpow(ll a , ll b) ;
ll modmul(ll a , ll b , ll m);
//******************************** Template End ******************************//
// #define int ll
 
void solve() {
    int n , k ;
    cin >> n >> k ;
    vector<pair<int, int>> movie ;
    for (int i = 0 ; i < n ; i++) {
        int a , b ;
        cin >> a >> b ;
        movie.pb({a , b});
    }
 
    sort(all(movie), [](auto x , auto y) {
        if (x.S == y.S)
            return  x.F > x.S ;
        return x.S < y.S ;
    } );
 
    // for (auto &[x , y] : movie) {
    //     cout << x << ' ' << y << '\n';
    // }
 
    multiset<int> st ;
    auto help = [&](int s , int e) -> bool {
 
        if (!st.empty() && *st.begin() > s) {
            if ((int)st.size() >= k)
                return false ;
            else {
                st.insert(e) ;
                return true ;
            }
        }
        if (!st.empty()) {
            auto it = st.upper_bound(s) ;
            st.erase(--it);
        }
        st.insert(e);
        return true;
    };
 
    int count = 0 ;
    for (auto &[s , e] : movie) {
        if (help(s , e)) {
            count++;
            // cout << s << " " << e << " " << count << '\n';
        }
 
        // cout << "\n";
        // for (auto u : st)
        //     cout << u << ' ';
 
        // cout << "\n";
    }
    cout << count << '\n';
}
 
 
 
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
 
#ifndef ONLINE_JUDGE
    freopen ("error.txt", "w", stderr);
#endif
    solve();
#ifndef ONLINE_JUDGE
    cerr << "Runtime : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
 
    return 0;
}
 
//******************************** Utility Functions *************************//
 
ll binpow(ll a , ll b) {
    ll res = 1 ;
    while (b) {
        if (b & 1) res = res * a % M ;
        a = a * a % M ;
        b >>= 1 ;
    }
    return res ;
}
 
ll modmul(ll a , ll b , ll m) {
    return ((a % m) * (b % m )) % m ;
}