#include <bits/stdc++.h> 
  #define test int t; cin>>t; while(t--)
  #define init(arr,val) memset(arr,val,sizeof(arr))
  #define loop(i,a,b) for(int i=a;i<b;i++)
  #define loopr(i,a,b) for(int i=a;i>=b;i--)
  #define loops(i,a,b,step) for(int i=a;i<b;i+=step)
  #define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
  #define ull unsigned long long int
  #define ll long long int
  #define mp make_pair
  #define pb push_back
  #define pf push_front
  #define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
  #define all(a) a.begin(),a.end()
  #define deb(x) cerr<<#x<<' '<<'='<<' '<<x<<'\n';
 const int mod = 1e9+7;
 const int MOD = 998244353;
 inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
 inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
 inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
 using namespace std;
  
 const ll maxn = 1e5+5;
 const ll inf = 1e17;
 const double pi = acos(-1);
    ll n,m,c,d,p,q,x,y,z,minn,maxx;
    ll u,v,w;
    vector< pair<ll,ll> >G[maxn];
    bool vis[maxn];
    ll dist[maxn];
  
  signed main(){
      FAST
 
  cin>>n>>m;
  for(ll i=1;i<=n;i++){
      dist[i]=inf+1;
      vis[i]=false;
  }
 
for(ll i=1;i<=m;i++){
    cin>>u>>v>>w;
    G[u].push_back({v,w});
  
}
 
 
    dist[1]=0;
  priority_queue< pair<ll,ll> , vector< pair<ll,ll> > , greater< pair<ll,ll> > >pq;
 
  pq.push({dist[1],1});
 
  while(!pq.empty()){
      ll a=pq.top().second;
      pq.pop();
 
      if(!vis[a]){
          vis[a]=true;
      }else{
          continue;
      }
 
    for(auto b:G[a]){
        if(!vis[b.first]){
        if(dist[b.first]>dist[a]+b.second){
            dist[b.first]=dist[a]+b.second;
            pq.push({dist[b.first],b.first});
        }
        }
    }
 
  }
 
  for(ll i=1;i<=n;i++){
      cout<<dist[i]<<" ";
  }
 
 
 
  
  
     return 0;
  }
