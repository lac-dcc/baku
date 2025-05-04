// GODFATHER ~ stanlee
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define stanlee ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define lld long double 
#define setbits(x) __builtin_popcountll(x)
#define pb push_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
 
const lld pi= 3.141592653589793238;
const ll INF= LONG_LONG_MAX;
const ll mod=1e9+7;
 
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,x,y) for(int i=x; i<y; i++) 
#define fr(i,m,n) for(int i=n;i>=m;i--)
#define cy cout<<"YES\n";
#define cm cout<<"-1\n";
#define cn cout<<"NO\n";
#define vr(v) v.begin(),v.end()
#define rv(v) v.end(),v.begin()
 
template<typename T1, typename T2> 
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> 
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
 
 
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
void printarr(ll arr[], ll n){rep(i,0,n) cout << arr[i] << " ";cout << "\n";}
template<typename T>
void printvec(vector<T>v){ll n=v.size();rep(i,0,n)cout<<v[i]<<" ";cout<<"\n";}
template<typename T>
ll sumvec(vector<T>v){ll n=v.size();ll s=0;rep(i,0,n)s+=v[i];return s;}
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}//lcm
 
//Code 
void dfs(int node, vector<int>adj[],int parent,vector<int>&subtree)
{
    for(int  x : adj[node])
    {
        if(x!=parent)
        {
          dfs(x,adj,node,subtree);
          subtree[node]+=subtree[x];
        }
    }
    subtree[node]++;
}
void solve()
{ 
   ll n;
   cin>>n; 
   vector<int>adj[n];
   for(int i=1;i<n;i++)
   {
    int x ;cin>>x;
    x--;
     adj[i].push_back(x);
     adj[x].push_back(i);
   }
   vector<int>subtree(n,0);
   dfs(0,adj,-1,subtree);
   for(auto it:subtree)
   {
    cout<<--it<<" ";
   }
   cout<<endl;
}
 
int32_t main()
{
    stanlee;
    ll t=1;
    //cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;
}
