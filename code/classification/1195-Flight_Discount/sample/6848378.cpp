#include <bits/stdc++.h>
#define int long long
#define pii pair <int, int>
#define fi first
#define se second
#define pb push_back
 
using namespace std;
 
const int N=1e5+5;
const int inf=1e18;
 
int n, m;
int d[2][N];
vector <pii> ke[N], ke2[N], vv;
map <pii, int> mp;
bool ck[N];
 
void dijkstra(int s, int ckk)
{
    if(ckk) for(int i=1; i<=n; i++) ke[i]=ke2[i];
    int wwe;
    if(s==1) wwe=0;
    else wwe=1;
    for(int i=1; i<=n; i++) d[wwe][i]=inf, ck[i]=false;
    d[wwe][s]=0;
    priority_queue < pii, vector <pii>, greater <pii> > q;
    q.push({0, s});
    while(q.size())
    {
        int u=q.top().se;
        q.pop();
        if(ck[u]) continue;
        ck[u]=true;
        for(auto e : ke[u])
        {
            int v=e.fi;
            int w=e.se;
            if(d[wwe][v]>d[wwe][u]+w) d[wwe][v]=d[wwe][u]+w, q.push({d[wwe][v], v});
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].pb({v, w});
        ke2[v].pb({u, w});
        mp[{u, v}]=w;
        vv.push_back({u, v});
    }
    dijkstra(1, 0);
    dijkstra(n, 1);
    int kq=1e18;
    //for(int i=1; i<=n; i++) cout << d[0][i] << " " << d[1][i] << "\n";
    for(auto x : vv)
    {
        kq=min(kq, d[0][x.fi]+d[1][x.se]+mp[{x.fi, x.se}]/2);
    }
    cout << kq;
}
