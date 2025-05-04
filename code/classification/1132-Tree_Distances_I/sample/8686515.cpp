/*
 
                ॐ
 
    वक्रतुण्ड महाकाय सूर्यकोटि समप्रभ।
 
    निर्विघ्नं कुरु मे देव सर्वकार्येषु सर्वदा
 
*/
#include <bits/stdc++.h>
 
using namespace std;
 
// Macros
#define FASTIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007
#define INF 1e18
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng) //random number between a,b
#define lb lower_bound
#define ub upper_bound
 
// Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvi;
typedef vector<pll> vpll;
 
// Constants
const double PI = 3.141592653589793238462;
 
// Debugging
#ifdef DEBUG
#define debug(x) cerr << #x << " : " << x << endl;
#else
#define debug(x)
#endif
 
// Utility Functions
template <typename T>
void print(const T& container) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}
 
template <typename T>
void print(const T& container, char delim) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        cout << *it;
        if (next(it) != container.end()) {
            cout << delim;
        }
    }
    cout << "\n";
}
 
// Mathematical Functions
ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
 
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}
 
ll power(ll base, ll exponent) {
    ll result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}
 
int gcdExtended(int a, int b, int* x, int* y) {
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
 
ll iMod(ll a, ll m) {
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1) return 0;
    else {
        ll res = (x % m + m) % m;
        return res;
    }
}
 
ll nCr(int n, int r) {
    if (r > n) {
        return 0;
    }
    if (r > n - r) {
        r = n - r;
    }
    ll ans = 1;
    for (int i = 1; i <= r; i++) {
        ans *= (n - i + 1);
        ans %= MOD;
        ans *= iMod(i, MOD);
        ans %= MOD;
    }
    return ans;
}
 
 
void dfs(int start, int parent, vi &distance, int d, vvi &tree)
{
    if(start != parent)distance[start] = d;
    for(auto &x : tree[start])
    {
        if(x != parent)
        {
            dfs(x, start, distance, d+1, tree);
        }
    }
}
// Main Solution
void solve() {
    int n, u, v;
    cin >> n;
    vvi tree(n, vi());
    FOR(i, 0, n-1)
    {
        cin >> u >> v;
        u--, v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    int start = 0;
    vi distStart(n);
    dfs(start, -1, distStart, 0, tree);
    start = 0;
    int x = 0;
    FOR(i, 0, n)
    {
        if(distStart[start] < distStart[i])start = i;
    }
    x = start;
    vi distX(n);
    dfs(x, -1, distX, 0, tree);
    int y = 0;
    FOR(i, 0, n)
    {
        if(distX[y] < distX[i])y = i;
    }
    vi distY(n);
    dfs(y, -1, distY, 0, tree);
    FOR(i, 0, n)cout<<max(distX[i], distY[i])<<" ";
    cout<<endl;
}
 
signed main() {
    FASTIO();
    #ifndef ONLINE_JUDGE
        auto start_time = chrono::high_resolution_clock::now();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    #ifndef ONLINE_JUDGE
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        cout << "Elapsed time: " << duration.count() << " microseconds" << endl;
    #endif
    return 0;
}
