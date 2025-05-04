#include <bits/stdc++.h>
 
using namespace std;
 
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
 
template <typename A, typename B> 
string to_string(pair<A, B> p) { 
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; 
}
 
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first)
            res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define snp string::npos
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;
 
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    freopen("_data.in", "rt", stdin);
#endif
 
    int n; cin>>n;
    int k; cin>>k;
    vpi a(n);
    forn (i, n) {
        cin>>a[i].se;
        cin>>a[i].fi;
    }
    sort(all(a));
    vector<tuple<int, int, int>> b(2*n);
    forn (i, n) {
        b[2*i] = mt(a[i].fi, 0, i);
        b[2*i+1] = mt(a[i].se, 1, i);
    }
    sort(all(b));
    set<int> d;
    int sol = 0;
    for (auto x : b) {
        int time, type, pos;
        tie(time, type, pos) = x;
        if (type == 1) {
            d.insert(-pos);
            if (d.size() > k) {
                d.erase(d.begin());
            }
        }
        else {
            if (d.count(-pos)) {
                d.erase(-pos);
                sol++;
            }
        }
        debug(d);
        // debug(time, type, pos);
    }
    cout<<sol;
 
#ifdef LOCAL
    cerr << endl << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    return 0;
}
