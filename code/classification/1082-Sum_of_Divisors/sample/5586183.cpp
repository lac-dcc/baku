/* ARYAN MISRA*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define fastio()
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define vi vector<ll>
#define vii vector<vector<ll>>
#define pii pair<ll, ll>
#define lb lower_bound
#define ub upper_bound
#define fo(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rev(x) (x).begin(), (x).end(), greater<>()
#define allr(x) (x).rbegin(), (x).rend()
#define no cout << 'NO' << endl;
#define yes cout << 'YES' << endl;
#define nline "\n"
#define ma *max_element
#define mi *min_element
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order , order_of_key
// void dfs(ll root, vector<ll> &edges, vector<bool> &visted, ll &cnt)
//{
// Take action on vertex after entring the vertex
// if(visted[root])return;
// visted[root]=true;
// for(auto child:edges[root]){
// if(visted[child])continue;
// Take action on child before entring the child node
// dfs(child);
// Take action on child after exiting child node
// }
// Take action on vertex before exiting the vertex
// }
bool compare(int a, int b)
{
    if ((a % 2 == 0) && (b % 2 != 0))
        return true;
    if ((a % 2 != 0) && (b % 2 == 0))
        return false;
    return a > b;
}
bool arraySortedOrNot(vector<ll> &a, ll n)
{
    if (n == 1 || n == 0)
    {
        return true;
    }
    return a[n - 1] >= a[n - 2] && arraySortedOrNot(a, n - 1);
}
bool isPalindrome(string S)
{
    // Iterate over the range [0, N/2]
    for (int i = 0; i < S.length() / 2; i++)
    {
        if (S[i] != S[S.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}
struct dsu
{
    vi parent;
    ll components = 0;
    dsu(ll n = -1)
    {
        if (n >= 0)
            init(n);
    }
    void init(int n)
    {
        parent.assign(n + 1, -1);
        components = n;
    }
    ll find(ll x)
    {
        return parent[x] < 0 ? x : parent[x] = find(parent[x]);
    }
    ll get_size(ll x)
    {
        return -parent[find(x)];
    }
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (-parent[x] < -parent[y])
            swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        components--;
        return true;
    }
};
ll power(ll base, ll exponent, ll p)
{
    if (exponent == 0)
        return 1;
    ll res = power(base, exponent / 2, p);
    if (exponent & 1)
    {
        return (((res * res) % MOD) * base) % MOD;
    }
    return (res * res) % MOD;
}
char get(int i)
{
    return 'a' + i - 1;
}
ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }
bool is_valid(ll x, ll y, ll n, ll m)
{
    if (x < 0 || y < 0 || x > n - 1 || y > m - 1)
        return false;
    return true;
}
void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    ll i = 1, j;
    while (i <= n)
    {
        ll quotient = (n / i);
        j = (n / quotient) + 1;
        ll l = ((((j % MOD) * ((j - 1LL) % MOD)) % MOD) * power(2, MOD - 2LL, MOD)) % MOD;
        ll r = ((((i % MOD) * ((i - 1LL) % MOD)) % MOD) * power(2, MOD - 2LL, MOD)) % MOD;
        ll range = (l - r + MOD) % MOD;
        ans = (ans + ((quotient % MOD) * range)) % MOD;
        i = j;
    }
    cout << ans << nline;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL)
        fastio();
    cout << fixed;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    // for (int i = 1; i <= t; i++)
    //{
    // cout<<'Case #'<<i<<':'<<' ';
    // solve();
    // }
    // seive();
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}