//arif_17
//MBSTU
//LEVEL:0
//GAME ON:->
#include<bits/stdc++.h>
using namespace std;
//          A         R R R    I     FFFFF
//       A  A  A      R R      I     FFFFF
//     A         A    R   R    I     F
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
//using order_set = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;//for multiset
using order_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
#define N 200005
#define  arif_fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mx ((int)1e9 + 5)
#define arif 0
//random value generator
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
inline ll gen_random(ll l,ll r)
{
return uniform_int_distribution<ll>(l,r)(rng);
}
 
#define SetBit(x,k) (x=(1ll<<k))     // 0 bit ke 1 korbe
#define ClearBit(x,k) (x&=~(1ll<<k)) // 1 bit ke 0 korbe
#define CheckBit(x,k) ((x>>k)&1)     //check korbe 1 na 0 ??
 
// vector sort multiple way
bool cmp(pair<ll,ll>&x,pair<ll,ll>&y)
{
if (x.second != y.second) {
return x.second < y.second;
}
return x.first > y.first;
}
 
const ll mod=1000000007;
 
int64_t fact(ll n)
{
if(n==0)return 1;
return (n*fact(n-1))%mod;
}
 
int64_t powermod(ll a, ll b){
if(b==0) return 1;
if(b%2==0){
ll x = powermod(a, b/2);
return (x*x)%mod;
}
else {
ll x = powermod(a, b/2);
return ((x*x)%mod * a)%mod;
}
return 0;
}
 
int64_t inversemod(ll a)
{
return powermod(a,mod-2);
}
 
int64_t ncr(ll n,ll r)
{
if(r==0)return 1;
if(r>n)return 0;
return ((fact(n))*inversemod((fact(r)*fact(n-r))%mod))%mod;
}
int parent[N];
int sz[N];
void make_set(int n){
for (int i = 0; i <= n; i++){
parent[i] = i;
sz[i] = 1;
}
}
int find_set(int v){
if (v == parent[v])
return v;
return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b){
a = find_set(a);
b = find_set(b);
if (a != b){
if (sz[a] < sz[b])
swap(a, b);
parent[b] = a;
sz[a] += sz[b];
 }
}
 void dfs(ll node,vector<ll>v[],vector<ll>&vis)
 {
   vis[node]=1;
   for(ll child:v[node])
   {
    if(!vis[child])
    {
        dfs(child,v,vis);
    }
   }
 
 
 
 }
 
 
void solve()
{
 
 ll n,m;
 cin>>n>>m;
 vector<ll>v[n+1];
 vector<ll>vis(2*1e5+2,0);
 
 while(m--)
 {
 
   ll a,b;
   cin>>a>>b;
   v[a].push_back(b);
   v[b].push_back(a);
 }
   dfs(1,v,vis); 
 
   ll cnt=0;
   vector<ll>vv;
   for(ll i=2;i<=n;i++)
   {
    //cout<<i<<" "<<vis[i]<<" check"<<endl;
      if(!vis[i])
      {
        cnt++;
        vv.push_back(i);
        dfs(i,v,vis); 
      }
   }
  cout<<cnt<<endl;
 
  for(ll h:vv)
  {
    cout<<1<<" "<<h<<endl;
  }
 
 
 
 
 
}
 
 
int main()
{
arif_fast;
ll t=1;
//cin>>t;
while(t--)
{
solve();
 
}
 
 
}
