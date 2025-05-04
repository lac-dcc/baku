#include <bits/stdc++.h>
 
using namespace std;
//using namespace chrono;
 
typedef long long ll;
typedef vector< int > vi;
typedef vector< ll > V;
typedef map<int, int > mp;
 
#define pb push_back
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define F first
#define S second
 
#define debug cout << -1 << endl;
#define REP(i, a, b) for(int i=a; i<b; i++)
#define f0r(i, n) for (int i = 0; i < n; ++i)
#define f0r1(i, n) for (int i = 1; i <= n; ++i)
#define r0f(i, n) for(int i=n-1; i>=0; i--)
#define r0f1(i, n) for(int i=n; i>=1; i--)
#define fore(a, x) for (auto& a : x)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
 
#define MP make_pair
#define UB upper_bound
#define LB lower_bound
#define nw cout << "\n"
 
#define issq(x) (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x))
#define rev(v) reverse(v.begin(),v.end())
#define asche cerr<<"Ekhane asche\n";
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define valid(tx,ty) (tx>=0 && tx<n && ty>=0 && ty<m)
#define one(x) __builtin_popcount(x)
//#define pop pop_back
#define setPrec(x) cout << fixed << setprecision(x)
#define sz(a) (int)a.size()
//#define fin cin
//#define fout cout
const int INF = 1e9;
const ll MOD = (ll)1e9+7;
const ll INFL = 1e18;
const ll mnINF = -1e18;
const double diff = 10e-6;
const int maxn = 200005;
const double PI = acos(-1);
using namespace std;
 
// int dx[] = {-1, 0, 1};
// int dy[] = {-1, 0, 1};
 
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
 
int tt = 0;
 
void solve()
{
    int n;
    cin >> n;
    set< int > s;
    f0r(i, n) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << "\n";
}
 
void setIO(string name = "") { // name is nonempty for ----- file I/O
 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
 
    // alternatively, cin.tie(0)->sync_with_stdio(0);
 
    if (name.size()) {
 
        freopen((name+".in").c_str(), "r", stdin); // see Input & Output
 
        freopen((name+".out").c_str(), "w", stdout);
 
    }
 
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif
    //setIO("breedflip");
    FastIO;
    int t;
    t = 1;
    // cin >> t;
    f0r(i, t) {
        //cout << "Case " << i+1 << ": ";
        solve();
    }
    return 0;
}