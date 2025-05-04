#include<bits/stdc++.h>
using namespace std;
 
// GCC Optimizations
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
 
//MACROS
#define ll long long
#define int ll
#define endl "\n"
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define umap unordered_map
#define all(v) v.begin() , v.end()   
#define min3(a1,b1,cost) min(a1,min(b1,cost))
#define min4(a1,b1,cost,d ) min(a1 , min(b1 , min(cost,d)))
#define max3(a1,b1,cost) max(a1 , max(b1,cost))
#define max4(a1,b1,cost,d) max(max(a1,b1) , max(cost,d))
#define vecti vector<int> 
#define ld long double    
#define debug(a) cout<<a<<endl;
#define debugtwo(a1,b1) cout<<a1<<" "<<b1<<endl;                          
#define pq priority_queue
#define pii pair<int,int>
#define frq(NN)  for(int UUU=0;UUU<(NN);UUU++)  
#define minvec *min_element
#define maxvec *max_element
#define fori(II,GG,HH) for(int II=(GG);II<(HH);II++)
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define rep(RRR,FFF)  for(auto &RRR:FFF)
#define sz(AA)  (int)((AA).size())
#define minus cout<<"-1\n";
#define zero cout<<"0\n";
#define print(x) cout<<(x)<<endl;
#define input(FDFDFDF)  for(auto &FFFF:FDFDFDF){cin>>FFFF;}
// Array utils
#define ub upper_bound
#define lb lower_bound 
#define bs binary_search
int comb(int n, int r)
{if(r<0||r>n)return 0;if((n-r)<r)r=n-r; // nCr
int a=1;for(int i=n;i>n-r;--i){a=a*i;}for(int i=1;i<r+1;++i){a=a/i;}return a;}
 
// Bitwise operations
int Set(int qq , int pos){return (qq|(1<<pos));}
int chk(int qq , int pos){return (qq&(1<<pos));}
int p2(int idx){return ((1LL<<idx));};
 
// Maths//Modular exponential
int modpow(int x, int n, int m) 
{
   if (n == 0) return 1%m;
   int u = modpow(x,n/2,m);
   u = (u*u)%m;
   if (n%2 == 1) u = (u*x)%m;
   return u;
}
 
int _pow(int a, int b)
{
   if(!b)return 1;
   ll temp = _pow(a, b/2);
   temp = (temp * temp);
   if(b%2)return (a * temp);
   return temp;
}
int ceil(int a, int b){if(a%b)return 1 + a/b;return a/b;}
 
void printvec(const vecti &AAA)
{
   for(auto SDDD:AAA)cout<<SDDD<<" ";
   cout<<endl;
}
int dx[] = {0 , 0 , -1 , 1};
int dy[] = {1 , -1 , 0 , 0};
 
const int MOD = 1e9 + 7;
const int N = 1e5+10;
const int inf = 1e18;
vecti adj[N];
queue<int>qq;
bool vis[N];
map<int,int>par;
int bfs(int n)
{
   par[1]=-1;
   vis[1]=true;
   while(!qq.empty())
   {
      int u=qq.front();
      qq.pop();
      for(auto x: adj[u])
      {
         if(vis[x])continue;
         par[x]=u;
         if(x==n)
         {
            return 1;
         }
         vis[x]=true;
         qq.push(x);
      }
   }
   return 0;
}
 
 
 
void solve()
{
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {
      int u,v;
      cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
   }
   vecti ans;
   qq.push(1);
   int f=bfs(n);
   if(f)
   {
      int x=n;
      ans.pb(n);
      while(par[x]!=-1)
      {
         ans.pb(par[x]);
         x=par[x];
      }
      reverse(all(ans));
      cout<<sz(ans)<<endl;
      printvec(ans);
   }
   else 
   cout<<"IMPOSSIBLE"<<endl;
 
}
 
signed main() 
{
   IOS
   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    freopen("output.txt" , "w" , stdout);
   #endif
   int TESTS=1;
   // cin>>TESTS;
   int GOOOGLE=1;
   while(TESTS--)
   {
      // cout<<"Case #"<<GOOOGLE<<": ";
      solve();
      // cout<<flush;
      GOOOGLE++;
   }
}