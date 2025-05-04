#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb emplace_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define ump unordered_map
#define mp map
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define all(n) n.begin(), n.end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
 
void swap(ll &x, ll &y)
{
    ll temp = x;
    x = y;
    y = temp;
}
void google(ll t) { cout << "Case #" << t << ": "; }
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
ll expom(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    x = x % m;
    if (y % 2 == 0)
        return expom(x * x, y / 2, m) % m;
    return (x * expom(x * x, y / 2, m)) % m;
}
inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
inline ll ceil(ll a, ll b) { return (a % b == 0) ? a / b : a / b + 1; }
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
 
bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] =(color[node]==1)?2:1;
            if(!bipartiteDfs(it, adj, color)) {
                return false; 
            }
        } else if(color[it] == color[node]) return false; 
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n,int color[]) {
    
    for(int i = 1;i<=n;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; 
}
void solve()
{
    //Start from here....
   int n,m;
    cin>>n>>m;
    vector<int> adj [n+1];
      	for(auto i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
        int color[n+1];
    memset(color, -1, sizeof color);
    if(checkBipartite(adj,n,color)) {
        for(int i=1;i<=n;i++)
            cout<<color[i]<<" ";
    }
    else cout<<"IMPOSSIBLE";
}
 
int main()
{
    // clock_t begin = clock();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    fastio;
    ll t = 1;
    //cin >> t;
 
    while (t--)
    {
        solve();
    }
    // #ifndef ONLINE_JUDGE
    //     clock_t end = clock();
    //     cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
    // #endif
    return 0;
}
