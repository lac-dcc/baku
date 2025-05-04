#include <iostream>
#include <bits/stdc++.h>
 
// policy based datastructure
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define indexed_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#define ll long long
#define en '\n'
#define ff first
#define ss second
#define pb push_back
#define MP make_pair
#define mod 1000000007
#define mod1 1000000009
#define mod2 998244353
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
 
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef priority_queue<ll> pqi;
typedef priority_queue<ll, vi, greater<ll>> minpqi;
typedef pair<ll, ll> pii;
#define debarr(a, n)            \
    cout << #a << " : ";        \
    for (int i = 0; i < n; i++) \
        cerr << a[i] << " ";    \
    cerr << endl;
#define debmat(mat, row, col)         \
    cout << #mat << " :\n";           \
    for (int i = 0; i < row; i++)     \
    {                                 \
        for (int j = 0; j < col; j++) \
            cerr << mat[i][j] << " "; \
        cerr << endl;                 \
    }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const unordered_set<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
void dbs(string str, T t) { cerr << str << " : " << t << "\n"; }
template <class T, class... S>
void dbs(string str, T t, S... s)
{
    int idx = str.find(',');
    cerr << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}
template <class T>
void prc(T a, T b)
{
    cerr << "[";
    for (T i = a; i != b; ++i)
    {
        if (i != a)
            cerr << ", ";
        cerr << *i;
    }
    cerr << "]\n";
}
#define all(x) x.begin(), x.end()
#define present(c, key) (find(all(c), key) != c.end())
#define tr(c, it) for (auto it : c)
#define fr(i, s, e) for (ll i = s; i < e; i++)
#define revfr(i, s, e) for (ll i = s - 1; i >= e; i--)
#define getv(v, n)             \
    for (ll i = 0; i < n; i++) \
        cin >> v[i];
 
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)
{
 
    for (auto element : v)
    {
        os << element << ' ';
    }
    return os;
}
inline void add(ll &a, ll b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
 
inline void sub(ll &a, ll b)
{
    a -= b;
    if (a < 0)
        a += mod;
}
 
inline ll mul(ll a, ll b, ll p = mod)
{
    return (ll)((long long)a * b % p);
}
 
inline ll power(ll a, long long b, ll p = mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, a, p);
        }
        a = mul(a, a, p);
        b >>= 1;
    }
    return res;
}
inline ll binpow(ll a, long long b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
inline ll inv(ll a, ll p = mod)
{
    a %= p;
    if (a < 0)
        a += p;
    ll b = p, u = 0, v = 1;
    while (a)
    {
        ll t = b / a;
        b -= t * a;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    if (u < 0)
        u += p;
    return u;
}
// inline ll lsb(ll x)
// {
//     return x&(~(x-1));
// }
// ll modexp2(ll a, ll b, ll c, ll p) // calculate (a^(b^c))%prime
// {
//     // By Fermat's Little Theorem (a^(p-1))%p = 1 if p is prime
//     ll x = power(b,c,p-1);  // so we first find remainder when b^c is divided by p-1
//     return (power(a,x,p));  // then just do (a^remainder)%p
 
// }
ll gcd(ll a, ll b)
{
    if (a == 0 or b == 0)
        return a ^ b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * (b / gcd(a, b));
}
void fread()
{
    // #ifdef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
    // #endif
}
/*** set hashing
 
const ll k=10000019;
const ll h=131;
 
Hash[st]=(summation of (a+k)^h)%mod where a belongs to set st;
***/
vvi g;
int indp[200100],outdp[200100];
void indfs(int node,int par)
{
    indp[node]=0;
    for(auto x:g[node])
    {
        if(x==par)continue;
        indfs(x,node);
        indp[node]=max(indp[node],1+indp[x]);
    }
}
void outdfs(int node,int par,int val)
{
    if(par==0)outdp[node]=0;
    else
    {
        outdp[node]=max(outdp[par]+1,val);
    }
    int mx=-1,mx2=-1;
    for(auto x:g[node])
    {
        if(x==par)continue;
        if(mx==-1)mx=x;
        else if(indp[mx]<indp[x])
        {
            mx2=mx;
            mx=x;
        }
        else if(mx2==-1)mx2=x;
        else if(indp[mx2]<indp[x])mx2=x;
    }
    for(auto x:g[node])
    {
        if(x==par)continue;
        if(x==mx)
        {
            if(mx2==-1)outdfs(x,node,0);
            else outdfs(x,node,indp[mx2]+2);
        }
        else outdfs(x,node,indp[mx]+2);
    }
}
void solve()
{
    int n;
    cin>>n;
    g.clear();
    g.resize(n+1);
    fr(i,1,n)
    {
        ll a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    indfs(1,0);
    outdfs(1,0,0);
    fr(i,1,n+1)cout<<max(indp[i],outdp[i])<<" ";cout<<"\n";
}
using namespace std;
 
int main()
{
    fast
    // pre();
    // fread();
    ll _t = 1;
    // cin >> _t;
    fr(i, 1, _t + 1)
    {
        // cerr<<"i="<<i<<en;
        solve();
    }
    return 0;
}
