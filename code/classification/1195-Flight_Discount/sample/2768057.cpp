#include <bits/stdc++.h>
 
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vb>
#define pb push_back
#define loop(i,a,b) for(int i = a ; i < b ; i++)
#define autoDeb(Arr) for(auto elem: Arr) cout<<elem<<" "; \
    cout<<endl;
    #define YES cout << "YES"<<endl;
#define NO cout << "NO" << endl;
const int N = 1e5+1;
const long long int INF = 1e18;
using namespace std;
vvll adj[N];
vvll edges;
 
ll n,m;
 
 
vll dijkstra(int src)
{
    vll dist(n+1,INF);
    
    vector<bool> vis(n+1,false);
 
    dist[src] = 0;
 
    loop(i,1,n+1)
    {
        ll v = -1;
        loop(j,1,n + 1)
        {
            if(vis[j] == 0 && (v == -1 || dist[j] < dist[v] ))
                v = j;
        }
 
        vis[v] = 1;
 
        for(auto edge : adj[v])
        {
            ll to = edge[0];
            ll wt = edge[1];
            if(dist[to] > dist[v] + wt)
            {
                dist[to] = dist[v] + wt;
            }
 
        }
    }
    return dist;
}
 
 
vll djk(int src)
{
    vll dist(n+1,INF);
    dist[src] = 0;
    set<vll> s;
    s.insert({0,src});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for(auto elem: adj[x[1]]){
            if(dist[elem[0]] > dist[x[1]] + elem[1])
            {
                s.erase({dist[elem[0]],elem[0]});
                dist[elem[0]] = dist[x[1]] + elem[1];
                s.insert({dist[elem[0]],elem[0]});
            }
        }
    }
    return dist;
}
 
vll a_djk(int src){
    vll dist(n+1,INF);
    vvll g[n+1];
    loop(i,0,m)
    {
        ll u = edges[i][0];
        ll v = edges[i][1];
        ll wt = edges[i][2];
        g[v].pb({u,wt});
    }
    dist[src] = 0;
    set<vll> s;
    s.insert({0,src});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for(auto elem: g[x[1]]){
            if(dist[elem[0]] > dist[x[1]] + elem[1])
            {
                s.erase({dist[elem[0]],elem[0]});
                dist[elem[0]] = dist[x[1]] + elem[1];
                s.insert({dist[elem[0]],elem[0]});
            }
        }
    }
    return dist;   
}
 
vll abc(int src){
    vll dist(n+1,INF);
    vvll g[n+1];
    loop(i,0,m)
    {
        ll u = edges[i][0];
        ll v = edges[i][1];
        ll wt = edges[i][2];
        g[v].pb({u,wt});
    }
    vector<bool> vis(n+1,false);
 
    dist[src] = 0;
 
    loop(i,1,n+1)
    {
        ll v = -1;
        loop(j,1,n + 1)
        {
            if(vis[j] == 0 && (v == -1 || dist[j] < dist[v] ))
                v = j;
        }
 
        vis[v] = 1;
 
        for(auto edge : g[v])
        {
            ll to = edge[0];
            ll wt = edge[1];
            if(dist[to] > dist[v] + wt)
            {
                dist[to] = dist[v] + wt;
            }
 
        }
    }
    return dist;
}
 
vvll floyd_warshall()
{
    vvll arr(n+1, vll(n+1 , INF));
    loop(i,1,n+1) arr[i][i] = 0;
    loop(i,0,m)
    {
        ll u = edges[i][0];
        ll v = edges[i][1];
        ll wt = edges[i][2];
        if(arr[u][v] > wt)
        {
            arr[u][v] = wt;
        }
    }
 
    loop(k,1,n+1)
    {
        loop(i,1,n+1)
        {
            loop(j,1,n+1)
            {
                arr[i][j] = min(arr[i][j] , arr[i][k] + arr[k][j]);
            }
        }
    }
    return arr;
}
 
 
int main(){
    speed
    cin >> n >> m;
    loop(i,0,n+1) adj[i] = vvll();
    loop(i,0,m)
    {
        ll a , b , c;
        cin >> a >> b >> c;
        edges.pb({a,b,c});
        adj[a].pb({b,c});
    }
    vvll d(n+1);
 
    d[1] = djk(1);
    //autoDeb(d[1]);
 
    d[n] = a_djk(n);
    //autoDeb(d[n]);
    ll ans = INF;
    loop(i,0,m)
    {
        ll u = edges[i][0];
        ll v = edges[i][1];
        ll wt = edges[i][2];
        //if(d[v].empty() == true) d[v] = dijkstra(v); 
        ans =  min(ans , d[1][u] + d[n][v] + wt/2);
    }
    cout<<ans<<endl;
    return 0;
}
