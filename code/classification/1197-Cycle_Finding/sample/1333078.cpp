#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAX = 205;
const int inf = 1e9+10;
int adj[MAX][MAX], path[MAX][MAX];
int dist[MAX][MAX] , minimax[MAX][MAX] , maximin[MAX][MAX] , prob[MAX][MAX];
bool hasPath[MAX][MAX];
struct Edge
{
    ll  a,   b,  cost;
    Edge() {};
 
    Edge(ll _a,ll _b,ll _cost)
    {
        a = _a;
        b = _b;
        cost = _cost;
    }
};
 
ll n,m;
vector<Edge> edges;
const int INF = 1000000000;
 
void solve()
{
    vector<ll> d(n+5);
    vector<ll> p(n+5, -1);
    ll x;
 
    for (int i = 0; i < n; ++i)
    {
        x = -1;
        for (Edge e : edges)
        {
            if (d[e.a] + e.cost < d[e.b])
            {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }
 
    if (x == -1)
    {
        cout << "NO";
    }
    else
    {
        for (int i = 0; i < n; ++i)
                x = p[x];
 
        vector<ll> cycle;
        for (int v = x;; v = p[v])
        {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
 
         cout << "YES"<<endl;
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}
int main()
{
   // freopen("ahsan.txt","r",stdin);
    cin>>n>>m;
    for(int i = 0; i<m; i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back(Edge(u,v,w));
    }
    solve();
 
}
