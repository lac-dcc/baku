 
/*जय श्री महाकाल!*/
/* जय श्री गणेश! */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
 
#define int long long
#define double long double
#define inp0(a, n)              \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define inp1(a, n)               \
    for (int i = 1; i <= n; i++) \
    cin >> a[i]
#define out(x) cout << x << endl;
#define out0(a, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << a[i] << " ";    \
    }                           \
    cout << endl;
#define out1(a, n)               \
    for (int i = 1; i <= n; i++) \
    {                            \
        cout << a[i] << " ";     \
    }                            \
    cout << endl;
#define sz(s) (long long)(s.size())
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (long long i = a; i < b; ++i)
#define yes cout << "YES"
#define no cout << "NO"
#define vi vector<long long>
#define vv vector<vector<long long>>
#define mii map<int, int>
const int MOD = 1e9 + 7;
#define INF (int)1e18
#define PI (double)acos(-1)
 
#define dbg(x) cout << #x << " is " << x << endl;
#define dbgarr(x)                      \
    cout << #x << " is:" << endl;      \
    for (int i = 0; i < x.size(); i++) \
    {                                  \
        cout << x[i] << " ";           \
    }                                  \
    cout << endl;
#define dbgarrp(x)                                               \
    cout << #x << " is:" << endl;                                \
    cout << "( ";                                                \
    for (int i = 0; i < x.size(); i++)                           \
    {                                                            \
        cout << "[" << x[i].first << " " << x[i].second << "],"; \
    }                                                            \
    cout << " )";                                                \
    cout << endl;
#define repr(i, b, a) for (long long i = b - 1; i >= a; i--)
#define brk cout << "break the line" << endl;
#define repa(i, a, b) for (long long i = a; i <= b; ++i)
#define repra(i, b, a) for (long long i = b; i <= a; i--)
 
typedef tuple<int, int, int> state; // use tie(a,b,c)=(could be any tuple)
 
const bool testcases = true;
 
const int M = 1e9 + 7;
long long mod(long long x)
{
    return ((x % M + M) % M);
}
long long add(long long a, long long b, long long m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
int binexp(int a, int b, int m)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}
typedef long long ll;
 
int inverse(int x)
{
    int res = 1;
    int expo = MOD - 2;
    while (expo > 0)
    {
        if (expo & 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        expo >>= 1;
    }
    return res;
}
long long mul(long long a, long long b, long long m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
long long sub(long long a, long long b, long long m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
 
    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<vi> dist(n + 1, vi(2, __LONG_LONG_MAX__));
    dist[1][0] = 0;
 
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
 
    priority_queue<state, vector<state>, greater<state>> pq;
    pq.emplace(0, 1, 0);
 
    while (!pq.empty())
    {
        int d, node, dliya;
        tie(d, node, dliya) = pq.top();
        pq.pop();
        if (d > dist[node][dliya])
        {
            continue;
        }
        for (auto [v, w] : adj[node])
        {
 
            if (dliya == 1)
            {
                if (dist[v][dliya] > (d + w))
                {
                    dist[v][dliya] = (d + w);
                    pq.emplace(dist[v][dliya], v, dliya);
                }
            }
            else
            {
                if (dist[v][dliya] > (d + w))
                {
                    dist[v][dliya] = (d + w);
                    pq.emplace(dist[v][dliya], v, 0);
                    if (dist[v][1] > (d + w / 2ll))
                    {
                        dist[v][1] = (d + w / 2ll);
                        pq.emplace(dist[v][1], v, 1ll);
                    }
                }
            }
        }
    }
 
    cout << min(dist[n][1], dist[n][0]) << "\n";
}
 
int32_t main()
{
    solve();
 
    return 0;
}
