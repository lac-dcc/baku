#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define st(v) sort(v.begin(),(v.begin()+v.size()))
 
char uc[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char lc[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
 
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
 
ll countDivisors(ll n)
{
    ll cnt = 0,j=n;
    for (ll i = 2; i <= sqrt(j); i++) {
            ll fl=0;
        while(n % i == 0) {
              n/=i;
              fl=1;
              cout<<i<<endl;
        }
        if(fl==1) cnt++;
    }
    return cnt;
}
ll divisor(ll number)
    {
        for (ll i = 2; i <=sqrt(number); i++)
        {
            if (number % i == 0)
            {
                return number/i;
            }
        }
        return 1;
    }
 
     ll getSum(ll n)
    {
        ll sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }
 vector<ll> prmeFactors(ll n)
{     // Print the number of 2s that divide n
   /* while (n % 2 == 0)
    {
       co++;
        n = n/2;
    }*/
vector<ll> v;
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 2; i*i<=n;i++)
    {
        // While i divides n, print i and divide n
        if(n % i == 0)
        {   v.pb(i),v.pb(n/i);
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
 
        return v;
}
long double distance(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}
ll binomialCoeff(ll n, ll k)
{
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
 
    // Recur
    return binomialCoeff(n - 1, k - 1)
           + binomialCoeff(n - 1, k);
}
pair<int,int> primeFactors(ll n)
{   int fl=0;
    pair<int,int> x=mp(0,0);
    ll op=n;
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        fl=1;
        n = n/2;
    }
    if(fl==1){
            x.first++;
            x.second=2;
    }
    fl=0;
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(op); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            fl=1;
            n = n/i;
        }
        if(fl==1){
            x.first++;
            x.second=i;
        }
        fl=0;
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        {
            x.first++;
            x.second=n;
        }
        return x;
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
ull nPrModPFermat(ull n,ull r,vector<ull>&fac, ull p)
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
    return (fac[n] * modInverse(fac[n-r], p)) % p;
}
/*vector<ull> fac(200001,1);
//fac[0]=1;
f1(i,200001){
fac[i]=fac[i-1]*i;
fac[i]%=mod;
}*/
ll modi(ll x,ll y,ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}
 
//___________________________________graph__________________________
 /*int dx[]={0,0,1,-1};
 int dy[]={1,-1,0,0};
 string ds="RLDU";
 
 int n,m;
 bool possible(int x,int y){
 	//cout<<n<<" "<<m<<" "<<x<<" "<<y<<" possible"<<endl;
 
     return (x<n&&x>=0&&y<m&&y>=0);
 }
*/
//____________________________________solve____________________________________________
#define f(i,n) for(ll i=0;i<n;i++)
#define f1(i,n) for(ll i=1;i<n;i++)
#define vl vector<ll>
#define vvl vector<vl>
int possible(int x,int y,int n,int m,vector<vector<int>>&vis,vector<vector<int>>&grid){
if(x<0 || y<0 || x==n ||y==m ||vis[x][y]==1 || grid[x][y]==0)return 0;
return 1;
}
 
void dfs(int i,vector<vector<int>>&grid,vector<int>&vis,vector<int>&par,vector<int>&ind){
if(ind[0]==1)return;
vis[i]=1;
int p=par[i];
f(j,grid[i].size()){
    if(ind[0]==1)return;
    if(grid[i][j]==p)continue;
  if(vis[grid[i][j]]){
    ind[1]=grid[i][j];
    ind[2]=i;
    ind[0]=1;
    //cout<<"hhiugdigd"<<endl;
    return ;
  }
  else{
    par[grid[i][j]]=i;
    dfs(grid[i][j],grid,vis,par,ind);
  }
}
}
int main(){
//ll mod=1000000007;
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//freopen("test_input.txt","r",stdin);
//freopen("final_output.txt","w",stdout);
int n,m;cin>>n>>m;
vector<vector<int>> grid(n+1);
vector<int> vis(n+1,0);
vector<int> par(n+1,0);
vector<int> ind(3,0);
f(i,m){
int x,y;cin>>x>>y;
grid[x].pb(y);
grid[y].pb(x);
}
f1(i,n+1){
if(vis[i]==1)continue;
if(ind[0]==1)break;
vis[i]=1;
f(j,grid[i].size()){
if(par[grid[i][j]]==0)par[grid[i][j]]=i;
dfs(grid[i][j],grid,vis,par,ind);
if(ind[0]==1)break;
}
}
vector<int> ans;
if(ind[0]==1){
    int lol=ind[2];
    while(lol!=ind[1]){
        ans.pb(lol);
        lol=par[lol];
    }
cout<<ans.size()+2<<endl;
cout<<ind[1]<<" ";
for(int i=ans.size()-1;i>=0;i--){
    cout<<ans[i]<<" ";
}
cout<<ind[1]<<endl;
}
else cout<<"IMPOSSIBLE"<<endl;
}
