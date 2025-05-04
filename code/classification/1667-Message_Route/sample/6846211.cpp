#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007ll
#define tt    \
    int t;    \
    cin >> t; \
    while (t--)
#define int long long
#define pb push_back
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define rep(i, s, e) for (int i = s; i <= e; i++)
#define repr(i, s, e) for (int i = s; i >= e; i--)
#define mp make_pair
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pii>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pll pair<ll, ll>
#define lb lower_bound
#define ub upper_bound
#define sz(a) int(a.size())
#define inf 1000000000000000000
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
vl factorial(ll n, ll m)
{
    vl fact(n + 1, 1);
    for (int i = 2; i <= n; ++i)
    {
        fact[i] = (fact[i - 1] * i) % m;
    }
    return fact;
}
ll expo(ll a, ll b, ll mod)
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
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
int pow_fun(int b, int p)
{
    if (p == 0)
        return 1;
    int res = 1;
    while (p)
    {
        if (p & 1)
            res *= b;
        b = b * b;
        p = p / 2;
    }
    return res;
}
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
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
 
    while (t--)
    {
        int n = 0, m = 0, a = 0, b = 0, c = 0, d = 0, sum = 0, diff = 0, maxN = 0, minN = 0, count = 0, temp = 0;
        bool flag = false;
        cin >> n >> m;
        vector<int> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            int aa, bb;
            cin >> aa >> bb;
            adj[aa].push_back(bb);
            adj[bb].push_back(aa);
        }
        vector<int> parent(n + 1);
 
        queue<int> qq;
        vector<int> vis(n + 1, 0);
        qq.push(1);
        vis[1] = 1;
        int flg = 0;
        while (!qq.empty())
        {
            int node = qq.front();
            qq.pop();
            if (node == n)
            {
                flg = 1;
                break;
            }
            for (auto it : adj[node])
            {
                if (vis[it] == 0)
                {
                    vis[it] = 1;
                    qq.push(it);
                    parent[it] = node;
                }
            }
        }
        // for (int i = 1; i <= n; i++)
        // {
 
        //     cout << parent[i] << " ";
 
 
        // }
        int curNode = n;
        vector<int> ans;
        if (flg == 0)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            while (curNode != 0)
            {
                ans.push_back(curNode);
                curNode = parent[curNode];
            }
            reverse(ans.begin(), ans.end());
 
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}