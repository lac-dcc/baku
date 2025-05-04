//INCLUDES--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <ctime>
//OPTIMIZATIONS????-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//DEFINES--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define ll long long
#define ld long double
#define pb push_back
#define endl '\n'
#define SZ(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define make_unique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin());
#define lastEle(vec) vec[vec.size()-1] 
#define ll long long 
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
//#define PI 3.1415926535897932384626
//ORDERED_SET--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
using namespace std;
 using namespace __gnu_pbds;
 template <typename T>
 using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//DEBUG--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define deb(args...) { error(args); cout << flush;}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << " [" << *it <<  ": " << a << "] " << flush;
    err(++it, args...);
}
//FAST HASHING-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
}; 
// unordered_map<long long, int, custom_hash> safe_map;
// unordered_set<long long, custom_hash> safe_set;
//HELPER FUNCTIONS----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
// reads vector
template <typename T>
void scanVec(vector< T > & vec){for(int i = 0;i < SZ(vec);i++) cin >> vec[i];}
 
// prints vector
template <typename T>
void printVec(vector< T > & vec){for(int i = 0;i < SZ(vec);i++){cout << vec[i] << " ";}cout << endl;}
 
//calculates mod
template <typename T>
T mod(T a,T b){return ((a%b) + b)%b;}
 
//swaps value between two variables
//template <typename T>
//void swap(T & a, T & b){T temp = a;a = b;b = temp;}
 
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
 
// in (r,l) 
template <typename T>
bool IN(T i, T l, T r) {return (l<i&&i<r);}
// in [r,l]
template <typename T>
bool LINR(T i, T l, T r) {return (l<=i&&i<=r);}
 
// in [l,r)
template <typename T>
bool LIN(T i, T l, T r) {return (l<=i&&i<r);}
 
// in (l,r]
template <typename T>
bool INR(T i, T l, T r) {return (l<i&&i<=r);}
 
//prints NO
void no(){cout <<"NO" << endl;}
 
//prints YES
void yes(){cout <<"YES" << endl;}
 
//HELPER_VARIABLES----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int inf = 1001001001;
ll INF = 1e17;
const ll MOD = 1e9 + 7; 
const ll md = 998244353;
vector< int > dx = {0,0,1,-1};
vector< int > dy = {-1,1,0,0};
vector< char > dd = {'U','D','R','L'};
// check constraints !!!
const int MAXN = 1e5 + 10;
 
void sl(){
  int n,k; cin >> n >> k;
  vector< pair< int , int > > arr (n);
  for(int i = 0;i < n;i++){
      int a,b; cin >> a >> b;
      arr[i] = {b,a};
  }
  sort(all(arr));
  int ans = 0;
  multiset< int > getsFree;
  for(int i = 0;i < k;i++){
      getsFree.insert(0);
  }
  for(int i = 0;i < n;i++){
      int start = arr[i].second;
      int end = arr[i].first;
      auto posFree = getsFree.lower_bound(start + 1);
      if(posFree == getsFree.begin()) continue;
      --posFree;
      int time = *posFree;
      if(time <= start){
        getsFree.erase(posFree);
        getsFree.insert(end);
        ans++;
      }
  }
   cout << ans << endl;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //srand(time(NULL));
    // 1 - multiple tests
    // 0 - single test
 
    int ts = 0;
    if(ts == 1) cin >> ts;
    else ts = 1;
    while(ts--) sl(); 
    return 0;
} 
