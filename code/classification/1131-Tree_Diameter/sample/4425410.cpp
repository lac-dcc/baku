#include <bits/stdc++.h>
 
// #include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
// using namespace __gnu_pbds;
 
 
 
void __print(int dps) {cerr << dps;}
void __print(long dps) {cerr << dps;}
void __print(long long dps) {cerr << dps;}
void __print(unsigned dps) {cerr << dps;}
void __print(unsigned long dps) {cerr << dps;}
void __print(unsigned long long dps) {cerr << dps;}
void __print(float dps) {cerr << dps;}
void __print(double dps) {cerr << dps;}
void __print(long double dps) {cerr << dps;}
void __print(char dps) {cerr << '\'' << dps << '\'';}
void __print(const char *dps) {cerr << '\"' << dps << '\"';}
void __print(const string &dps) {cerr << '\"' << dps << '\"';}
void __print(bool dps) {cerr << (dps ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &dps) {cerr << '{'; __print(dps.first); cerr << ','; __print(dps.second); cerr << '}';}
template<typename T>
void __print(const T &dps) {int f = 0; cerr << '{'; for (auto &jx: dps) cerr << (f++ ? "," : ""), __print(jx); cerr << "}";}
void _print() {cerr << "]\neg";}
template <typename T, typename... V>
void _print(T by2, V... v) {__print(by2); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(dps...) cerr << "[" << #dps << "] = ["; _print(dps)
#else
#define debug(dps...)
#endif
 
#define ll long long
#define lli long long int
#define __
#define pll pair<ll, ll>
#define pii pair<int, int>
#define pdd pair<double, double>
#define v vector 
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define rep(jx, ft, yo) for (ll jx = ft; jx < yo; jx++)
#define nrep(jx, ft, yo) for (ll jx = ft; jx >= yo; jx--)
#define rloop(i, arr, b) for (ll i = (b); i > arr; --i)
#define sortv(v) sort(v.begin(), v.end())
#define rev(a2) reverse(a2.begin(), a2.end())
#define forp(jx, ft, yo) for (ll jx = ft; jx <= yo; jx++)
#define forq(jx, ft, yo) for (ll jx = ft; jx >= yo; jx--)
#define fe first
#define se second
#define all(dps) dps.begin(), dps.end()
#define umv unordered_map<ll,set<ll>>
#define mv map<ll,v<ll>>
 
#define us unordered_set<ll>
#define pi acos(-1.0)
#define ln endl
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(dps)             (int)((dps).size())
#define ub(v, val) upper_bound(v.begin(), v.end(), val)
#define lb(v, val) lower_bound(v.begin(), v.end(), val)
#define inf 1000000000000000005
void input(vl &v){forp(ix,0,v.size()-1) cin>>v[ix];}
void output(vl &v){ for(auto it:v) cout<<it << " "; cout<<ln;}
 
ll dx4[4]={-1,0,1,0};
ll dy4[4]={0,1,0,-1};
ll dx2[4]={-2,2,2,-2};
ll dy2[4]={-1,-1,1,1};
ll dx8[8]={-1,-1,0,1,1,1,0,-1};
ll dy8[8]={0,1,1,1,0,-1,-1,-1};
 
 
// *** dijktra ******
// vl arr2(num+1,LLONG_MAX);
// arr2[1]=0;
// priority_queue<pll,vector<pll>,greater<pll>> pq;
// pq.push({0,1});
// while(pq.size()>0)
// {
//     pll x = pq.top();
//     ll dis = x.fe;
//     ll right = x.se;
//     pq.pop();
 
//     if(dis>arr2[right])
//     {
//         continue;
//     }
 
//     for(auto it:mp[right])
//     {
//         if(dis+it.se<arr2[it.fe])
//         {
//             arr2[it.fe] = dis + it.se;
//             pq.push({arr2[it.fe],it.fe});
//         }
//     }
// }
//********************
 
 
// ****** Floyd-Warshall ******
 // vll arr2(num+1,vl(num+1,inf));
 //    forp(i,0,m-1)
 //    {
 //        ll arr1,b,c;
 //        cin >> arr1 >> b >> c;
 //        arr2[arr1][b]=min(arr2[arr1][b],c);
 //        arr2[b][arr1]=min(arr2[b][arr1],c);
 //    }
 
 //    forp(i,0,num) arr2[i][i] = 0;
 
 //    forp(k,1,num)
 //    {
 //        forp(i,1,num)
 //        {
 //            forp(j,1,num)
 //            {
 //                if(arr2[i][k]!=inf && arr2[k][j]!=inf)
 //                {
 //                arr2[i][j] = min(arr2[i][j],arr2[i][k] + arr2[k][j]);
 //                }
 //            }
 //        }
 //    }
// *****************************
 
 
// **************** Bellman-Ford *********
//     ll num,m;
//     cin >> num >> m;
//     vector<vector<ll>> mp;
//     forp(i,0,m-1)
//     {
//         ll arr1,b,c;
//         cin >> arr1 >> b >> c;
//         mp.push_back({arr1,b,-1*c});
//     }
//     vl arr2(num+1,inf);
//     arr2[1]=0;
//     for(int i=1;i<num;i++)
//     {
//         for(auto it:mp)
//         {
//             ll s = it[0];
//             ll e = it[1];
//             ll d = it[2];
//             if(arr2[s]==inf) continue;
//             arr2[e] = min(arr2[e],d + arr2[s]);
//             arr2[e] = max(arr2[e],-1LL*inf);
//         }
//     }
//     debug(arr2);
//     for(int i=1;i<num;i++)
//     {
//         for(auto it:mp)
//         {
//             ll s = it[0];
//             ll e = it[1];
//             ll d = it[2];
//             if(arr2[s]==inf) continue;
//             if(arr2[e] > (d + arr2[s]))
//                 arr2[e] = -1*inf;
//             arr2[e] = max(arr2[e],-1LL*inf);
//         }
//     }
// ****************************************
 
bool isprime(ll num)
{
    // Corner cases
    if (num <= 1)
        return true;
    if (num <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (num % 2 == 0 || num % 3 == 0)
        return false;
  
    for (int j = 5; j * j <= num; j = j + 6)
        if (num % j == 0 || num % (j + 2) == 0)
            return false;
  
    return true;
}
 
ll mod =  1e9+7;
long long gcd(long long ft, long long yo)
{
  if (yo == 0)
    return ft;
  return gcd(yo, ft%yo);
}
 
 
long long lcm(ll ft, ll yo)
{
    return (ft / gcd(ft, yo)) * yo;
}
 
ll binpow (ll num, ll k) {
    if (k == 0)
        return (1 % mod);
    if (k % 2 == 1)
        return (binpow (num, k - 1) * num) % mod;
    else {
        ll bb = binpow (num, k / 2);
        return (bb * bb) % mod;
    }
}
 
 
ll inv(ll num){
    return binpow(num, mod - 2);
}
 
 
// const int N = 1e5+5;
// int primes[N];
// vector<ll> pr;
// void seive()
// {
//     for(int j=2;j<N;j++)
//     {
//         if(primes[j]==0)
//         {
//             pr.pb(j);
//             for(int j=j*j;j<N;j+=j)
//             {
//                 primes[j]=1;
//             }
//         }
//         primes[j]= (primes[j]^1);
//     }
// }
 
ll modFact(ll num)
{
    if (num >= mod)
        return 0;
 
    ll tempult = 1;
    for (int j = 1; j <= num; j++)
        tempult = (tempult * j) % mod;
 
    return tempult;
}
 
 
const int N = 2e5 + 5;
ll rk[N], a2[N];
 
int getP(int ft){
    return (ft == a2[ft] ? ft : a2[ft] = getP(a2[ft]));
}
 
void unite(int ft, int yo){
    ft = getP(ft), yo = getP(yo);
    if (ft == yo) return;
    if (rk[ft] < rk[yo]) swap(ft, yo);
    a2[yo] = ft;
    rk[ft] += rk[yo];
}
 
ll yo(ll n,ll x)
{
    ll a = x,co=0;
    while(n>0)
    {
        co +=n/a;
        n/=a;
    }
    return co;
}
 
pll dfs(ll r,map<ll,vl> &mp,ll p)
{
    debug(r);
    vector<ll> a;
    ll ma = 0;
    for(auto it:mp[r])
    {
        if(it!=p)
        {
            debug(it);
            pll x = dfs(it,mp,r);
            a.pb(x.fe);
            ma=max(ma,x.se);
        }
    }
    debug(a);
    if(a.size()==0)
    {
        return {0,0};
    }
    if(a.size()==1)
    {
        ma=max(ma,a[0]+1);
        return {a[0]+1,ma};
    }
    else
    {
        sortv(a);
        ma=max(ma,2+a[a.size()-2]+a[a.size()-1]);
        return {a[a.size()-1]+1,ma};
    }
}
 
 
 
 
void solve(){
   ll n;
   cin >> n;
   map<ll,vl> mp;
   forp(i,0,n-2)
   {
    ll a,b;
    cin >> a >> b;
    mp[a].pb(b);
    mp[b].pb(a);
   }
   cout << dfs(1,mp,-1).se << ln;
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","right",stdin);
        freopen("output.txt","w",stdout);
        freopen("Error.txt","w",stderr);
    #endif
    ll tc = 1;
   // cin >> tc;
    for (ll z = 1;z<=tc;z++)
    {
        solve();
    }   
}
 
