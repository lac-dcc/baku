using namespace std;
#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using db = double;
using str = string; 
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
 
#define srt(v) sort(v.begin(),v.end())
#define printv(a) printa(a,0,a.size())
#define debug(x) cout<<#x" = "<<(x)<<endl
#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?"\n":" ")
#define printv(a) printa(a,0,a.size())
#define print2d(a,r,c) for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?"\n":" ")
 
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
tcT> using PR = pair<T,T>;
 
// pairs
#define mp make_pair
#define f first
#define s second
 
// vectors
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
 
#define lb lower_bound
#define ub upper_bound
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
 
// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FR(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define PRE(i,m,n,in) for(int (i)=(m);(i)<(n);i+=in)
#define RPRE(i,m,n,in) for(int (i)=(m);(i)>=(n);i-=in)
#define trav(a,x) for (auto& a: x)
 
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); //
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
 
// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); 	
  return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x))
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }
 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
 
tcT> bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0; }
 
tcTU> T fstTrue(T lo, T hi, U f) {
  hi ++; assert(lo <= hi); // assuming f is increasing
  while (lo < hi) { // find first index such that f is true
    T mid = lo+(hi-lo)/2;
    f(mid) ? hi = mid : lo = mid+1;
  }
  return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
  lo --; assert(lo <= hi); // assuming f is decreasing
  while (lo < hi) { // find first index such that f is true
    T mid = lo+(hi-lo+1)/2;
    f(mid) ? lo = mid : hi = mid-1;
  }
  return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
  sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
  auto it = t.find(u); assert(it != end(t));
  t.erase(it); } // element that doesn't exist from (multi)set
 
// INPUT
#define tcTUU tcT, class ...U
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(V<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);
 
tcT> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }
 
tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(V<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { trav(a,x) re(a); }
tcT> void rv(int n, V<T>& x) { x.rsz(n); re(x); }
 
int R, C;
vector <string> grid;
int ans = 0;
 
void floodfill(int r, int c, char c1, char c2) {
  if(r < 0 || r >= R || c < 0 || c >= C) return; // outside of the grid
  if(grid[r][c] != c1) return; 
  grid[r][c] = c2; 
  for(int d = 0; d < 4; d++)
    floodfill(r + dx[d], c + dy[d], c1, c2);
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> R >> C; grid.resize(R);
  FR(i, R) cin >> grid[i];
  FR(i, R) 
    FR(j, C) {
      if(grid[i][j] == '.') {
        floodfill(i, j, '.', 'x');
        ans++;
      }
    }
  cout << ans << endl;
  
}
