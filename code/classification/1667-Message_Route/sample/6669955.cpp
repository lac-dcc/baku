#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <iterator>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <functional>
#include <bitset>
#include <chrono>
#include <climits>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#pragma region
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
 
#define set_bits __builtin_popcountll
 
//__builtin_clz(x) -> count leading zeros  //32 bits for int, 64 bits for ll
//__builtin_ctzll(x) -> count trailing zeros
 
#define rep(i, a, b) for (long long i = a; i < b; i++)
#define rept(i, a) for (long long i = 0; i < a; i++)
#define repd(i, a, b, step) for (long long i = a; i < b; i = i + step)
#define rev(i, a, b) for (long long i = a; i >= b; i--)
#define revd(i, a, b, step) for (long long i = a; i >= b; i = i - step)
#define ff first
#define ss second
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define PI 3.141592653589793238462
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sortv(v) sort(all(v));
#define rsortv(v) sort(rall(v));
#define tc        \
    ll tests;     \
    cin >> tests; \
    for (ll i = 1; i <= tests; i++)
#define io                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define max3(a, b, c) max(max((a), (b)), (c))
#define max4(a, b, c, d) max(max((a), (b)), max((c), (d)))
#define min3(a, b, c) min(min((a), (b)), (c))
#define min4(a, b, c, d) min(min((a), (b)), min((c), (d)))
#define coutv(v)           \
    for (auto it : (v))    \
        cout << it << " "; \
    nline;
#define cout2d(v)             \
    for (auto it : (v))       \
    {                         \
        for (auto j : it)     \
            cout << j << " "; \
        nline;                \
    }
#define cinv(v, n) \
    rep(i, 0, (n)) { cin >> v[i]; }
#define cin2d(v, n, m)                   \
    rep(i, 0, n)                         \
    {                                    \
        rep(j, 0, m) { cin >> v[i][j]; } \
    }
#define pyes(CONDITION) cout << (CONDITION ? "YES" : "NO") << "\n";
#define nline cout << "\n"
#define MOD 1000000007
#define MOD1 998244353
#define INF LLONG_MAX / 2
#define endl "\n"
 
template <typename T>
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
// #define ordered_set tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>
 
// s.find_by_order(x) ->  find number at position x among sorted numbers
// s.order_of_key(x) -> position of x among sorted numbers
 
ll dx[] = {-1, 0, 0, 1};
ll dy[] = {0, -1, 1, 0};
 
ll ddx[] = {-1, 0, 0, 1, -1, -1, 1, 1};
ll ddy[] = {0, -1, 1, 0, -1, 1, -1, 1};
 
// knight movements
int kx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int ky[8] = {1, 2, 2, 1, -1, -2, -2, -1};
 
// Operator Overloads
template <typename T1, typename T2> // cin >> pair
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
    {
        cin >> it;
    }
    return istream;
}
template <typename T1, typename T2> // cout << pair
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
    {
        cout << it << " ";
    }
    return ostream;
}
template <typename T> // cout << vector<vector>>  //
ostream &operator<<(ostream &ostream, const vector<vector<T>> &c)
{
    for (int i = 0; i < c.size(); i++)
    {
        for (auto j : c[i])
            cout << j << " ";
        cout << endl;
    }
    return ostream;
}
 
int binary_search(vi v, int n)
{
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] == n)
            return mid;
        else if (v[mid] < n)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
 
ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll lcm(int a, int b) { return (a * b) / gcd(a, b); }
ll power(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void extendgcd(ll a, ll b, ll *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size1 3
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return power(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
ll combination(ll n, ll r, ll m, vector<int> &fact, vector<int> &ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<ll> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
ll phin(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number -= number / i;
        }
    }
    if (n > 1)
        number -= number / n;
    return number;
} // O(sqrt(N))
vector<int> phi_1_to_n(int n)
{
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;
    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}
 
// *****************************************DEBUG START*************************************************
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << " is " << x << endl;
#define debugv(v)                   \
    cout << #v << " is :-" << endl; \
    for (auto it : (v))             \
        cout << it << " ";          \
    cout << endl;
#define debug2d(v)                  \
    cout << #v << " is :-" << endl; \
    for (auto it : (v))             \
    {                               \
        for (auto j : it)           \
            cout << j << " ";       \
        cout << endl;               \
    }
#define pline cout << __LINE__ << " line is reached" << endl;
#define debugvp(v)                  \
    cout << #v << " is :-" << endl; \
    cout << v;                      \
    cout << endl;
#define prline cout << "\n";
#define print(s) cout << s << endl;
#else
#define debug(x)
#define debugv(v)
#define debug2d(v)
#define debugvp(v)
#define prline
#define pline
#define print(s)
#endif
// *****************************************DEBUG END***************************************************
#pragma endregion
 
const int N = 1e5 + 1;
vector<int> adj[N];
int parent[N];
bool vis[N];
 
void solve()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(parent, -1, sizeof parent);
 
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        if (vis[a])
            return;
        vis[a] = true;
 
        for (auto j : adj[a])
        {
            if (vis[j] || parent[j] != -1)
                continue;
            q.push(j);
            parent[j] = a;
        }
    }
    vector<int> ans;
    int curr = n - 1;
    while (curr != 0)
    {
        ans.push_back(curr + 1);
        curr = parent[curr];
        if (curr == -1)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
 
    ans.push_back(1);
 
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}
 
signed main()
{
    io
    solve();
 
    return 0;
}
