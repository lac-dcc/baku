//~......................................................................
//~~~~~~~~~~~~~~~~~~~~~~~~~AUTHOR - MANAS RAWAT~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~USERNAME - importlogic~~~~~~~~~~~~~~~~~~~~~~~
//~......................................................................
 
#include <bits/stdc++.h>
 
 
#define loop(a,b,c)       for(int a=b;a<c;a++)
#define loopr(a,b,c)      for(int a=b;a>c;a--)
#define nl                ("\n")
#define gcd(a,b)          __gcd(a,b)
#define int               long long
#define vi                vector<int>
#define vb                vector<bool>
#define vs                vector<string>
#define pb(n)             push_back(n)
#define mp(a,b)           make_pair(a,b)
#define ff                first
#define ss                second             
#define sz(s)             (s.size())*1LL
#define google(T)         cout<<"Case #"<<T<<": "
#define testcases         int t; cin>>t; loop(i,1,t+1) solve(i)
#define mod               1000000007
#define modadd(a,b,c)     ((a%c)+(b%c))%c
#define modmul(a,b,c)     ((a%c)*(b%c))%c
#define modsub(a,b,c)     ((a%c)-(b%c))%c
#define all(v)            (v).begin(),(v).end()
 
using namespace std;
 
 
void RUN()
{
  ios::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0);
}
 
void sieve(int n);
int power(int a,int n);
 
// int dx[] = {-1,1,0,0,-1,-1,1,1};
// int dy[] = {0,0,-1,1,-1,1,-1,1};
 
 
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 
 
vector<vi> g(100000);
vb vis(100000);
 
 
void dfs(int node){
  vis[node] = 1;
  for(auto child : g[node]){
    if(!vis[child]) dfs(child);
  }
}
 
void solve(int T)
{
  int n,m;
  cin>>n>>m;
  loop(i,0,n){
    g[i].clear();
    vis[i]=0;
  }
 
 
  loop(i,0,m){
    int a,b;
    cin>>a>>b;
    --a,--b;
 
    g[a].pb(b);
    g[b].pb(a);
  }
 
  vi res;
  loop(i,0,n){
    if(!vis[i]){
      res.pb(i);
      dfs(i);
    }
  }
 
  cout<<sz(res)-1<<nl;
 
  if(sz(res)>1){
    loop(i,1,sz(res)){
      cout<<res[i-1]+1<<" "<<res[i]+1<<nl;
    }
  }
}
 
 
signed main()
{
  RUN();
 
 
  // testcases;
  solve(1);
 
 
  return 0;
}
 
 
// void sieve(int n){
//   fill(all(prime),0);
//   prime[0]=prime[1]=1;
//   for(int i=2;i*i<=n;i++)
//   {
//     if(prime[i]==0){
//       for(int j=i*i;j<n;j+=i)
//       prime[j]=1;
//     }
//   }
// }
 
// int power(int a,int n)
// {
//   int res=1;
//   while(n)
//   {
//     if(n&1) {res*=a;--n;}
//     else {a*=a;n/=2;}
//   }
//   return res;
// }


