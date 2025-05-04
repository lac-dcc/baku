#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
#define ll                    long long
#define Author                std::ios_base::sync_with_stdio(0);
#define u_map                 unordered_map<ll,ll>
#define n_map                 map<ll,ll>
#define n_pair                pair<ll,ll>
#define all(v)                v.begin(),v.end()
#define frr(i,j,k)           for(ll i=j; i<k; i++)
#define frp(i,j,k)           for(ll i=j; i>=k; i--)
#define pb(a)                 push_back(a)
#define debug(a)              cout<<a<<endl
#define lb(v,t)               lower_bound(all(v),t)-v.begin()
#define ub(v,t)               upper_bound(all(v),t)-v.begin()
// #define in(t)                 scanf("%lld",&t);
// #define out(t)                printf("%lld\n",t);
#define inputarr(a,n)        for(int i=0;i<n;++i) cin>>a[i]
#define printarr(a,n)        for(int i=0;i<n;++i) cout<<a[i]<<" "
#define mem(a)              memset(a,0,sizeof(a))
#define int_max     INT_MAX64
#define F first
#define S  second
vector<bool>prime(1000005,true);
ll abst(ll a){if(a<0)return -a; return a;}
void sieve(){ll i;ll j;prime[0]=prime[1]=false;for(i=2; i*i<=1000000; i++){if(prime[i]){for(j=2*i; j<=1000000; j+=i){prime[j]=false;}}}}
ll lcm(ll a, ll b){return (a*b)/__gcd(a,b);}
ll mod=1e9+7;
bool isPrime(ll n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (ll i = 5; i*i<=n;i=i+6) 
        if(n%i==0||n%(i+2)==0) 
            return false; 
    return true; 
}
void decToBinary(int n,vector<ll>&v) 
{ 
    int i = 0; 
    while (n > 0) { 
        v[i] += n % 2; 
        n = n / 2; 
        i++; 
    } 
}
ll fact(ll n,ll p) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = (res * i)%p; 
    return res; 
} 
ll modFact(ll n, ll p) 
{ 
    if (n >= p) 
        return 0; 
  
    ll result = 1; 
    for (ll i = 1; i <= n; i++) 
        result = (result * i) % p; 
  
    return result; 
}
ll getSum(ll n) {  
    ll sum=0; 
    while(n!=0) { 
        sum=sum+n%10; 
        n=n/10; 
    }  
    return sum; 
} 
ll largestPowerOf2(ll n){
    ll p=2;
    while(p<=n){
        p=2*p;
    }
    p=p/2;
    return p;
}
bool isPowerOfTwo(ll n)  {  
    if (n == 0)  
        return 0;  
    while (n != 1)  
    {  
        if (n%2 != 0)  
            return 0;  
        n = n/2;  
    }  
    return 1;  
}
bool isPal(string s){
    frr(i,0,(ll)s.length()/2){
        if(s[i]!=s[s.length()-i-1]){
            return false;
 
        }
    }
    return true;
}
 
// ll find(vector<ll>&par,ll p){
//     if(par[p]!=p){
//         par[p]=find(par,par[p]);
//     }
//     return par[p];
// }
 
ll maxSubArraySum(vector<ll>&a, ll size) { 
    ll max_so_far=0 ;
    ll curr_max=0;
    for (ll i = 0; i < size; i+=1) { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max); 
    } 
    return max_so_far; 
}
ll minSubarraySum(vector<ll>&a, ll size) { 
    ll min_so_far=0 ;
    ll curr_min=0;
    for (ll i = 0; i < size; i+=1) { 
        curr_min = min(a[i], curr_min+a[i]); 
        min_so_far = min(min_so_far, curr_min); 
    } 
    return min_so_far; 
}
bool valid(ll i, ll j,ll n,ll m){
    if(i<0 || j<0 || j>=m || i>=n) return false;
    return true;
}
bool perfectCube(ll N) 
{ 
    ll start = 1, end = N; 
    while (start <= end) { 
        ll mid = (start + end) / 2; 
        if(mid>=1000000){
            end=mid-1;
            continue;
        }
        if (mid * mid * mid == N) { 
            return true; 
        } 
        if (mid * mid * mid < N) { 
            start = mid + 1; 
        } 
        else
            end = mid - 1; 
    } 
  
    return false;
} 
// int getsum(int x){
//     int sum=0;
//     while(x>0){
//         sum+=bit[x];
//         x=x-(x&-x);
//     }
//     return sum;
// }
// void update(int i,int x){
// while(i<bit.size()){
//     bit[i]+=x;
//     //cout<<i<<endl;
//     i+=(i&-i);
// }
// }
ll lower(vector<ll>&v,ll t){
    ll j=lower_bound(all(v),t)-v.begin();
    return j;
}
ll upper(vector<ll>&v,ll t){
    ll j=upper_bound(all(v),t)-v.begin();
    return j;
}
ll fac[1000001];
void compute(){
    fac[0] = 1;
    for (ll i = 1; i <= 1000001; i++)
        fac[i] = (fac[i - 1] * i) % mod;
}
 
ll power(ll x,ll y,ll p){
    unsigned long long res = 1; 
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll modInverse(ll n,ll p){
    return power(n, p - 2, p);
}
ll nCr(ll n,ll r, ll p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
vector<pair<pair<ll,ll>,char>>dir={{{0,1},'R'},{{1,0},'D'},{{-1,0},'U'},{{0,-1},'L'}};
//bool vis[100001],rect[100001];
//vector<ll> adj[200001],rev[100001];
//ll dp[100001],par[100001],dist[100001];
ll find(string& a,string& b,ll i,ll j,vector<vector<ll>>&dp){
    if(i==a.length()) return b.length()-j;
    if(j==b.length()) return a.length()-i;
    if(dp[i][j]!=-1) return dp[i][j];
    ll res=INT_MAX;
    if(a[i]==b[j]) return dp[i][j]=find(a,b,i+1,j+1,dp);
    res=min(res,1+find(a,b,i+1,j+1,dp));
    res=min(res,1+find(a,b,i,j+1,dp));
    res=min(res,1+find(a,b,i+1,j,dp));
    return dp[i][j]=res;
}
void solve(){
    string a,b;
    cin>>a>>b;
    ll n=a.length(),m=b.length();
    vector<vector<ll>>dp(n,vector<ll>(m,-1));
    cout<<find(a,b,0,0,dp)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    //sieve();
    //compute();
    while(t--){
        solve();
    }
    // for(int i=1;i<=t;i++){
    //     cout<<"Case #"<<i<<": ";
    //     solve();
    // }
}