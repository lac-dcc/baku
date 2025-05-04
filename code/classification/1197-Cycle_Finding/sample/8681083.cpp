#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define inf 1e17
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
#define fr(i,x,y) for(int i=x;i<y;i++)
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
ll N;
vector<ll> A(N), ST(N);
void build(ll node, ll L, ll R)
{
ll mid = (L + R) / 2;
 build(2 * node+1, L, mid);
 build(2 * node+2, mid + 1, R);
 ST[node] = ST[2 * node+1] + ST[2 * node+2];
 }
//----------------------------//
void update(ll node, ll L, ll R, ll idx, ll val)
{
if (L == R) {
 A[idx] += val;
 ST[node] += val;
 }else {
 ll mid = (L + R) / 2;
 if (L <= idx and idx <= mid)
update(2 * node+1, L, mid, idx, val);
  else
update(2 * node+2, mid + 1, R, idx, val);
 ST[node] = ST[2 * node+1] + ST[2 * node+2];
   }}
//----------------------------//
ll query(ll node, ll tl, ll tr, ll l, ll r)
{
   if (r < tl or tr < l)
 return 0;
 if (l <= tl and tr <= r)
 return ST[node];
ll tm = (tl + tr) / 2;
  return query(2 * node+1, tl, tm, l, r)
+ query(2 * node + 2, tm + 1, tr, l, r);
}
struct range{
 ll l,r,ind;
bool operator < (const range &other) const{
if(l==other.l){
return r>other.r;}
 return l<other.l;
}};
ll binexp(ll a,ll b,ll m){
ll result =1;
while(b>0){
if(b&1){
result=(result*a)%m;
}
a=(a*a)%m;
b>>=1;
}
return result;
}
 
void solve()
{
  ll n,m,a,b,c;
  cin>>n>>m;
  vector<vector<ll>> tp(m);
  for(ll i=0;i<m;i++){
    cin>>a>>b>>c;
   tp[i].push_back(a);
   tp[i].push_back(b);
   tp[i].push_back(c);
 
  }
 
  vector<ll> dis(n+1,inf);
   dis[1]=0;
     ll u,v,w;
     vector<ll> par(n+1);
     ll flag=-1;
   for (ll i = 0; i < n ; i++) {
       flag=0;
       for(auto it:tp){
         u=it[0];
          v=it[1];
          w=it[2];
        if(dis[u]+w<dis[v]){
          dis[v]=dis[u]+w;
          par[v]=u;
          flag=v;
 
        }
       }
    }
 
    if(!flag){
      cout<<"NO"<<endl;
      return;
    }
 
    cout<<"YES"<<endl;
   for(int i = 0; i < n; i++)
        flag = par[flag];
 
    vector<int> cycle;
    for(int v = flag;; v = par[v]){
        cycle.push_back(v);
        if(v == flag && (int) cycle.size() > 1)
            break;
    }
    reverse(cycle.begin(), cycle.end());
    
 
    for(auto it:cycle){
      cout<<it<<" ";
    }
 
    
 
 
}
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
// ll t;cin>>t;while(t--)
{solve();}
return 0;
}
