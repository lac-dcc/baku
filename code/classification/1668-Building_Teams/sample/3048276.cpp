#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e17+1
ll const M = 1e5+10;
ll const N = 100001;
 
vector<ll> adj[N];
bool vis[N],group[N],bad;
 
void dfs(ll n, bool g=0)
{
    vis[n]= true;
    group[n]=g;
    for(auto c: adj[n])
    {
        if(vis[c])
        {
            if(group[c]==g)bad=true;
        } else {
            dfs(c,!g);
        }
    }
}
 
void solve(int t){
    // cout << "Case #" << t << ": ";
    ll n,m; cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
   }
   memset(vis,false,sizeof(vis));
   for(ll i=1;!bad and i<=n;i++)
   {
     if(!vis[i])
     {
        dfs(i);
     }
   }
   if(bad)cout<<"IMPOSSIBLE"<<endl;
   else {
    for(ll i=1;i<=n;i++)
    {
        cout<<group[i]+1<<" ";
    }
    cout<<endl;
   }
}
    
    int main(){
        ios_base::sync_with_stdio(false), cin.tie(nullptr);
        // freopen("moocast.in", "r", stdin);
        // freopen("moocast.out", "w", stdout);
        // int T;
        // cin >> T ;
        // for(int t = 1; t <= T; t++) 
        solve(1);
    }
