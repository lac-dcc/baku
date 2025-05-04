#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define vll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))
 
const int N = 1e5+5;
const int MOD = 1e9+7;
const int maxn = 105;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
 
//U,D,L,R
char dir[4]={'U','D','L','R'};
int dx[]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[]={0, 0, -1, 1, -1, 1, -1, 1};
 
int kx[]={1, 1, 2, 2, -1, -1, -2, -2};
int ky[]={2, -2, 1, -1, 2, -2, 1, -1};
 
struct Edge
{
    int v;
    int w;
};
 
struct Node
{
    ll node,cost;
    Node(ll _node, ll _cost)
    {
        node=_node;
        cost=_cost;
    }
};
 
 
bool operator<(Node A,Node B)
{
    return A.cost>B.cost;
}
 
 
vector<Edge>adj[N];
priority_queue<Node>pq;
ll dist[N];
 
 
void dijkstra(int s,int n)
{
    for(int i=0;i<=n;i++)
    {
        dist[i]=infLL;
    }
 
    dist[s]=0;
    pq.push(Node(s,0));
 
    while(!pq.empty())
    {
        Node u=pq.top();
        pq.pop();
 
        if(u.cost>dist[u.node])
        {
            continue;
        }
 
        for(Edge e:adj[u.node])
        {
            if(dist[e.v]>dist[u.node]+e.w)
            {
                dist[e.v]=dist[u.node]+e.w;
                pq.push(Node(e.v,dist[e.v]));
            }
        }
    }
}
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n,m;
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        //adj[v].pb({u,w});
 
    }
 
    dijkstra(1,n);
 
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
 
    return 0;
}
