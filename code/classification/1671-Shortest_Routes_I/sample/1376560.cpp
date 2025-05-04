#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a) for (int i = a; i >= 0; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define repll(i, a, n) for (lli i = a; i <= n; i++)
#define mkp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define lli long long int
#define ii int, int
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<long long int>
#define vpi vector<pair<int, int>>
#define vvlli vector<vector<long long int>>
#define INF 1000000007
#define MAXLL 1e18
#define endl '\n'
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define asort(v) sort(v.begin(), v.end())
#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define all(v) v.begin(), v.end()
#define umap unordered_map
#define uset unordered_set
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define input(a)      \
    for (auto &i : a) \
        cin >> i;
using namespace std;
 
vector<pair<ll, ll>> adj[100004];
ll dist[100005];
bool vis[100004];
ll n, m;
void Dijkstra()
{
    // priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    priority_queue<pair<ll, ll>> pq;
 
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        ll node = pq.top().ss;
        ll node_d = pq.top().ff;
        pq.pop();
        if (vis[node])
            continue;
        vis[node] = true;
        for (auto e : adj[node])
        {
            if (dist[e.ff] > e.ss - node_d)
            {
                dist[e.ff] = e.ss - node_d;
                pq.push({-dist[e.ff], e.ff});
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return;
}
void solve()
{
    // cout << fixed << setprecision(10);
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
    }
    for (ll i = 1; i <= n; ++i)
    {
        dist[i] = 1e18;
    }
    Dijkstra();
    return;
}
int main()
{
    fastio;
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
 
// typedef long long ll;
// typedef vector<ll> vl;
// typedef pair<ll, ll> pll;
// typedef vector<pll> vll;
 
// #define pb push_back
// #define F first
// #define S second
 
// #define fastio()                  \
//     ios_base::sync_with_stdio(0); \
//     cin.tie(0);                   \
//     cout.tie(0);
 
// ///**************************************************** C o d e ****************************************************///
// ///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=///
// ll n, m, dist[100005];
// vector<pair<ll, ll>> adj[100005];
// bool vis[100005];
 
// void Dijkstra()
// {
//     priority_queue<pll> q;
//     q.push({0, 1});
//     dist[1] = 0;
//     while (!q.empty())
//     {
//         ll node_d = q.top().ff, node = q.top().ss; ///node_d is negatiadje cost for nodeth node
//         q.pop();
//         if (vis[node])
//             continue;
//         vis[node] = true;
//         for (auto i : adj[node])
//         {
 
//             if (dist[i.F] > i.S - node_d)
//             { ///if not adjisited or shorter route
 
//                 dist[i.F] = i.S - node_d; ///updating
 
//                 q.push({-dist[i.F], i.F}); ///pushing negatiadje cost and node number
//             }
//         }
//     }
//     for (ll i = 1; i <= n; i++)
//         cout << dist[i] << ' '; ///printing
//     cout << '\n';
// }
// int main()
// {
//     fastio();
//     cin >> n >> m;
//     while (m--)
//     {
//         ll a, b, c;
//         cin >> a >> b >> c;
//         adj[a].pb({b, c});
//     }
 
//     for (ll i = 1; i <= n; i++)
//         dist[i] = 1e18;
//     Dijkstra();
//     return 0;
// }
