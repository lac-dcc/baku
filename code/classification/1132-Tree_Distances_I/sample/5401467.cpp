#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
 
#include <bits/stdc++.h>
 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define loop(i,k,n) for(ll i = k; i < n;i++)
#define MOD 1000000007
#define MOD1 998244353
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define UNIQUE(X) X.erase(unique(all(X)),X.end())
const ll INF = 1e18;
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (ull)rng() % B;
}
vll genRandPerm(ll n){
    vll p(n);
    iota(all(p), 1);
    shuffle(all(p), rng);
    return p;
}
vll genComb(ll n, ll l, ll r){
    // n = size of vector 
    // [l, r] = the range of the values in vector
    vll a(n); 
    for(auto &x: a){
        x = l + myRand(r - l + 1); 
        assert(x <= r && x >= l);
    }
    return a;
}
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x) ((void)0);
#endif
 
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
// --------------------------------------------------------------------------------------------------------------------------------------------------------
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// --------------------------------------------------------------------------------------------------------------------------------------------------------
 
template<class A> void read(vector<A>& v);
template<class T> void read(T& x) {
    cin >> x;
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
 
template<class A> void read(vector<A>& x) {
    for (auto& a: x)
        read(a);
}
template<class A> void read1(vector<A>& x) {
    for(ll i = 1; i <= sz(x) - 1; i++){
        read(x[i]);
    }    
}
// --------------------------------------------------------------------------------------------------------------------------------------------------------
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void google(int t) {cout << "Case #" << t << ": ";}
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll nCr( ll n , ll r){ if(n < r) {cout << " n cannot be less than r " ;return -1;    }if(n - r < r) return nCr(n , n-r); if( r == 0) return 1; return ((n*(nCr(n-1, r-1))) / r );}
 
ll mul(ll a, ll b, ll m) {
        if (a < (1 << 14)) {
            return (a * b) % m;
        }
        ll c = mul(a >> 14, b, m);
        c <<= 14;
        c %= m;
        c = (c + (a % (1 << 14)) * b) % m;
        return c;
}
ll fast_power(ll p, ll e, ll m) {
        if (e == 0) {
            return 1 % m;
        }
        if (e % 2 == 0) {
            return fast_power(mul(p, p, m), e / 2, m);
        }
        else {
            return mul(fast_power(p, e - 1, m), p, m);
        }
}
// --------------------------------------------------------------------------------------------------------------------------------------------------------
 
 
// ll n, m;
 
// vector<ll> adj[N];
// void dfs(ll u){
//     visited[u] = 1;
//     for(ll v: adj[u]){
//         if(!visited[v]){
//             dfs(v);
//         }
//     }
// }
 
// vll dist;
 
// void bfs(ll s) {
//     dist.assign(n + 1, -1);  // n must be defined(i.e global)
//     queue<ll> q;
//     dist[s] = 0; q.push(s);
//     while (q.size()) {
//         ll u = q.front(); q.pop();
//         for (ll v : adj[u]) {
//             if (dist[v] == -1) {
//                 dist[v] = dist[u] + 1;
//                 q.push(v);
//             }
//         }
//     }
// }
 
// void makenCr(){
//     const ll maxn = 1000;   // set maxn accordingly
//     ll C[maxn + 1][maxn + 1];
//     C[0][0] = 1;
//     for (ll n = 1; n <= maxn; ++n) {
//         C[n][0] = C[n][n] = 1;
//         for (ll k = 1; k < n; ++k)
//             C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
//             // C[n][k] %= MOD;
//     }
// }
// --------------------------------------------------------------------------------------------------------------------------------------------------------
 
 
#define N 200005
vector<vll> adjl(N);
vll vis(N);
vll d(N);
 
ll f = 1;
 
void bfs(ll s){
    fill(all(vis), 0);
    fill(all(d), 0);
 
    queue<ll> q;
    q.push(s);
    vis[s] = 1;
    d[s] = 0;
    while(!q.empty()){
        ll curr = q.front(); q.pop();
        for(auto x: adjl[curr]){
            if(!vis[x]){
                q.push(x);
                vis[x] = 1;
                d[x] = 1 + d[curr];
            }
        }
    }
 
    loop(i, 1, N){
        if(d[f] < d[i]) f = i;
    }
}
 
void solve()
{    
    ll n; cin >> n;
    loop(_, 0, n - 1){
        ll a, b; cin >> a >> b;
        adjl[a].pb(b);
        adjl[b].pb(a);
    }
    
    ll s = 1;
    bfs(s);
    ll a = f;
    bfs(a);
    vll da = d;
    debug(da)
 
    ll b = f;
    bfs(b);
    vll db = d;
 
    for(ll i = 1; i <= n; i ++) cout << max(da[i], db[i]) << " ";
}
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    #endif 
    
    int t = 1;
    
//    cin>>t;
    
    for(ll i = 1; i <= t; i ++)
    {   
        // google(i);
        solve();
        // cout << "\n"; 
    }
    return 0;
}
 
