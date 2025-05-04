#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
 
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL),cout.tie(NULL)
#define PI 3.141592653589793238462
//#define PI 1.0l*acos(-1)
#define MOD 1000000007
//#define MOD 998244353
#define INF 1e18
#define nl '\n'
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define loop(i,a,b) for (int i = a; i <= b; i++)
#define rloop(i,a,b) for (int i = a; i >= b; i--)
#define tc(t) int t; cin >> t; while (t--)
#define prec(n) fixed<<setprecision(n)
#define ini(a, i) memset(a, i, sizeof(a))
 
#define us unordered_set
#define um unordered_map
#define ll long long
#define ull unsigned long long
#define maxpq priority_queue<int>
#define pii pair<int, int>
#define minpq priority_queue<int, vector<int>, greater<int> >
 
#ifdef kk_singh
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void google(int t) {cout << "Case #" << t << ": ";}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
vector<vector<int>> pre(int N){
    vector<vector<int>> divs(N);
    loop(i, 1, N-1){
        for(int j=i;j<N;j+=i)
            divs[j].pb(i);
    }
return divs;
}
 
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll gcd(ll a, ll b) {  return b ? gcd (b, a % b) : a;  }
ll add(ll x, ll y, ll m) {ll res=x+y; return res>=m ? res-m:res;}
ll mul(ll x, ll y, ll m) {ll res=x*y; return res>=m? res%m:res;}
ll sub(ll x, ll y, ll m) {ll res=x-y; return res<0? res+m:res;}
ll power(ll x, ll y, ll m) {ll res=1; x%=m; while(y){ if (y&1) res=mul(res, x, m); y >>=1; x=mul(x, x, m);} return res;}
 
 
void solve(){
 
    int n, x; cin >>n >> x;
    // vector<int> v(n);
    vector<pair<int, int>> v(n);
 
    loop(i, 0, n-1){
        cin >> v[i].f;
        v[i].s = i;
    }
 
    sort(all(v));
 
    int i=0, j=n-1;
 
    while(i<j){
        if (v[i].f+v[j].f==x){
            cout << v[i].s+1 << " " << v[j].s+1;
            return;
        }
        else if (v[i].f+v[j].f>x){
            j--;
        }
        else{
            i++;
        }
    }
    cout << "IMPOSSIBLE";
}
 
int main(){
#ifdef kk_singh
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
 
#ifdef kk_singh
freopen("Error.txt", "w", stderr);
#endif
 
fio;
auto start1 = high_resolution_clock::now();
int t = 1;
//cin >> t;
while(t--)
solve();
auto stop1 = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop1 - start1);
 
#ifdef kk_singh
cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}
