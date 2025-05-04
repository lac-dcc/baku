#include <bits/stdc++.h>
typedef long long ll;
#define al(x) x.begin(),x.end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define vl vector<ll>
#define pp endl
#define pb push_back
#define ff first
#define ss second
#define pi 3.1415926536
#define mod 1000000007
#define ull unsigned long long
#define vcin(v) for(auto &e:v) cin>>e;
#define vcout(v) for(auto &e:v)
#define fll(i,a,n) for(long long i=a;i<n;i++)
#define bp __builtin_popcount
#define IOS  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
 
 
ll ncr(ll n, ll r)
{
  if(r>n) return 0;
  if(r>n-r) r=n-r;
  ll calc=1;
  for(ll i=1;i<=r;i++) 
    {calc*=(n-r+i); calc/=i;}
    return calc;   
}
 
ll binpow(ll a,ll b){
  ll ans=1;
  while(b){
    if(b&1) ans=(ans*a);
       b>>=1;
    a=(a*a);
  }
  return ans;
}
 
 ll sqrbin(ll a) 
 {
    ll h=mod,l=0,mid;
    while(h>l)
    {
        mid=(l+h)/2;
        if(mid*mid>a) h=mid;
        else l=mid+1; 
    }
    return l-1;
 }
 
 vector<vl> moves={{1,0},{0,1},{0,-1},{-1,0}};
 
////////////////////////////////////////////////
void solve()
{
    ll n,m,q;
    cin>>n>>m>>q;
  ll dis[n+5][n+5];
    
    for(int i=0;i<=n;i++)
         for(int j=0;j<=n;j++)
            if(i==j) dis[i][j]=0;
            else dis[i][j]=1e18;
    
    while(m--)
    {
      ll x,y,z;
      cin>>x>>y>>z;
      dis[x][y]=min(dis[x][y],z);
      dis[y][x]=min(dis[y][x],z);
 
    }
    
 
 for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
 
      
 while(q--)
 {
  ll x,y;
  cin>>x>>y;
  if(dis[x][y]==1e18) cout<<-1<<pp;
  else cout<<dis[x][y]<<pp;
 }
 }
/////////////////////////////////////////////
 int main(){
  IOS
  int t=1;
  //cin>>t;
  
while(t--)
solve();
}
