#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define st(v) sort(v.begin(),(v.begin()+v.size()))
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
 
bool is_prime(ll n) {
    if (n == 1) {
        return false;
    }
    ll i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }
    return true;
}
ll powe(ll a,ll b){ll result=1;while(b>0){if(b%2 == 1){result *= a;} a *= a;b /= 2;}return result;}
 
long double distance(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}
 
 
ll lcm(ll x,ll y){
ll pro=x*y;
ll h=__gcd(x,y);
ll lc=pro/h;
return lc;
}
//______________________________________ncr________________________
ull power(ull x,ull y, ull p)
{
    ull res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {  // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
ull modInverse(ull n,ull p)
{
return power(n, p - 2, p);
}
// Returns nCr % p using Fermat's little
// theorem.
ull nCrModPFermat(ull n,ull r,vector<ull>&fac, ull p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
 
 
//___________________________________graph__________________________
 /*ll dx[]={0,0,1,-1};
 ll dy[]={1,-1,0,0};
 string ds="RLDU";
 
 ll n,m;
 bool possible(ll x,ll y){
 	//cout<<n<<" "<<m<<" "<<x<<" "<<y<<" possible"<<endl;
 
     return (x<n&&x>=0&&y<m&&y>=0);
 }*/
 /*int possible(int x,int y,int n,int m,vector<vector<int>>&vis,vector<vector<int>>&grid){
if(x<0 || y<0 || x==n ||y==m ||vis[x][y]==1 || grid[x][y]==0)return 0;
return 1;
}
void dfs(ll i,vvl&grid,vl&vis,vl&par,vl&coun){
if(vis[i]==1)return;
vis[i]=1;
f(j,grid[i].size()){
if(vis[grid[i][j]])continue;
par[grid[i][j]]=i;
coun[grid[i][j]]=coun[i]+1;
dfs(grid[i][j],grid,vis,par,coun);
}
}
*/
//_____________________________________dsu______________________
/*ll n;
vector<ll> parent(100000);
vector<ll> siz(100000,1);
void makeset(ll v) {
    parent[v] = v;
}
ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
ll union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
        return 1;
    }
    return 0;
}*/
//_________________________________________________
/*ll up[200001][20]={0};
vvl grid(200001);
vl dep(200001,0);
 
void lvl(ll src,ll par){
dep[src]=dep[par]+1;
for(int c:grid[src]){
    if(c==par)continue;
  dep[c]=dep[src]+1;
  lvl(c,src);
}
}
 
void binarylifting(ll src,ll par){
  up[src][0]=par;
  f1(i,20){
    if(up[src][i-1]!=-1)
        up[src][i]=up[up[src][i-1]][i-1];
    else up[src][i]=-1;
  }
  for(int child: grid[src]){
    if(child!=par){
        binarylifting(child,src);
    }
  }
}
 
ll liftnode(ll node,ll jump){
for(int i=19;i>=0;i--){
   if(jump==0 || node==-1){
    break;
}
    if(jump>=(1<<i)){
        node=up[node][i];
        jump-=(1<<i);
    }
}
return node;
}
 
ll lca(ll x,ll y){
if(dep[x]<dep[y]){
    swap(x,y);
}
x=liftnode(x,dep[x]-dep[y]);
if(x==y){
    return x;
}
for(int i=19;i>=0;i--){
    if(up[x][i]!=up[y][i]){
        x=up[x][i];
        y=up[y][i];
    }
}
return up[x][0];
}*/
//____________________________________solve____________________________________________
#define f(i,n) for(ll i=0;i<n;i++)
#define f1(i,n) for(ll i=1;i<n;i++)
#define vl vector<ll>
#define vvl vector<vl>
//cout<<"YES"<<endl;
int main(){
ll mod=1000000007;
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//freopen("test_input.txt","r",stdin);
//freopen("final_output.txt","w",stdout);
ll n;cin>>n;
vector<pair<pair<ll,ll>,ll>> v;
vl ends;
f(i,n){
ll x,y,z;cin>>x>>y>>z;
v.pb(mp(mp(y,x),z));
ends.pb(y);
}
st(v);
st(ends);
map<ll,ll> mpp;
f(i,n){
ll op=v[i].first.first;
ll x=lower_bound(ends.begin(),ends.end(),v[i].first.second)-ends.begin();
x--;
ll opq=0;
if(x<0)opq=0;
else opq=mpp[ends[x]];
if(i>0)mpp[op]=max(mpp[v[i-1].first.first],v[i].second+opq);
else mpp[op]=v[i].second;
}
cout<<mpp[v[n-1].first.first];
}
