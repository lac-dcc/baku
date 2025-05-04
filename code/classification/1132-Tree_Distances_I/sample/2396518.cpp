#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// --------------------------------------------------------
template<class T> bool chmax(T& a, const T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, const T b) { if (b < a) { a = b; return 1; } return 0; }
#define FOR(i,l,r) for (ll i = (l); i < (r); ++i)
#define RFOR(i,l,r) for (ll i = (r)-1; (l) <= i; --i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define MIN(c) *min_element(ALL(c))
#define MAX(c) *max_element(ALL(c))
#define SUMLL(c) accumulate(ALL(c), 0LL)
#define COUNT(c,v) count(ALL(c),(v))
#define SZ(c) ((ll)(c).size())
#define BIT(b,i) (((b)>>(i)) & 1)
#define PCNT(b) __builtin_popcountll(b)
#define CIN(c) cin >> (c)
#define COUT(c) cout << (c) << '\n'
#define debug(x) cerr << "l." << __LINE__ << " : " << #x << " = " << (x) << '\n'
ll llceil(ll a, ll b) { return (a + b - 1) / b; }
ll bitlen(ll b) { if (b <= 0) { return 0; } return (64LL - __builtin_clzll(b)); }
string toupper(const string& S) { string T(S); REP(i,SZ(T)) T[i] = toupper(T[i]); return T; }
string tolower(const string& S) { string T(S); REP(i,SZ(T)) T[i] = tolower(T[i]); return T; }
template<class T> void cout_line(const vector<T>& ans, ll l, ll r) { for (ll i = l; i < r; i++) { if (i != l) { cout << " "; } cout << ans[i]; } cout << '\n'; }
template<class T> void debug_line(const vector<T>& ans, ll l, ll r, ll L = 0) { cerr << "l." << L << " :"; for (ll i = l; i < r; i++) { cerr << " " << ans[i]; } cerr << '\n'; }
using P = pair<ll,ll>;
using VP = vector<P>;
using VVP = vector<VP>;
using VS = vector<string>;
using VVS = vector<VS>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;
using VD = vector<double>;
using VVD = vector<VD>;
using VVVD = vector<VVD>;
using VLD = vector<ld>;
using VVLD = vector<VLD>;
using VVVLD = vector<VVLD>;
static const double EPS = 1e-10;
static const double PI  = acos(-1.0);
static const ll MOD = 1000000007;
// static const ll MOD = 998244353;
static const ll INF = (1LL << 62) - 1;  // 4611686018427387904 - 1
// --------------------------------------------------------
// #include <atcoder/all>
// using namespace atcoder;
 
 
template <class S, S (*op)(S, S), S (*fv)(S, int), S (*fe)(S, int, int, ll), S (*e)()>
struct rerooting {
    struct edge { int to; ll w; };
    int N;
    vector<vector<edge>> G;
    vector<vector<S>> dp;  // dp[u][i] := u から出る i 番目の有向辺の先の部分木に対応する値
    vector<S> ans;  // ans[u] := u を根とした木に対する答え
    rerooting(int n) : N(n) {
        G.resize(N);
        dp.resize(N);
        ans.resize(N);
    }
 
    // 頂点 u から頂点 v に有向辺を張る
    //   - 無向グラフの場合は両方向を追加する
    void add_edge(int u, int v, ll w) {
        assert(0 <= u && u < N);
        assert(0 <= v && v < N);
        G[u].push_back({v, w});
    }
 
    void build() {
        for (int u = 0; u < N; u++) {
            dp[u].resize(G[u].size());
        }
        dfs1(0, -1);
        dfs2(0, -1, e());
    }
 
    S dfs1(int u, int p) {
        S res = e();
        int m = G[u].size();
        for (int i = 0; i < m; i++) {
            auto [v, w] = G[u][i];
            if (v == p) continue;
            dp[u][i] = dfs1(v, u);
            res = op(res, fe(dp[u][i], u, v, w));
        }
        return fv(res, u);
    }
 
    void dfs2(int u, int p, S px) {
        int m = G[u].size();
        for (int i = 0; i < m; i++) {
            if (G[u][i].to == p) {
                dp[u][i] = px;
                break;
            }
        }
        vector<S> dp_R(m+1);
        dp_R[m] = e();
        for (int i = m; 0 < i; i--) {
            auto [v, w] = G[u][i-1];
            dp_R[i-1] = op(fe(dp[u][i-1], u, v, w), dp_R[i]);
        }
        ans[u] = fv(dp_R[0], u);
        S dp_l = e();
        for (int i = 0; i < m; i++) {
            auto [v, w] = G[u][i];
            if (v != p) dfs2(v, u, fv(op(dp_l, dp_R[i+1]), u));
            dp_l = op(dp_l, fe(dp[u][i], u, v, w));
        }
    }
 
    S query(int u) {
        assert(0 <= u && u < N);
        return ans[u];
    }
};
 
 
// (rerooting) ans[u] := u を根とした時に u から最も遠い頂点までの距離
using S = ll;
S op(S a, S b) { return max(a, b); };
S fv(S x, [[maybe_unused]] int u) { return x; };
S fe(S x, [[maybe_unused]] int s, [[maybe_unused]] int t, ll w) { return x + w; };
S e() { return 0; };
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
 
    ll N; cin >> N;
    rerooting<S, op, fv, fe, e> re(N);
    REP(_,N-1) {
        ll s, t; cin >> s >> t;
        s--; t--;
        re.add_edge(s, t, 1);
        re.add_edge(t, s, 1);
    }
    re.build();
 
    VLL ans(N,0);
    REP(u,N) ans[u] = re.query(u);
    cout_line(ans,0,N);
 
    return 0;
}
