#include <bits/stdc++.h>
using namespace std;
 
/*typedef pair<long long, long long> ll;
const int MAX_N = 100000;
 
int n, m;
vector<ll> edge[MAX_N], back_edge[MAX_N];
long long d1[MAX_N], d2[MAX_N];
 
void dijkstra(int s, long long *d, vector<ll> adj[MAX_N])
{
    for(int i = 0; i < n; i++) d[i] = LLONG_MAX;
    d[s] = 0;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    pq.push(ll(d[s], s));
    while(!pq.empty()){
        int u = pq.top().second; long long t = pq.top().first;
        pq.pop();
        if(t != d[u]) continue;
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first;
            long long w = adj[u][i].second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push(ll(d[v], v));
            }
        }
    }
}
 
int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
 
    cin>>n>>m;
 
    for(int i = 0; i < m; i++){
        int u, v;
        long long w; cin>>u>>v>>w;
        u--; v--;
        edge[u].push_back(ll(v, w));
        back_edge[v].push_back(ll(u, w));
    }
 
    dijkstra(0, d1, edge);
    dijkstra(n - 1, d2, back_edge);
 
    for(int i = 0; i < n; i++) if(d1[i] == LLONG_MAX) d1[i] = 1000000000; else if(d2[i] == LLONG_MAX) d2[i] = 1000000000;
 
    //for(int i = 0; i < n; i++) cout<<d1[i]<<endl; cout<<endl;
    //for(int i = 0; i < n; i++) cout<<d2[i]<<endl;
 
    long long ans = LLONG_MAX;
    for(int u = 0; u < n; u++){
        for(int i = 0; i < edge[u].size(); i++){
            int v = edge[u][i].first;
            long long w = edge[u][i].second;
 
            ans = min(ans, d1[u] + d2[v] + w / 2 * 1LL);
        }
    }
 
    cout<<ans;
 
    return 0;
}*/
 
#define ll long long
 
typedef pair<ll, ll> ii;
const int MAX_N = 100000;
 
struct node
{
    long long to, dist;
    bool used;
    bool operator<(const node &a) const
    {
        if(dist > a.dist) return true;
        return false;
    }
    node(long long to, long long dist, bool used)
    {
        this -> to = to;
        this -> dist = dist;
        this -> used = used;
    }
};
 
ll n, m;
vector<ii> edge[MAX_N];
ll d[MAX_N][2];
 
ll dijkstra(ll s, ll f)
{
    for(int i = 0; i < n; i++) d[i][0] = d[i][1] = LLONG_MAX;
 
    priority_queue<node, vector<node> > pq;
    d[s][0] = 0;
    d[s][1] = 0;
 
    pq.push(node(s, 0, 0));
    while(!pq.empty()){
        ll u = pq.top().to, t = pq.top().dist;
        bool used = pq.top().used;
        pq.pop();
 
        if(t != d[u][used]) continue;
        if(u == f) break;
 
        if(!used){
            for(int i = 0; i < edge[u].size(); i++){
                int v = edge[u][i].first; long long w = edge[u][i].second;
                if(d[v][0] > d[u][0] + w){
                    d[v][0] = d[u][0] + w;
                    pq.push(node(v, d[v][0], 0));
                }
                if(d[v][1] > d[u][0] + w / 2){
                    d[v][1] = d[u][0] + w / 2;
                    pq.push(node(v, d[v][1], 1));
                }
            }
        }
        else{
            for(int i = 0; i < edge[u].size(); i++){
                int v = edge[u][i].first; long long w = edge[u][i].second;
                if(d[v][1] > d[u][1] + w){
                    d[v][1] = d[u][1] + w;
                    pq.push(node(v, d[v][1], 1));
                }
            }
        }
    }
 
    return d[n - 1][1];
 
}
 
int main()
{
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v; long long w;
        cin>>u>>v>>w; u--; v--;
        edge[u].push_back(ii(v, w));
    }
 
    cout<<dijkstra(0, n - 1);
 
    return 0;
}
