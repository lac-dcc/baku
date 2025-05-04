#include<iostream>
#include <iomanip>
#include<string>
#include <ios>
#include <utility>
#include <cmath>
using namespace std;
//1000000007
using ll = long long;
ll mod= 1e9 +7;
#include<sstream>
#include<numeric>
#define filein          freopen("input.txt","r",stdin)
#define fileout         freopen("output.txt","w",stdout)
#include<bits/stdc++.h>
/*ll getHash(string key){ll value = 0;ll p = 31;ll p_power = 1;
    for (char ch : key){value += ((ch - 'a' + 1) * p_power) % mod;p_power = (p_power * p) % mod;
    }
    return value;
}*/
#define ya              cout<<"YES\n";
#define no              cout<<"NO\n";
#define pb              push_back
#define fast_cin        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(bi)         bi.begin(),bi.end()
#define printv(bi)      for(ll i=0;i<bi.size();i++)cout<<bi[i]<<" ";cout<<endl;
#define print(x)        printf("%lld\n",x);
#define scc(x)          scanf("%lld",&x);
#define see(x)          cout<<x<<endl;
#define N            300050
#define ff           first
#define ss           second
typedef  pair<ll, ll> pi;
//string str = bitset<number_bits>(any_input).to_string();
ll inf = 1e16;
ll dx[] = { -1, 1, 0, 0, -1, -1, 1, 1};
ll dy[] = {0, 0, 1, -1, -1, 1, 1, -1};
////policy based data structure commonFile.
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>>
using namespace __gnu_pbds;
//->less equal,less,greater as u wish
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update>*/
//iterateinaset for(auto it:s){cout<<it<<endl;}
//for searching a key:
//[auto it=mp.find(x);if(it!=mp.end())]
//for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
//*____________________________*
////*________________________________________________________________________________________
/*bool cmp(pair<ll, ll>& a,
         pair<ll, ll>& b)
{
    return a.ff< b.ff;
}*/
/*bool cmp(pair<ll, ll>& a,
         pair<ll, ll>& b)
{
    if (a.first != b.first)
        return a.first < b.first;
    else
    {
        return a.second > b.second;
    }
}*/
 
//*______________________________*
vector<ll>grp[N];
vector<ll>dis(N),dis1(N);
vector<ll>vis(N);
void bfs(ll source,ll ds)
{
    queue<ll>pq;
    vis[source]=1;
    dis[source]=ds;
    pq.push(source);
    while(!pq.empty())
    {
        ll x=pq.front();
        pq.pop();
        for(auto it:grp[x])
        {
            if(vis[it]==0)
            {
                pq.push(it);
                dis[it]=dis[x]+1;
                vis[it]=1;
            }
        }
 
    }
 
}
 
void bfs1(ll source,ll ds)
{
    queue<ll>pq;
    vis[source]=1;
    dis1[source]=ds;
    pq.push(source);
    while(!pq.empty())
    {
        ll x=pq.front();
        pq.pop();
        for(auto it:grp[x])
        {
            if(vis[it]==0)
            {
                pq.push(it);
                dis1[it]=dis1[x]+1;
                vis[it]=1;
            }
        }
 
    }
 
}
void solve()
{
    ll k,i,j;
    ll n,x,y;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    bfs(1,0);
    /*for(i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }*/
    ll ds=-inf;
   ll nde=-1;
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
        if(dis[i]>ds)
        {
            ds=dis[i];
            nde=i;
        }
        dis[i]=0;
    }
    //cout<<ds<<endl;
    bfs(nde,0);
    ll ans=-1;
    ds=-inf;
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
        if(dis[i]>ds)
        {
            ds=dis[i];
            ans=i;
        }
    }
    bfs1(ans,0);
    for(i=1;i<=n;i++)
    {
        cout<<max(dis[i],dis1[i])<<" ";
    }
 
 
 
 
     
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    int j = 1, i;
    //cin >> t;
    while (t--)
    {
        //cout << "Case " << j++ << ": ";
        solve();
        //cout << endl;
 
    }
}
/*.
.
.
.*/  
//vector<ll>v_prime = seive(100000);
/*vector<ll> seive(ll  n)
{
    //prime array return
    vector<ll>prime;
    for (ll i = 3; i * i <= n; i = i + 2)
    {
        if (isprime[i] == true)
        {
            for (ll j = i * i; j <= n; j += i+i)
            {
                isprime[j] = false;
            }
        }
 
    }
    prime.pb(2);
    for (ll i = 3; i <= n; i += 2)
    {
        if (isprime[i] == true)prime.pb(i);
    }
    return prime;
 
}*/
//.................//
/*vector<pi> prime_factor(ll n)
{
    vector<pi>v;
    for (ll i = 0; i < v_prime.size() && v_prime[i]*v_prime[i] <= n; i++)
    {
        if (n % v_prime[i] == 0)
        {
            ll cnt = 0;
            while (n % v_prime[i] == 0)
            {
                cnt++;
                n /= v_prime[i];
            }
            v.pb({v_prime[i], cnt});
        }
    }
    if (n > 1)
        v.pb({n, 1});
    return v;
}*/
 
//counting the divisors in(O^1/3).(using seeive upto 10^6 for prime).
//vlog theke likha demo
/*ll count_divisor(ll n)
{
    ll ans = 1;
    for (ll i = 0; i < prime.size(); i++)
    {
        ll cnt=1;
        if (prime[i]*prime[i]*prime[i] <= n)
        {
 
            while (n % prime[i] == 0)
            {
                cnt++;
                n = n / prime[i];
            }
        }
        ans=ans*cnt;
    }
    if(isprime[n]==true)ans=ans*2;
    // if it is  squre of any prime  check,age ekta squre array banai niya;
    if(chk)ans=ans*3;
    else if(n!=1)ans=ans*4;
 
}
*/
//ETF:a^b%m=(a^(b%(m-1)))%m;
/*ll bigmod(ll b, ll p, ll mod)
{
    if (p == 0)
        return 1;
    ll ans = bigmod(b, p / 2, mod);
    ans = (ans % mod) % mod * (ans % mod) % mod;
    if (p & 1)
        return (ans * b) % mod;
    else
        return ans % mod;
}*/
/*ll fact[1000005];
ll invers[1000005];
void ncr(ll n)
{
 
 
    fact[0] = fact[1]=invers[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invers[n] = bigmod(fact[n], mod - 2, mod);
    for (ll i = n - 1; i >= 1; i--)
    {
        invers[i] = (invers[i + 1] * (i + 1)) % mod;
    }
    //this will be output
    //(((fact[n] * invers[r]) % mod) * invers[n - r]) % mod;
 
}*/
/* prime fact using log(n) upto 10^7
 int prime[N];
 void seive()
 {
     for(int i=2;i<N;i++)
         prime[i]=i;
     prime[1]=1;
     for(int i=4;i<N;i+=2)
         prime[i]=2;
     for(int i=3;i*i<N;i++)
     {
         if(prime[i]==i)
         {
             for(int j=i*i;j<N;j+=i)
                 prime[j]=i;
         }
     }
 }
 vector<int>prime_fact(int n)
 {
     vector<int>v;
     while(n!=1)
     {
         v.pb(prime[n]);
         n/=prime[n];
     }
     return v;
 }*/
