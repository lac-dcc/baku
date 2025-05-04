#include<bits/stdc++.h>
 
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
vector<int>fac(100004,1);
int MOD(int a,int b){
     return (1LL*a*b)%M;
}
ll bnr(ll a,ll b){
     ll res=1;
     while(b>0){
          if(b&1){
               res=MOD(res,a);
          }
          a=MOD(a,a);
          b>>=1;
     }
     return res;
}
int cnr(int n,int r){
     if(r>n) return 0;
     int num=fac[n];
     int den=MOD(fac[n-r],fac[r]);
     den=bnr(den,M-2);
     return MOD(num,den);
}
ll modAdd(ll a,ll b){
     return (a+b)%M;
}
ll modMul(ll a,ll b){
     return (a*b)%M;
}
ll countSetBit(ll n){
     ll cnt=0;
     for(int i=63;i>=0;i--){
          if(((1LL<<i)&n)!=0) cnt++;
     }
     return cnt;
}
// const int N=200001;
// int level[N];
// int up[N][20];
// void dfs(int node,int par,unordered_map<int,vector<int>>&adj){
//      up[node][0]=par;
//      if(par==-1) level[node]=1;
//      else level[node]=level[par]+1;
//      for(int i=1;i<=19;i++){
//           if(up[node][i-1]==-1) up[node][i]=-1;
//           else up[node][i]=up[up[node][i-1]][i-1];
//      }
//      for(auto negh:adj[node]){
//           if(negh!=par) dfs(negh,node,adj);
//      }
// }
// int binary_lift(int node,int k){
 
//      for(int i=19;i>=0;i--){
//           if(k==0 || node==-1) break;
//           if((k&(1<<i))!=0){
//                node=up[node][i];
//                k&=(~(1<<i));
//           }
//      }
//      return node;
// }
// int LCA(int u,int v){
//      if(level[u]<level[v]) swap(u,v);
//      u=binary_lift(u,level[u]-level[v]);
//      if(u==v) return u;
//      for(int i=19;i>=0;i--){
//           if(up[u][i]!=up[v][i]){
//                u=up[u][i];
//                v=up[v][i];
//           }
//      }
//      return binary_lift(u,1);
// }
const int N=200001;
int vis[N];
int subtree[N];
int dp[N][3];
unordered_map<int,vector<int>>adj;
void dfs(int node){
     vis[node]=1;
     //cout<<node<<endl;
     vector<int>child;
     vector<pair<int,int>>ans;
     for(auto negh:adj[node]){
          if(vis[negh]==1) continue;
          dfs(negh);
          child.pb(negh);
     }
     for(auto v:child) dp[node][0]=max(dp[node][0],max(dp[v][0],dp[v][1]));
         // debug(node);
          // debug(child);
    
    for(auto v:child) dp[node][2]=max(dp[node][2],dp[v][2]);
     dp[node][2]++;
 
    if(child.size()<2) dp[node][1]=dp[node][2]-1;
    else{
       debug(node);
       vector<int>h;
       for(auto v:child) h.pb(dp[v][2]);
       sort(all(h));
       debug(h);
       int m=h.size();
       debug(dp[node][1]);
       dp[node][1]=h[m-1]+h[m-2];
       debug(dp[node][1]);
 
    }
     
 
}
void solve(){
     ll n;
     cin>>n;
     for(int i=2;i<=n;i++){
          int a,b;
          cin>>a>>b;
          adj[b].pb(a),adj[a].pb(b);
     }
     dfs(1);
     // for(int i=0;i<11;i++){
     //      for(int j=0;j<3;j++) cout<<dp[i][j]<<" ";
     //           cout<<endl;
     // }
   
     cout<<max(dp[1][0],dp[1][1])<<endl;
     
 
    }
int main() {
#ifndef ONLINE_JUDGE
     freopen("Error.txt", "w", stderr);
#endif 
     fastio();
  //   for(int i=2;i<=100003;i++) fac[i]=MOD(fac[i-1],i);
  
    
       solve();
     //  ll t;
     // cin>>t;
     // while(t--) solve();
    
}
