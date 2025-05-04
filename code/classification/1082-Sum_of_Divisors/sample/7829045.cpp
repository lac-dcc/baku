#include <bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
 
#define int long long
#define double long double
#define all(x) x.begin(), x.end()
#define printarr(x, start) for(int i = start; i < (int)x.size(); i++){cout << x[i] << " ";}cout << '\n';
#define printnl(...) for(auto x : {__VA_ARGS__}){cout << x << " ";}cout << '\n';
#define print(...) for(auto x : {__VA_ARGS__}){cout << x << " ";}
 
template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template<typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {
  }
};
template<typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
  }
};
 
const int intmin = -1000000000000000000LL;
const int intmax = 1000000000000000000LL;
const double PI = 3.14159265;
int mod = 1e9+7;
 
long long power(int x, int y){
    if (y==0) return 1;
    
    long long v = power(x, y/2);
    v *= v; v%= mod;
    
    if (y&1) return v * x % mod;
    else return v;
}
 
long long inverse(int n){
    return power(n, mod - 2);
}
 
//remember to update facN and mod to the value you want 
 
void solve()
{
    int n;
    cin >> n;
 
    int ans = 0;
    int twoinv = inverse(2);
 
    int nxt = 1;
    for (int i = 1; i <= n; i = nxt)
    {
        int q = n/i;
 
        nxt = n/q + 1;
 
        int a = i-1;
        int b = nxt-1;
 
        ans += (q%mod * ((((((b%mod) * ((b+1)%mod))%mod * twoinv)%mod) - ((((a%mod) * ((a+1)%mod))%mod * twoinv)%mod)) + mod)%mod)%mod;
        ans %= mod;
    }
    
    cout << ans << '\n';
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i << ": ";
        // cout << "Case #" << i << ": ";
        solve();
    }
}
