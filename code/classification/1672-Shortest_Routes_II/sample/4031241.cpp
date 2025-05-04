#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using namespace chrono;
 
#define int long long
#define endn '\n'
#define Ff(i,a,b) for(i=a;i<b;i++)
#define Fb(i,a,b) for(i=a-1;i>=b;i--)
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ff first
#define ss second
#define maxel max_element
#define minel min_element
#define upb upper_bound
#define lob lower_bound
#define PI 2*asin(1)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define trav(x) for(auto& i:x)
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define spc ' '
#define nO {cout<<"NO\n"; return;}
#define yES {cout<<"YES\n"; return;}
#define zERO {cout<<0<<endl; return;}
#define oNE {cout<<-1<<endl; return;}
#define inf ((int)1e18+1)
#define ninf ((int)1e18*(-1)-1)
#define mem0(x) memset(x,0,sizeof x)
#define mem1(x) memset(x,-1,sizeof x)
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef map<int, int> mi;
typedef map<long long, long long> mll;
typedef unordered_map<int, int> umi;
typedef unordered_map<long long, long long> umll;
typedef set<int> si;
typedef set<long long> sll;
typedef unordered_set<int> usi;
typedef unordered_set<long long> usll;
typedef tuple<int, int, int> tpi;
 
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 
template <class T> void show(vector<vector<T>> &a) {for (auto &i : a) { for (T &j : i) cout << j << ' ' ; cout << endl; } }
template <class T> void show(vector<T> &a) {for (T i : a) cout << i << ' ' ; cout << endl; }
template <class T> void show(vector<pair<T, T>>&a) {trav(a) {cout << i.ff << ' ' << i.ss << endl;}}
template <class T> void show(pair<T, T>p) {cout << p.ff << ' ' << p.ss << endl;}
void show(vector<string>&a) {trav(a) cout << i << endl;}
template<class T> void take(vector<T>&a) {trav(a) cin >> i;}
int digits(int n) {int k = 0; while (n) k++, n /= 10; return k;}
bool isprime(int n) {int i; if (n == 1) return 0; if (n == 2) return 1; if (n % 2 == 0) return 0; for (i = 3; i * i <= n; i += 2) {if (n % i == 0) return 0;} return 1;}
ll power(ll x, ll y, ll MOD) {ll ans = 1; x %= MOD; while (y > 0) { if (y % 2 == 1) ans = (ans * x) % MOD; y /= 2; x = (x * x) % MOD;}  return ans;}
void sieve(vb &a, int n) {int i, j; a[1] = 0; a[0] = 0; int h = sqrt(n + 1); Ff(i, 2, h) {if (!a[i])continue; for (j = 2 * i; j < n + 1; j += i)a[j] = 0;}}
void load(umi&g) {g.max_load_factor(0.25);}
vi bits(int n) {vi a; int i; Ff(i, 0, 33) {a.pb(n % 2); n /= 2;} reverse(all(a)); return a;}
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
void sub() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
#endif
}
 
const ll N = 1e9 + 7;
const ll M = 998244353;
 
/*
 
 
*/
/*.........................................................................................................................................................................*/
 
// vector<int>z;
int tt;
 
 
void solve() {
    int i, j, k, n, m;
    int q;
    cin >> n >> m >> q;
    vector<vector<pii>>v(n + 1);
    vector<vi>dis(n + 1, vector<int>(n + 1, 1e18));
    Ff(i, 0, m) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].pb({y, z});
        v[y].pb({x, z});
        dis[x][y] = dis[y][x] = min(dis[x][y], z);
    }
    Ff(i, 1, n + 1) dis[i][i] = 0;
    Ff(k, 1, n + 1) {
        Ff(i, 1, n + 1) {
            Ff(j, 1, n + 1) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while (q--) {
        cin >> i >> j;
        cout << (dis[i][j] == 1e18 ? -1 : dis[i][j]) << endn;
    }
    // cout << endn;
 
}
 
int32_t main() {
    FIO
    sub();
    auto start1 = high_resolution_clock::now();
    tt = 1; int s;
    // cin >> tt;
    Ff(s, 1, tt + 1)
    {
        // cout << "Case #" << s << ": " ;
        solve();
        // count();
 
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr << "Time: " << (double)duration . count() / 1000 << " ms" << endl;
    return 0;
}
