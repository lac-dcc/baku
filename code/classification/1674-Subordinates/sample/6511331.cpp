#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll ;
using namespace std ;
#define sortv(vec) sort(vec.begin(),vec.end())
#define rep(i,n) for(ll i=0;i<n;++i)
#define f(i,a,n) for(ll i=a;i<=n;++i)
#define g(i,a,n) for(int i=a;i>=n;--i)
#define pb push_back
#define F first
#define S second
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
 
const double pie = 3.14159265358979323846;
const ll M = 1e9+7;
 
ll factorial(ll n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
 
ll BinExpRecur(ll a , ll b){
    if(b==0) return 1;
    ll res = BinExpRecur(a,b/2);
    if(b&1){
        return (a*((res*res)%M))%M;
    }
    else return (res*res)%M;
}
 
ll BinExpIter(ll a, ll b){
    ll ans = 1 ;
    while(b){
        if(b&1){
            ans = (ans*a)%M;
        }
        a = (a*a)%M;
        b >>=1 ;
    }
    return ans ;
}
 
 
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
   if(a.second != b.second){
       return a.second < b.second ;
   }
   return a.first > b.first ;
}
 
ll modFact(ll n, ll p)
{
    if (n >= p)
        return 0;
 
    ll result = 1;
    for (int i = 1; i <= n; i++)
        result = (result * i) % p;
 
    return result;
}
 
 
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
 
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
 
 
void sieve(vector<bool> &is_prime , ll N ){
    for(int i=2;i<N;i++){
        if(is_prime[i]){
            for(int j=i*2;j<N;j+=i){
                is_prime[j]=0;
            }
        }
    }
}
 
const ll N = 2e5+5;
vector<vector<ll>> adj(N);
ll ans[N];
 
void dfs(ll vertex , ll par){
    ll k =0;
    for(auto i : adj[vertex]){
        if(i!=par){
            dfs(i,vertex);
            k += ans[i] + 1;
        }
    }
    ans[vertex]=k;
}
 
 
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
     ll n ; cin >> n ;
     f(i,2,n){
        ll x ; cin >>  x;
        adj[x].pb(i);
        adj[i].pb(x);
     }
     dfs(1,-1);
     f(i,1,n) cout << ans[i]<<" ";
}
