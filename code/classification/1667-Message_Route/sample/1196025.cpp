#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define range(i,l,h) for(int i=l;i<h;i++)
#define endl '\n'
#define I INT_MAX
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define vt vector
#define pii pair<int,int> 
using namespace std;
using std::ios;
constexpr int MOD=1e9+7;
constexpr int mod=998244353;
template<typename T> T power(T a,T b){T r=1;while(b){if(b&1)r*=a;b/=2;a*=a;}return r;}
const int mxn=2e+5;
 
vt<int> adj[100005];
vt<int> p,d;
 
void bfs(int n)
{
  vt<bool> vis(n+1,false);
  queue<int> q;
  q.push(1);
  p[1]=1;
  d[1]=0;
  vis[1]=1;
 
  while(q.size())
  {
    int v=q.front();
    q.pop();
    for(int i:adj[v])
    {
      if(!vis[i])
      {
        q.push(i);
        vis[i]=1;
        d[i]=d[v]+1;
        p[i]=v;
      }
    }
 
  }
}
 
int main()
{
  fastio;
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  
  int n,m;
  cin>>n>>m;
  p.assign(n+1,-1);
  d.assign(n+1,1e7);
 
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
 
  bfs(n);
 
  if(d[n]==1e7)
  {
    cout<<"IMPOSSIBLE";
    return 0;
  }
 
  int r=n;
  vt<int> path;
  while(r!=1)
  {
    path.pb(r);
    r=p[r];
  }
  path.pb(1);
  reverse(all(path));
  cout<<path.size()<<endl;
  for(auto i:path)cout<<i<<' ';
  
}
