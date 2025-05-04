#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
const ll M = 1e9 + 7;
ll mod(ll a)
{
    return (a % M + M) % M;
}
ll add(ll a, ll b)
{
    return mod(mod(a) + mod(b));
}
ll prod(ll a, ll b)
{
    return mod(mod(a) * mod(b));
}
ll modpow(ll a, ll b)
{
    if (b == 0)
        return 1LL;
    if (b == 1)
        return a % M;
    ll res = 1;
    while (b)
    {
        if (b % 2 == 1)
            res = prod(res, a);
        a = prod(a, a);
        b = b / 2;
    }
    return res;
}
bool isprime(ll a)
{
    if (a <= 1)
        return false;
    for (ll i = 2; i * i <= a; i++) //if a number is not a prime number then it has a factor between 2 and root of n
    {
        if (a % i == 0)
            return false;
    }
    return true;
}
int noofdigits(ll number)
{
    return floor(log10(number) + 1);
}
vector<ll> primefactors(ll a)
{
    vector<ll> res;
    for (ll i = 2; i * i <= a; i++)
    {
        while (a % i == 0)
        {
            res.push_back(i);
            a = a / i;
        }
    }
    if (a > 1)
        res.push_back(a);
    return res;
}
vector<ll> dijkstra(vector<pair<ll, ll>> adj[], ll n, ll source)
{
    vector<ll> dist(n + 1);
    bool processed[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        dist[i] = 1e16;
        processed[i] = false;
    }
    dist[source] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, source});
    while (!q.empty())
    {
        pair<ll, ll> u = q.top();
        q.pop();
        if (processed[u.second])
            continue;
        for (auto s : adj[u.second])
        {
            if (dist[s.first] > u.first + s.second)
            {
                dist[s.first] = u.first + s.second;
                q.push({dist[s.first], s.first});
            }
        }
        processed[u.second] = true;
    }
 
    return dist;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> adj[n + 1];
    vector<pair<ll, ll>> adjT[n + 1];
    ll x, y, weight;
    for (ll i = 1; i <= m; i++)
    {
        cin >> x >> y >> weight;
        adj[x].push_back({y, weight});
        adjT[y].push_back({x, weight});
    }
    vector<ll> dist1 = dijkstra(adj, n, 1);
    vector<ll> dist2 = dijkstra(adjT, n, n);
    ll ans=1e17;
    for(ll i=1;i<=n;i++)
    {
        for(auto x: adj[i])
        {
            ans=min((dist1[i]+dist2[x.first]+x.second/2),ans);
        }
    }
    cout<<ans<<"\n";
}
