using namespace std;
//@formatter:off
 
#ifdef lol
#include "stdc++.h"
const bool dbg = true;
#else
#include <bits/stdc++.h>
const bool dbg = false;
#endif
 
#define dout if(dbg) cout
 
#define int int64_t
 
#define val(x) #x << " = " << (x)
#define bug(x) cout << val(x) << endl;
#define loop(i, s, n) for (int i = s; i < n; ++i)
#define fin(i, s, n) for (auto i = s; i < n; ++i)
#define fine(i, s, n) for (auto i = s; i <= n; ++i)
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define def(x) int x; cin >> x
#define cases def(t); while (t--)
#define cases1 int t = 1; while(t--)
#define all(x) (x).begin(), (x).end()
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vii = vector<ii>;
using vvii = vector<vector<ii>>;
using dd = pair<double, double>;
using vd = vector<double>;
using vdd = vector<dd>;
using vvd = vector<vd>;
using vb = vector<bool>;
using vvb = vector<vb>;
using ld = long double;
//using bigint = __int128;
#define tct template<class T>
#define tcab template<class A, class B>
tcab ostream &operator<<(ostream &os, pair<A, B> p) { return os << '{' << p.x << ',' << p.y << '}'; }
tcab istream& operator>>(istream& is, pair<A,B>& p) { return is >> p.x >> p.y; }
tct istream& operator>>(istream& is, vector<T>& v) { for(auto& x : v) is >> x; return is; }
tct ostream& operator<<(ostream& os, vector<T>& v) { for(auto& x : v) os << x << " "; return os; }
#define popcnt(x) __builtin_popcount(x)
int rnd() { return rand()^(rand()<<15); }
#define sz(a) int((a).size())
 
//@formatter:on
 
 
int32_t main() {
    if (dbg) freopen("ina.txt", "r", stdin);
    else cin.tie(0)->sync_with_stdio(0);
 
    int n, x;
    cin >> n >> x;
 
    vi c(n), dp(x, 0);
    cin >> c;
 
    fin(j, 0, n) {
        if(c[j] <= x) dp[c[j] - 1] += 1;
        fin(i, 0, x) {
            if (i - c[j] < 0) continue;
            dp[i] = (dp[i] + dp[i - c[j]]) % (int(1e9) + 7);
        }
    }
 
    cout << dp[x - 1];
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
