// JOSH TYPE// 
// Submission by Ritik Jaat // ios_base::sync_with_stdio(false); cin.tie(NULL);
    
#include <bits/stdc++.h>
#define ll            long long 
#define pb            push_back
#define eb            emplace_back
#define ld            long double
#define sz            size()
#define foo(i,a,b)    for (ll i=a;i<b;i++)
#define pll           pair<ll,ll>
#define mii           map<ll,ll>
#define ed            "\n"
#define ct            cout
#define m_p           make_pair
#define vi            vector<ll>
#define vpll           vector<pll>
#define ff            first
#define ss            second
#define mod           998244353
#define int  long long
using namespace std;
const int inf=1e9+1;
vector<vector<int>> vc;
vector<int> color;
vector<bool> vis;
int dfs(int node,int colr)
{
    vis[node]=true;
    color[node]=colr;
    for(auto child:vc[node])
    {
        if(vis[child]==false)
        {
            int res=dfs(child,colr^1);
            if(res==0)return 0;
        }
        else
        {
            if(color[node]==color[child])return 0;
        }
    }
    return 1;
}
void soln()
{
  int n,m;
  cin>>n>>m;
  vc.resize(n+1);
  color.resize(n+1);
  vis.resize(n+1);
  foo(i,0,m)
  {
    int x,y;
    cin>>x>>y;
    vc[x].pb(y);
    vc[y].pb(x);
  }
  foo(i,1,n+1)
  {
    if(vis[i]==0)
    {
        int r=dfs(i,0);
        if(r==0)
        {
            ct<<"IMPOSSIBLE"<<ed;
            return;
        }
    }
  }
  foo(i,1,n+1)
  {
    ct<<color[i]+1<<" ";
  }
  ct<<ed;
}
 
int32_t main()
{
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("ol.txt","w",stdout);
  #endif 
   // int t; cin>>t;
   // while(t--)
   //  {
    soln();
 
     // }
   return 0;
}
