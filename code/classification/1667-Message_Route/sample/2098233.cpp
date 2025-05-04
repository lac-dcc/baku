// #pragma GCC optimize("Ofast")
// #pragma GCC target("fma")
// #pragma GCC optimization ("unroll-loops")
 
/*
General Tips
 
* Don't use >= or <= in cmp func, only <(ascend) and >(descend)
* Check MOD, LIM, BITS
* NEVER use debug tools when submitting
* in power() check if MOD is needed or not
* n = str.length() -- Check if all variables are initialised
* Always cover ternary ((?:)) in ((extra)) brackets
* check if min and max are initialsed (+- MOD*MOD or something acc to Ques)
* in graph if ERROR check for g.clear(), resize(), assign(), etc.
* Be clear with if..else if, if(x)[True if x!=0] =/ if(x>0)[True if x>0]. Check these issues properly.
* Use SieveofEratosthenes() only till 10^6 (o/w may use segmented sieve |or| bitwise sieve)
* Use factorial() only till 10^6[Change LIM accordingly] (o/w compute individually add(),mult(),sub() |or| other theorems)
* Don't use fast() in online queries
* Use pragma if simple loops are used (might reduce time sometimes[not reliable though])
* NEVER use fast cout and printf togerher.[printf is quick and order of output may mess up]
* Some primes: 1e6+69, 1e9+7, 1e9+9, 998244353[FFT], 99999999999899999
*/
 
/*
STRING
 
* string(count,char) : returns a string of len=count made of char
* str_name.substr(start idx, len of target_str) == target_str: bool if match
* to_string() to convert anything to string
* str.find(target,initial pos) : returns start index of target found else '\0'(string::npos)
* USE s+=x :O(1) instead of s=s+x :O(n)
*/
 
/*
BITWISE
 
* __builtin_popcountll(x) = #set bits in (ll)x
* __builtin_clzll(x) = #leading zeros in (ll)x   [64 bit for ll]
* __builtin_ctzll(x) = #trailing zeros in (ll)x
* use ((extra)) brackets for all bitwise operations
* add x*MOD if subtraction is done; choose x acc to need
* use (1LL<<i)
* a+b = a^b + 2*(a&b)
* binary to gray -> n^(n>>1)
* MSB position = floor(log2(n))       [0-based index]
* LSB position = floor(log2(n&(-n)))  [0-based index]
*  10^5 = 2^20 (2^17 strict)
*  10^9 = 2^31 (2^30 strict)
* 10^18 = 2^62 (2^60 strict)
*/
 
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fr(a,b,c) for(a = b;a<c;a++)
#define rfr(a,b,c) for(a = b;a>c;a--)
#define rep(i,n) for(i = 0;i<n;i++)
#define repr(i,n) for(i = n-1;i>=0;i--)
#define ii pair<ll,ll>
#define tii tuple<ll,ll,ll>
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define vi vector<ll>
#define vii vector<ii>
#define eb emplace_back
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define sz(a) (ll)((a).size())
#define filla(a,n,val) for(ll i=0;i<n;i++) a[i]=val;
#define all(o) (o).begin(),(o).end()
#define rall(o) (o).rbegin(), (o).rend()
#define bitcount __builtin_popcountll
#define nl cout <<"\n"
#define ns cout <<" "
#define o2(a,b) cout<<a<<" "<<b
#define o(a) cout << a
#define ppr(a) cout << a.first << " " << a.second
#define debug(a) cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
#define debugvi(a) for(ll idx=0;idx<a.size();idx++) {cerr<<#a<<"["<<idx<<"]: ";for(auto i:a[idx])cerr<<i<<" ";cerr<<' ';cerr<<'\n';}
#define debugpp(a) cerr<<#a<<": ";for(auto i:a)cerr<<"("<<i.first<<","<<i.second<<") ";cerr<<'\n';
#define EPSILON 1e-9
const ll MOD = 1000000007;
const ll LIM = 200005;
const ll BITS = 31;
const ll inf = 1e16;
// template<typename... T> void printout(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
 
 
auto start = std::chrono::system_clock::now();
inline void time()
{
    std::chrono::time_point<std::chrono::system_clock> end;
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    cerr<<"Time taken " << elapsed_seconds.count()*1000<<"\n";
}
 
ll addMOD(ll a,ll b)
{ll res=((a%MOD)+(b%MOD))%MOD; return res;}
ll multMOD(ll a,ll b)
{ll res=((a%MOD)*(b%MOD))%MOD; return res;}
 
ll powerMOD(ll x,ll y){
x%=MOD; y%=(MOD-1); if(x==0||x==1) return x;
ll res = 1;
while(y>0)
{ if(y&1) res = (res*x)%MOD;
y = y>>1; x = (x*x)%MOD; } 
return res%MOD; }
 
ll power(ll x,ll y){
if(x==0||x==1) return x;
ll res = 1;
while(y>0)
{ if(y&1) res = (res*x);
y = y>>1; x = (x*x); } 
return res; }
 
ll min(ll a,ll b)
{ return (a<b)?a:b; }
ll max(ll a,ll b)
{ return (a>b)?a:b; }
ll gcd(ll a, ll b)
{ if(a==0) return b; if(b==0) return a; return __gcd(a,b); }
 
 
//*** factorial() ***
/*
ll fact[LIM],invFact[LIM];
void factorial(){
    ll i;
    fact[0] = fact[1] = 1; fr(i,2,LIM) fact[i] = (fact[i-1]*i)%MOD;
    invFact[LIM-1] = powerMOD(fact[LIM-1],MOD-2)%MOD;
    rfr(i,LIM-1,0) invFact[i-1] = (i * powerMOD(fact[i],MOD-2))%MOD; }
ll nCr(ll n, ll r) { if(n<0||r<0||r>n) return 0; return (((fact[n]*invFact[r])%MOD)*invFact[n-r])%MOD; }
*/
ll nC2(ll n) { if(n<0) return 0; return ((n&1)?(((n-1)/2)*n):((n/2)*(n-1))); }
 
//*** SIEVE and SPF ***
/*
bool prime[LIM+1];
ll spf[LIM+1];
// ll totient[LIM+1],sumofDiv[LIM+1];
void SieveofEratosthenes()
{
    ll n = LIM,i,j;
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    spf[1]=1; spf[2]=2;
    for(i=4;i<=n;i+=2) { prime[i]=false; spf[i]=2;spf[i-1]=i-1; }
    for(i=3;i<=n;i+=2){
        if(prime[i])  { for(j=i*i;j<=n;j+=2*i) prime[j]=false; }
        if(spf[i]==i) { for(j=i*i;j<=n;j+=2*i) if(spf[j]==j) spf[j]=i; } }
    /*
    for(i=1;i<=n;i++) totient[i]=i;
    for(i=2;i<=n;i++) { if(totient[i]==i) { for(j=i;j<=n;j+=i) totient[j]-=(totient[j]/i); }}
    for(i=1;i<=n;i++) for(j=i;j<=n;j+=i) sumofDiv[j]+=i;
    
}
*/
/*
bool is_prime(ll n) //O(sqrt(n))
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (ll i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0) return false;
    return true;
}*/
// ll dx[]={1,-1,0,0},dy[]={0,0,-1,1};
// ll dx[]={1,1,1,-1,-1,-1,0,0},dy[]={1,-1,0,1,-1,0,1,-1};
 
bool is_pow2(ll n)
{return (n&&(!(n&(n-1))));}
ll high2(ll n)
{return (n&(~(n-1)));}
 
// bool cmp(ii &p,ii &q)
// {
//     if(p.se==q.se)
//         return p.fi<q.fi;
//     return p.se<q.se;
// }
 
vector<vi> g;
vi dist,par;
void bfs(ll st)
{
    dist.clear();
    dist = vi(sz(g),inf);
    dist[st] = 0;
    par.clear();
    par = vi(sz(g),-1);
    queue<ll> q;
    q.push(st);
    while(!q.empty())
    {
        auto u=q.front();q.pop();
        for(auto &v:g[u])
            if(dist[v] > dist[u]+1)
            {
                dist[v] = dist[u]+1;
                par[v] = u;
                q.push(v);
            }
    }
}
 
signed main()
{
    fast;
    // factorial();
    // SieveofEratosthenes();
    ll T,n,m,i,j,k,x,y,cnt,res;
    // cin>>T;
    T=1;
    while(T--)
    {
        cin>>n>>m;
        g.clear();
        g.resize(n+1);
        rep(i,m)
        {
            cin>>x>>y;
            g[x].eb(y);
            g[y].eb(x);
        }
        bfs(1);
        if(dist[n]==inf)
            o("IMPOSSIBLE\n");
        else
        {
            vi tmp;
            x=n;
            while(x!=-1)
            {
                tmp.eb(x);
                x=par[x];
            }
            reverse(all(tmp));
            o(sz(tmp));nl;
            rep(i,sz(tmp))
                {o(tmp[i]);ns;}nl;
        }
    }
 
    time();
    return 0;
}/*
        cin>>n;
        vi a(n);
        rep(i,n)
            cin>>a[i];
 
    *max_element(a.begin(),a.end())
    *min_element(a.begin(),a.end())
*/
