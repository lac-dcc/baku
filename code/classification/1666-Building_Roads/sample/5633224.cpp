#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef long long int ll;
 
//using namespace __gnu_pbds;
//template <typename T> using ordered_set = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// ordered_set ->  find_by_order(x)<itr, x being 0-indexed>; order_of_key(x)<count, strictly less>
#define fast ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
//#define endl "\n"
#define ii pair<ll,ll>
#define ic pair<char,ll>
#define pb push_back
#define vi vector<ll>
#define popb pop_back
#define all(v) (v).begin(), (v).end()
#define F first
#define S second
#define pi 3.14159265358979323846264338
 
const int N=1e5+10;
ll M= 998244353;
long long binpow(long long a, long long b) {
    a %= M;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
ll fac[N+10];
void factorial(){
    fac[0]=1;
    ll fcto=1;
    for(int i=1;i<=N;i++)
    {
        fcto*=i;
        fcto%=M;
        fac[i]=fcto;
    }
}
ll inv_fac(ll x);
ll binexp(ll a, ll b);
ll ncr(ll n, ll r);
 
ll inv_fac(ll x){
    return binexp(fac[x],M-2);
}
ll binexp(ll a, ll b){
    if(a==0||a==1){return a;}
    if(b==0){return 1;}
    ll ret = binexp(a, b/2);
    if(b%2) return (((ret*ret)%M)*a)%M;
    else return (ret*ret)%M;
}
ll ncr(ll n, ll r){
    return ((fac[n]*inv_fac(n-r)%M)*inv_fac(r))%M;
}
 
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
  //suppose n=7 that is prime and its pair are (1,7)
  //so if a no. is prime then it can be check by numbers smaller than square root
  // of the n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
vector<int>adj[N];
map<int,int>mp;
void dfs(int i)
{
    if(mp.find(i)!=mp.end()){return;}
    mp[i]++;
    for(auto u:adj[i])
    {
        dfs(u);
    }
}
int main()
{
    fast;
    ll tt=1,i,j,num;
    // cin>>tt;
    
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        ll cnt=0;
        vector<int>comp;
        for(i=1;i<=n;i++)
        {
            if(mp.find(i)!=mp.end()){continue;}
            dfs(i);
            comp.pb(i);
        }
 
        cout<<comp.size()-1<<"\n";
        for(i=1;i<comp.size();i++)
        {
            cout<<comp[0]<<" "<<comp[i]<<"\n";
        }
    }
}
