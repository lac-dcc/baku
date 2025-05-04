// PRAGMAS
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
// #pragma GCC optimize("unroll-loops")
 
// INCLUDES
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
 
// DEFINES
#define int               long long
#define mp                make_pair
#define pb                push_back
#define eb                emplace_back
#define ins               insert
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define inparr(x,n)       for(int _i = 0; _i < (n); ++_i)cin>>(x)[_i];
#define popcnt            __builtin_popcountll
#define elasped_time      1.0 * clock() / CLOCKS_PER_SEC 
 
// TYPEDEFS
using ll = long long;
using str = string;
using pii = pair<int,int>;
using vi = vector<int>;
using vii = vector<pii>;
using vvi = vector<vi>;
template<class T> using vec = vector<T>;
 
// I/O
void setPrec(int prec) { cout << fixed << setprecision(prec); }
void unsyncIO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
 
// INPUT
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
 
template<class T, class U> void read(pair<T,U>& p);
template<class T> void read(vector<T>& v);
 
template<class T> void read(T& x) { cin >> x; }
void read(double& d) { str t; read(t); d = stod(t); }
void read(long double& d) { str t; read(t); d = stold(t); }
template<class T, class ...U> void read(T& t, U&... u) { read(t); read(u...); }
template<class T, class U> void read(pair<T,U>& p) { read(p.fr,p.sc); }
template<class T> void read(vector<T>& x) { for(auto &z: x) read(z); }
template<class T> void readn(vector<T>& x, int n) { x.resize(n); for(auto &z: x) read(z); }
 
// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
    #ifdef LOCAL
        return b ? "true" : "false"; 
    #else 
        return ts((int)b);
    #endif
}
 
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; for(int i = 0; i < SZ; ++i) res += char('0'+b[i]); return res; }
template<class T, class U> str ts(pair<T,U> p);
template<class T> str ts(T v) { // containers with begin(), end()
    #ifdef LOCAL
        bool fst = 1; str res = "{";
        for (const auto& x: v) {
            if (!fst) res += ", ";
            fst = 0; res += ts(x);
        }
        res += "}"; return res;
    #else
        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += " ";
            fst = 0; res += ts(x);
        }
        return res;
    #endif
}
 
template<class T, class U> str ts(pair<T,U> p) {
    #ifdef LOCAL
        return "("+ts(p.fr)+", "+ts(p.sc)+")"; 
    #else
        return ts(p.fr)+" "+ts(p.sc);
    #endif
}
 
// OUTPUT
template<class T> void pr(T x) { cout << ts(x); }
template<class T, class ...U> void pr(const T& t, const U&... u) { pr(t); pr(u...); }
void write() { pr("\n"); } // print w/ spaces
template<class T, class ...U> void write(const T& t, const U&... u) { 
    pr(t); if (sizeof...(u)) pr(" "); write(u...); }
 
// DEBUG
void DBG() { cerr << "]" << endl; }
template<class T,class ...U> void DBG(const T& t, const U&... u) {
    cerr << ts(t); if (sizeof...(u)) cerr << ", ";
    DBG(u...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
    #define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
    #define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
         << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
    #define dbg(...) 0
    #define chk(...) 0
#endif
 
// MISC
template<class T> int lwb(vector<T>& a, const T& b) { return lower_bound(all(a),b)-(a).begin(); }
template<class T> void uniq(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)),v.end()); }
 
// template<typename T>
// using oset = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
 
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const long long inf = 2e18;
const int hell = 1e9+7; // 998244353;
const long double PI = acos((long double)-1);
const int maxn = 1000006;
void solve(){
    int n, k;
    read(n, k);
    vi p(k);
    read(p);
    int ans = 0;
    for (int i = 1; i < 1<<k; ++i) {
        int prod = 1;
        for (int j = 0; j < k; ++j) {
            if (i & (1 << j)) {
                if (prod < inf / p[j]) {
                    prod *= p[j];
                } else prod = inf;
            }
        }
        if (popcnt(i) % 2) {
            ans += n / prod; 
        }else {
            ans -= n / prod;
        }
    }
    write(ans);
}
 
signed main(){
    unsyncIO();
    // setPrec(9);
    // setIn("input.txt");
    // setOut("output.txt");
    int cases=1;
    //cin>>cases;
    for (int i = 1; i <= cases; ++i) {
        solve();
    }
    #ifdef LOCAL
        cerr<<endl<<"Time Elasped : "<<elasped_time<<endl;
     #endif
    return 0;
}