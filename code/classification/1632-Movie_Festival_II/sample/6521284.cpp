#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
 
const double PI = 3.141592653589793;
const int MOD = 1e9+7;
const int mod = 998244353;
const ll INF = LLONG_MAX;
 
#define fo(i, a, b, d) for(ll i = a; i < b; i += d)
#define of(i, a, b, d) for(ll i = a; i > b; i -= d)
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(), x.end()
#define cin std::cin
#define cout std::cout
 
ll modpower(ll x, ll y, ll m){
    x %= m;
    ll ans = 1;
    while (y > 0) {
        if (y % 2 == 1) ans = (ans*x) % m;
        x = (x*x) % m;
        y /= 2;
    }
    return ans;
}
 
bool customsort (const pll &a, const pll &b){
    return (a.second < b.second);
}
 
void solve(){
    ll n, k; cin>>n>>k;
    pll a[n];
    fo (i, 0, n, 1)
        cin>>a[i].first>>a[i].second;
    sort(a, a+n, customsort);
    multiset<ll> mst;
    fo (i, 0, k, 1)
        mst.insert(0);
    ll ans = 0;
    fo (i, 0, n, 1){
        auto it = mst.upper_bound(a[i].first);
        if (it != mst.begin()){
            ans++;
            mst.erase(--it);
            mst.insert(a[i].second);
        }
    }
    cout<<ans<<"\n";
}
 
// for binary search
// ll l = ; // l is bad
// ll r = ; // r is good
// while (r > l+1){
//     ll mid = (r + l)/2;
//     if (good(mid)) r = mid;
//     else l = mid;
// }
 
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    // spf.assign(MAXN, 0);
    // sieve();
 
    ll t = 1;
    // cin>>t;
    fo (i, 1, t+1, 1){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
 
    return 0;
}
