#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define rep(i, n) for (i = 0; i < n; i++)
#define REP(i, k, n) for (i = k; i <= n; i++)
#define REPR(i, k, n) for (i = k; i >= n; i--)
using namespace std;
 
typedef long long ll;
typedef vector<ll> VI;
typedef set<ll> SET;
typedef vector<vector<ll>> VV;
typedef vector<pair<ll, ll>> VP;
typedef vector<set<ll>> VS;
typedef map<ll, ll> M;
typedef map<ll, vector<ll>> MV;
typedef priority_queue<ll> PQ;
 
const long long MOD = pow(10, 9) + 7;
ll fac[1001];
template <typename T, typename U>
static inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y)
{
    if (x < y)
        x = y;
}
 
void SieveOfEratosthenes(ll n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    for (ll p = 2; p <= n; p++)
        if (prime[p])
        {
            //   do something
        }
}
 
// Fermats Theorem
 
ll power(ll x, ll y, ll p)
{
    ll res = 1;
 
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}
 
ll nCrModPFermat(ll n, ll r, ll p)
{
 
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
 
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
 
void dfs(ll v, ll parent, VV &adj, VI &sz)
{
    sz[v] = 1;
    for (ll u : adj[v])
    {
        if (u != parent)
        {
            dfs(u, v, adj, sz);
            sz[v] += sz[u];
        }
    }
}
 
void solve()
{
    ll i, j, n, m;
    cin >> n;
    // cin>> m;
    // string s;
    // cin >> s;
 
    VV adj(n + 1);
 
    REP(i, 2, n)
    {
        ll x;
        cin >> x;
        adj[x].PB(i);
    }
 
    VI sz(n + 1, 0);
    dfs(1, -1, adj, sz);
 
    REP(i, 1, n)
    {
        cout << (sz[i] - 1) << " ";
    }
 
    return;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll test = 1;
    // fac[0]=1;
    // for(ll i=1;i<=1000;i++){
    //     fac[i] = (fac[i - 1] * i) % MOD;
    // }
 
    switch (test)
    {
    case 1:
        solve();
        break;
    case 2:
    {
        ll t;
        cin >> t;
        while (t--)
        {
            solve();
        }
    };
    break;
    }
}
