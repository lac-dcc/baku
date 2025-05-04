#include <bits/stdc++.h> 
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define veci vector<int>
#define ff first
#define ss second
#define vecl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define em emplace_back
#define IN(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define all(c) (c).begin(), (c).end()
const ll mod = 1000000007;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0)
{if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll modinv(ll a, ll b) {return expo(a, b - 2, b);}
ll modadd(ll a, ll b, ll m) { return ( a % m + b % m) % m;}
ll modmul(ll a, ll b, ll m) { return ( a % m * b % m) % m;}
ll modsub(ll a, ll b, ll m) { return ((a%m - b%m)+ m) % m;}
ll moddiv(ll a, ll b, ll m) { return modmul(a, modinv(b, m), m) % m ;}
bool com(pll a,pll b){return a.ff<b.ff;}
void solve(){
  ll n;
  cin>>n;
  vpll a(n);
  for(auto &i:a){
    cin>>i.ff>>i.ss;
  }
  vpll event(2*n);
  for(int i=0;i<2*n;i+=2){
    event[i]=mp(a[i/2].ff,1);
    event[i+1]=mp(a[i/2].ss,0);
  }
  sort(all(event),com);
  ll ans=0,temp=0;
  for(auto it:event){
    if(it.ss==1) temp++;
    else temp--;
 
    ans=max(ans,temp); 
  }
 
cout<<ans<<endl;
 
  
}
 
int main(){
 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
 
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   freopen("Error.txt", "w", stderr);
   #endif
 
 
   
      solve();
   
 
   return 0;
}
