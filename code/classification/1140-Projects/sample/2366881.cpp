/****************************************** By Lord Sanskar Bhargava******************************/
 
 
#include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
 
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define all(v) (v).begin(),(v).end()
#define dll(v) (v).rbegin(),(v).rend()
#define set1(x) __builtin_popcount(x)
#define gcd(a,b) __gcd(a,b)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define bk(i,a,b) for(ll i=a;i>=b;i--)
#define ff first
#define ss second
#define sz(x) ((ll) (x).size())
#define mid(l,r) (l+(r-l)/2)
#define inf 1e18
const int mod = 1000000007;
 
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
 
unsigned mod_pow(unsigned a, unsigned b, unsigned mod) 
{
    unsigned result = 1;
 
    while (b > 0) {
        if (b & 1)
            result = unsigned(uint64_t(result) * a % mod);
 
        a = unsigned(uint64_t(a) * a % mod);
        b >>= 1;
    }
 
    return result;
}
ll read(){
    ll i;
    cin>>i;
    return i;
}
vl readvl(ll n,ll off=0){
    vl v(n);
    rep(i,0,n)v[i]=read()+off;
    return v;
}
string readString(){
    string s;
    cin>>s;
    return s;
}
 
template<class T>
T sq(const T& t){
    return t*t;
}
void run_test()
{
  int n;
  cin >> n;
  map<int,int> compress;
  vector<int> a(n),b(n),p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> p[i];
    b[i]++;
    compress[a[i]], compress[b[i]];
  }
 
  int coords = 0;
  for (auto&v : compress) {
    v.second = coords++;
  }
 
  vector<vector<pair<int,int>>> project(coords);
  for (int i = 0; i < n; i++) {
    project[ compress[b[i]] ].emplace_back( compress[a[i]], p[i] );
  }
 
  vector<long long> dp(coords, 0);
  for (int i = 0; i < coords; i++) {
    if (i > 0) {
      dp[i] = dp[i-1];
    }
    for (auto p : project[i]) {
      dp[i] = max(dp[i], dp[p.first]+p.second);
    }
  }
  cout << dp[coords-1] << endl;
}
int main(int argc, char const *argv[]) 
{
    clock_t begin = clock();
    fastio;
    int tt=1;
    // cin>>tt;
    while(tt--)
    {
        run_test();
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
return 0;
}