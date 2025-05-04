#pragma GCC optimize("Ofast")
//#pragma GCC target("fma")
#include <bits/stdc++.h>
using namespace std;
//---------------------------------//
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
//------------------------------//
 
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
 
#define  ff           first
#define  ss           second
#define  pb           push_back
#define  IOS          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  all(x)       (x).begin(), (x).end()
#define  ps(x,y)      fixed<<setprecision(y)<<x
#define  rep(i,a,b)   for(ll i=a ; i<b ; ++i)
 
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll maxn = 1e6 + 4;
 
ll get_product(ll prod, ll num, ll n, bool type){
  if(prod == INT64_MAX)
    return prod;
  if(prod > (n/num)){
    return INT64_MAX;
  }
  return num*prod;
}
 
void solve(){
  ll n,k;
  cin >> n >> k;
  vll v(k);
  for(int i=0;i<k;i++){
    cin >> v[i];
  }
  ll count = 0;
  ll prod = 1;
  for(int i = 1;i < (1<<k);i++){
    prod = 1;
    bool type = __builtin_popcount(i)%2;
    for(int j=0;j<k;j++){
      if(i & (1<<j)){
        prod = get_product(prod,v[j],n,type);
      }
    }
    if(prod == INT64_MAX) continue;
    else count += (type?((n/prod)):(-n/prod));
  }
  cout << count;
}
 
int main(){
  IOS
  	solve();
  //cerr <<endl <<"[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
}
 
// integer overflow
// var vs loop var
