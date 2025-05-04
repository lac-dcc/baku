//Jai peetambra mai ki !!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define vi vector<ll> 
#define all(a) (a).begin(),(a).end()
#define rep(i,x,y) for(ll i=x; i<y; i++)
#define fill(a,b) memset(a, b, sizeof(a))
#define pii pair<ll, ll>
#define mii map<ll, ll> 
#define bc __builtin_popcountll
#define inf 9e18
#define mkp make_pair
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll gcd(ll a, ll b)
{
return b==0?a:gcd(b,a%b);
}
ll binP(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll nCr(ll n , ll r){
if (n < r) return 0;
if (r > n - r) r = n - r;
ll ans = 1; ll i;
for (i = 1; i <= r; i++){ans = (ans*(n - r + i));ans /= i;} return ans;}
ll modinv(ll a , ll m ) {return binP( a, m-2 , m);} // m is prime
const int N = 31625;
const ll MAX = 1e7+1;
// check overflows first
// Try to think as simple as you can less code more results
//(abs(v[k]-curr)<1e-10 )  for checking two floating numbers equal ot not
 
vector<vi > dp;
ll solve(string &a,string &b,ll i,ll j)
{  
   if( i>=a.length() || j>=b.length())
   {
      return max((ll)a.length()-i,(ll)b.length()-j);  
   }
 
  if(dp[i][j] != -1) return dp[i][j];
  
  ll ans;
  if(a[i] == b[j])
  {
    ans = solve(a,b,i+1,j+1);
  }
  else{
  ans = 1+solve(a,b,i,j+1);
  ans = min(ans,1+solve(a,b,i+1,j));
  ans = min(ans,1+solve(a,b,i+1,j+1));
  }
 dp[i][j] = ans;
 return dp[i][j];
}
         
int main()
{
    fastio;
  ll t;
   t = 1;
  // cin>>t;
  while(t--)
  {
   
   string a,b;
   cin>>a>>b;
   ll n,m;
    n =a.length();
    m =b.length();
 
    dp = vector<vi > (n+1,vi(m+1,-1));
     
     cout<<solve(a,b,0,0)<<"\n";
   
  }
}
