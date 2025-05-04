#include<bits/stdc++.h>
 
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
 
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             1e18
#define sz(v)       ((int)v.size())
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define loop(i,k,n)   for(i=k; i<n; i++)
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)    (a*b)/__gcd(a,b) 
#define msb(n)      __builtin_clz(n)
#define fastio() ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef vector<int>     vi;
typedef pair<ll, ll>  pl;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
typedef vector<string> vs;
const ll mod = 1e9 + 7;
 
 
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
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
 
ll power(ll x, ll y) 
 { 
     ll val = 1;
 
     while (y > 0)
     { 
         // If y is odd then multiply x with val
         if (y % 2 != 0) 
             val = ((val) * (x)); 
         y = y / 2; 
         x = ((x) * (x));
     } 
     return val; 
 }
 int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}
void PrimeFactors(int n) {
  mii m;
   while (n%2 == 0){
      m[2]++;
      n = n/2;
   }
   for (int i = 3; i <= sqrt(n); i = i+2){
      while (n%i == 0){
         m[i]++;
         n = n/i;
      }
   }
   if (n > 2)
   m[n]++;
}
ll len(ll x){
    int ans=0;
    while(x!=0){
        x/=10;
        ans++;
    }
    return ans;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
  fastio();
  //code goes here
  int n,x;cin>>n>>x;
  vi v(n);
  int i;
  loop(i,0,n) cin>>v[i];
  map<int,pii> m;int j;
  loop(i,0,n){
    loop(j,i+1,n){
        if(m.count(x-v[i]-v[j])>0){
            cout<<i+1<<" "<<j+1<<" "<<m[x-v[j]-v[i]].ff<<" "<<m[x-v[j]-v[i]].ss;
            return 0;
        }
    }
    loop(j,0,i){
        m[v[j]+v[i]]={i+1,j+1};
    }
  }
  cout<<"IMPOSSIBLE";
  return 0;
}