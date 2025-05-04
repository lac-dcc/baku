#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define compress_id(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define lowbit(x) x&(-x)
#define pb push_back
#define f first
#define s second
#define test() int t; cin >> t; for(;t;t--)
#define sz(x) (int)x.size()
#define cyes cout << "YES\n"
#define cno cout << "NO\n"
 
using namespace std;
 
using ull = unsigned long long;
using ld = long double;
using point = complex<double>;
const int MAX = 1e6+2;
const int inf = (1e18);
const int mod = 1e9+7;
const double pi = acos(-1);
 
struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15,x=(x^(x>>30))*0xbf58476d1ce4e5b9,x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};
 
inline int pow_mod(int a, int n){
    int ans = 1;
    for(;n ;n >>= 1){
        if(n&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
    }
    return ans;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> p(k);
    for(int i = 0; i < k; i++){
        cin >> p[i];
    }
    int ans = 0;
    for(int mask = 1; mask < (1<<k); mask++){
        int m = 1;
        bool ok = true;
        for(int i = 0; i < k; i++){
            if(mask&(1<<i)){
                if(m > (n/p[i])){
                    ok = false;
                    break;
                }
                m *= p[i];
            }
        }
        if(not ok) continue;
        if(__builtin_popcount(mask)&1) ans += (n/m);
        else ans -= (n/m);
    }
    cout << ans;
    return 0;
}