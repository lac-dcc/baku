#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
 
#define debvec(v)         \
    cout << #v << " : ";  \
    for (auto x : v)      \
        cout << x << " "; \
    cout << endl
 
#define check(x) cout << "--------" << x << endl
 
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define all(x) (x).begin(), (x).end()
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ar array
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
 
#define inp  \
    ll temp; \
    cin >> temp;
 
#define printvec(v)       \
    for (auto x : v)      \
        cout << x << " "; \
    cout << endl
 
#define print2dvec(v)         \
    for (auto x : v)          \
    {                         \
        for (auto y : x)      \
        {                     \
            cout << y << " "; \
        }                     \
        cout << endl;         \
    }
 
#define printarr(n, arr)        \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << arr[i] << " ";  \
    }                           \
    cout << endl;
 
#define print2darr(n, m, arr)         \
    for (int i = 0; i < n; i++)       \
    {                                 \
        for (int j = 0; j < m; j++)   \
        {                             \
            cout << arr[i][j] << " "; \
        }                             \
        cout << endl;                 \
    }
 
#define deb(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
 
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
 
const int mxn3 = 1e3 + 1;
const int mxn5 = 1e5 + 1;
const int mxn25 = 2e5 + 1;
const ll MXN = 1e9 + 1;
const ll MOD = 1e9 + 7;
 
class A
{
public:
    int dfs(int v, vvi &adj, vi &depth, int &ans, int p = -1)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int &np : adj[v])
        {
            if (np == p)
                continue;
 
            depth[np] = dfs(np, adj, depth, ans, v);
            q.push(depth[np]);
            // cout << "******************\n";
            // cout << v << " " << np << " " << depth[np] << " " << q.size() << "\n";
            // cout << "******************\n";
            if (q.size() > 2)
                q.pop();
        }
 
        if (q.size() == 0)
        {
            ans = max(ans, 1);
            return 1;
        }
 
        int a = q.top();
        q.pop();
 
        if (q.size() == 0)
        {
            ans = max(ans, a + 1);
            return a + 1;
        }
 
        int b = q.top();
        q.pop();
        ans = max(ans, a + b + 1);
        return b + 1;
    }
 
    void init()
    {
        int n;
        cin >> n;
        vvi adj(n + 1);
 
        for (int i = 0, a, b; i < n - 1; i++)
        {
            cin >> a >> b, --a, --b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
 
        vi depth(n + 2, 0);
        int ans = 0;
        dfs(0, adj, depth, ans);
        // for (int i = 0; i < n; i++)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << depth[i] << " ";
        // }
        // cout << "\n";
        cout << ans - 1;
    }
} obj;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    obj.init();
}
 
/*
 
 
*/
