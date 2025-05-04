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
vector<ll>v1[200005];
 ll vis1[200005];
 vector<ll>last1;
ll level1[200003];
 void dfs1(ll node1)
 {
    vis1[node1]=1;
    level1[node1]=1;
    queue<ll>q1;
    q1.push(node1);
 
   while(!q1.empty())
   {
    ll x=q1.front();
    q1.pop();
    for(ll child1:v1[x])
    {
        if(!vis1[child1])
        {
             vis1[child1]=1;
             level1[child1]=level1[x]+1;
             q1.push(child1);
        }
    }
   }
    
 }
 
 
 vector<ll>v[200005];
 ll vis[200005];
 vector<ll>last;
ll level[200005];
 void dfs(ll node)
 {
    vis[node]=1;
    level[node]=1;
    queue<ll>q;
    q.push(node);
 
   while(!q.empty())
   {
    ll x=q.front();
    q.pop();
    for(ll child:v[x])
    {
        if(!vis[child])
        {
             vis[child]=1;
             level[child]=level[x]+1;
             q.push(child);
        }
    }
   }
 }
void solve()
{
 ll n;
 cin>>n;
 
 ll m=n-1;
 for(ll i=0;i<m;i++)
 {
    ll a,b;
    cin>>a>>b;
    
    v[a].push_back(b);
    v[b].push_back(a);
    v1[a].push_back(b);
    v1[b].push_back(a);
 
 }
 
 dfs(1);
ll mm=INT_MIN;
ll an=0;
for(ll i=1;i<=n;i++)
{
    if(level[i]>mm)
    {
        mm=level[i];
        an=i;
    }
}
 
 
 dfs1(an);
 
 
 //cout<<last.back()<<endl;
ll ans[n+2],jj=0;
ll oo=INT_MIN;
for(ll i=1;i<=n;i++)
{
   ans[i]=max(level[i],level1[i]);
   if(oo<level1[i])
   {
    oo=level1[i];
    jj=i;
   }
 
 
}
 
 memset(vis1,0,sizeof vis1);
 memset(level1,0,sizeof level1);
 
dfs1(jj);
 
for(ll i=1;i<=n;i++)
{
    ll xxx=max(ans[i]-1,level1[i]-1);
    cout<<xxx<<" ";
}
 
 
 
 cout<<endl;
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
