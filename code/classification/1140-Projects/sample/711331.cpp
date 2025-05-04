//  zukonit14 - Kunal Raut
 
#include<bits/stdc++.h>
using namespace std;
 
/*/-----------------------------DEFINES----------------------------------/*/
 
#define ll                  long long
#define ld                  long double
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define mod1                1000000007
#define pi                  3.1415926535
#define MAXN                1*1000000+10
#define MAX2N               1*1000+10
const   ll INF              = 1e18;
#define all(v)              v.begin(), v.end()
#define allr(v)             v.rbegin(), v.rend()
#define ms(s, n)            memset(s, n, sizeof(s))
#define prec(n)             fixed<<setprecision(n)
#define forci(p,n)          for(ll i=p;i<(ll)n;i++)
#define forcj(p,n)          for(ll j=p;j<(ll)n;j++)
#define bolt                ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define bits(a)             __builtin_popcountll(a)
#define djokovic            freopen("input00.txt", "r", stdin);freopen("output00.txt", "w", stdout);
#define inrange(i,a,b)      ((i>=min(a,b)) && (i<=max(a,b)))
clock_t time_p              = clock();
void rtime()                {time_p = clock() - time_p; cout << "\nTime Taken : " << fixed << (float)(time_p) / CLOCKS_PER_SEC << "s\n";}
 
/*/-----------------------------INLINE FUNCTIONS----------------------------------/*/
 
inline ll gcd(ll a, ll b)          {if (b == 0) return a;    return gcd(b, a % b);}
inline ll lcm(ll a, ll b)          {return (a / gcd(a, b) * b);}
//inline ll expo(ll x, ll y)         {ll res = 1; x = x % mod; while (y > 0) {if (y & 1)res = (1ll * res * x) % mod; y = y >> 1; x = (1ll * x * x) % mod;} return res % mod;}
//inline ll inv_mod(ll q, ll m = mod1)   {return (expo(q, m - 2) % m);}
inline ll ncr(ll n, ll r)          {ll res = 1; if (r > n - r)r = n - r; for (ll i = 0; i < r; i++) {  res *= n - i;  res /= i + 1; } return res;}
inline bool prime(ll n)            {ll i; for (i = 2; i <= sqrt(n); i++) {if (n % i == 0)return false;} return true;}
 
/*/-----------------------------TRACE FUNCTIONS----------------------------------/*/
 
template<class T> ostream& operator<<(ostream &os, string V) {
    os << "[ ";
    for (auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for (auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S) {
    os << "{ ";
    for (auto s : S) os << s << " ";
    return os << "}";
}
template<class T, class T1> ostream& operator<<(ostream &os, map<T, T1> S) {
    os << "{ ";
    for (auto s : S) os << "(" << s.first << "," << s.second << ") ";
    return os << "}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
#define tracearr(a,n)  {cout << #a<<" : ";cout<<"[ ";for (ll i = 0; i < n; i++) cout << a[i] << " ";cout << "]\n";}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif
 
/*/-----------------------------MODULAR ARITHMETIC----------------------------------/*/
 
const ll mod = 1e9 + 7;
//const ll mod = 998244353;
inline ll add(ll x, ll y) {
    x += y;
    if (x >= mod) return x - mod;
    return x % mod;
}
inline ll sub(ll x, ll y) {
    x -= y;
    if (x < 0) return x + mod;
    return x;
}
inline ll mul(ll x, ll y) {
    return (x * 1ll * y) % mod;
}
inline ll expo(ll x, ll y) {
    ll ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        x = mul(x, x);
        y >>= 1;
    }
    return ans % mod;
}
inline ll inv(ll x) {
    return expo(x, mod - 2);
}
/*/-----------------------------CODE BEGINS----------------------------------/*/
 
ll rr[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll cc[] = {1, 1, 0, -1, -1, -1, 0, 1};
ll n, m, k, x, q, a[MAXN], b[MAXN], a1[MAXN];
void solve()
{
    cin >> n;
    vector<int>a(n), b(n), p(n);
    map<ll, ll>compress;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> p[i]; b[i]++;
        compress[a[i]];
        compress[b[i]];
    }
    ll coords = 0;
    for (auto &it : compress)
        it.second = coords++;
    vector<vector<pair<ll, ll>>>project(coords);
    for (ll i = 0; i < n; i++)
    {
        project[compress[b[i]]].push_back(make_pair(compress[a[i]], p[i]));
    }
    vector<ll>dp(coords, 0);
    for (ll i = 0; i < coords; i++)
    {
        if (i)     dp[i] = dp[i - 1];
        for (auto p : project[i])
            dp[i] = max(dp[i], dp[p.fi] + p.se);
    }
    cout << dp[coords - 1];
}
signed main()
{
    bolt;
// #ifndef ONLINE_JUDGE
//     djokovic;
// #endif
    ll t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    //rtime();
}
