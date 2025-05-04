#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define edl '\n'
#define fl(i, k, n) for (ll i = k; i < n; i++)
#define rfl(i, k, n) for (ll i = n - 1; i >= k; i--)
#define cpy(arr, arr1, n) \
    fl(i, 0, n) { arr1[i] = arr[i]; }
#define prnt(arr, n) \
    fl(i, 0, n) { cout << arr[i] << ' '; }
#define rprnt(arr, n) \
    rfl(i, 0, n) { cout << arr[i] << ' '; }
#define scn(arr, n) \
    fl(i, 0, n) { cin >> arr[i]; }
#define mx(arr) *max_element(arr.begin(), arr.end())
#define mn(arr) *min_element(arr.begin(), arr.end())
#define sm(v) accumulate(v.begin(), v.end(), 0LL);
#define yes cout << 'Y' << 'E' << 'S'
#define no cout << 'N' << 'O'
#define all(v) v.begin(), v.end()
#define pairout(v, n) \
    fl(i, 0, n) { cout << v[i].first << ' ' << v[i].second << endl; }
#define pairin(v, n) \
    fl(i, 0, n) { cin >> v[i].first >> v[i].second; }
#define MP make_pair
#define PB push_back
#define FL                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
bool isPerfectSquare(long double x)
{
    if (x >= 0)
    {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
 
ll lcm(ll a, ll b)
{
    ll ans = (a * b) / __gcd(a, b);
    return ans;
}
 
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
void dfs(ll root, ll parent, vector<vector<ll>> &adj, vector<ll> &dist, ll level)
{
    dist[root] = level;
    vector<ll> n = adj[root];
    for (auto i : n)
    {
        if (i != parent)
        {
            dfs(i, root, adj, dist, level + 1);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> adj(n);
        fl(i, 0, n - 1)
        {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<ll> distx(n, 0);
        dfs(0, -1, adj, distx, 0);
        ll maxi = mx(distx);
        ll y;
        fl(i, 0, n)
        {
            if (distx[i] == maxi)
            {
                y = i;
            }
        }
        // cout << y << endl;
        vector<ll> disty(n, 0);
        dfs(y, -1, adj, disty, 0);
        ll maxi1 = mx(disty);
        ll z;
        fl(i, 0, n)
        {
            // cout<<i+1<<' '<<
            if (disty[i] == maxi1)
            {
                z = i;
            }
        }
    
 
        // cout << z << endl;
        cout<<maxi1<<endl;
 
    }
 
    return 0;
}
