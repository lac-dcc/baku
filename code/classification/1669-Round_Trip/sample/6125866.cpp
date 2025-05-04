#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long int;
using ld = long double;
#define pb                    push_back
#define ff                    first
#define ss                    second
#define len(a)                (ll)(a).size()
#define all(x)                x.begin(),x.end()
#define uniq(x)               x.resize(distance(x.begin(),unique(all(x))))
#define rep(i,l,r)            for(int i = l; i < r; i++)
#define repi(n)               rep(i,0,n)
#define repj(n)               rep(j,0,n)
#define rrep(i,r,l)            for(int i = r; i >= l; i--)
#define el                    "\n"
#define yes               cout<<"YES"<<el;
#define no               cout<<"NO"<<el;
 
const int P = int(1e9+7); 
const int N = int(1e6+5);
const ll INF = ll(1e18);
 
const ld PI = 3.14159265359;
const ld E = 2.718281828459045;
const ld EPS = ld(5e-8);
 
inline void setIO(string fi = "" , string fo = "") {ios_base::sync_with_stdio(0); cin.tie(0);  if (!fi.empty()) { freopen(fi.c_str(), "r", stdin); freopen(fo.c_str(), "w", stdout);}}
 
/*****************************************************************************************************************************************/
#ifdef RMN // compile with -DRMN
#include "dbg.h"
#else
#define dbg(...);
#endif
/*****************************************************************************************************************************************/
 
mt19937 rng (high_resolution_clock::now().time_since_epoch().count());
template<typename T1, typename T2> static inline void amin(T1 &a, T2 b) { if (b < a) a = b; }
template<typename T1, typename T2> static inline void amax(T1 &a, T2 b) { if (a < b) a = b; }
template <typename T>                 istream& operator>> (istream& cin, vector<T> &x) {for (int i = 0; i < x.size() - 1; i++) cin >> x[i]; return cin >> x[x.size() - 1];}
template <typename T1, typename T2>     istream& operator>> (istream& cin, pair<T1, T2> &p) {cin >> p.first; return cin >> p.second;}
/*****************************************************************************************************************************************/
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
// the comparator determines whether object a belongs to the left of object b in a sorted ordering.
bool sortbysec(const pair<ll, ll>& a, const pair<ll, ll>& b ) {return a.second < b.second;}
/*****************************************************************************************************************************************/
 
/*****************************************************************************************************************************************/
void rmn()
{
    // DONT CODE WITHOUT FULL SOLUTION
    // cycle finding using dfs, can be done using bfs as well
 
    ll n , m; cin>>n>>m;
 
    vector<vector<ll>> adj(n);
    repi(m) {
        ll u , v; cin>>u>>v; 
        u -- , v --;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
 
 
    vector<ll> col(n, 0);
    vector<ll> par(n, -1);
    vector<ll> cycle_path;
 
    auto dfs = [&](auto &&dfs, ll v) -> bool {
        col[v] = 1;
        bool cyclePresent = 0;
 
        for(auto to : adj[v]) {
            if(to == par[v]) continue;
 
            if(!col[to]) {
                par[to] = v;
                cyclePresent |= dfs(dfs,to);
                if(cyclePresent) break;
            }
            else if(col[to] == 1) { 
 
                // process cycle
                cycle_path.pb(to);
                ll temp = v;
                while(temp != to) {
                    cycle_path.pb(temp);
                    temp = par[temp];
                }
                cycle_path.pb(to);
                reverse(all(cycle_path));
                return true;
            } 
 
        }
        col[v] = 2;
        return cyclePresent;
    };
 
 
    par[0] = -1;
    repi(n){
        if(!col[i])  {
            if(dfs(dfs, i)) {
                cout<<len(cycle_path) <<endl;
                for(auto x : cycle_path) cout<<x + 1<< " ";
                cout<<endl;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
 
}
/*****************************************************************************************************************************************/
int main()
{
    setIO("", "");    //inputFile and outputFile
    auto start1 = high_resolution_clock::now();
    int TOTAL = 1;
    // cin >> TOTAL;
    for (int CURRENT = 0; CURRENT < TOTAL; CURRENT++) {
        // cout<<"Case #"<<CURRENT + 1<<": ";        //googleContests
        rmn();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    // cerr << "Time: " << duration.count() / 1000 << endl;
 
    return 0;
}
