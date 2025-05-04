#include<bits/stdc++.h>
using namespace std;
 
void DBG() { cerr << "]\n"; }
template<class H, class... T> void DBG(H h, T... t) {
    cerr << h; if(sizeof...(t)) cerr << ", ";
    DBG(t...);
}
#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif // LOCAL
 
#define FOR(i,a,b) for(int i = (a) ; i<(b) ; i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for(int i = (b)-1 ; i>=(a) ; i--)
#define R0F(i,a) ROF(i,0,a)
#define each(e,a) for(auto &e : (a))
#define sz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back
#define tcT template<class T
#define nl "\n"
 
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using str = string;
tcT> using V = vector<T>;
tcT> using pqg = priority_queue<T,vector<T>,greater<T>>;
 
void setIO(string NAME = "") {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(NAME)) {
        freopen((NAME + ".inp").c_str(),"r",stdin);
        freopen((NAME + ".out").c_str(),"w",stdout);
    }
}
 
tcT> bool ckmin(T&a, const T&b) {
    return b < a ? a=b,1 : 0; }
tcT> bool ckmax(T&a, const T&b) {
    return b > a ? a=b,1 : 0; }
 
constexpr int pct(int x) { return __builtin_popcount(x); }
 
const int MOD = 1e9 + 7;
 
const int MX = 20;
 
 
ll N, A[MX];
int K;
 
void solve() {
    cin>>N>>K;
    F0R(i,K) cin>>A[i];
    ll ans = 0;
    FOR(msk,1,1<<K) {
        ll lc = 1;
        F0R(i,K) if(msk>>i&1) {
            if(lc > N/A[i]) {
                lc = N+1;
                break;
            }
            lc *= A[i];
        }
        if(pct(msk)&1) ans += N/lc;
        else ans -= N/lc;
    }
    cout << ans << nl;
}
 
int main() {
    setIO();
 
    int t=1;
    //cin>>t;
    while(t-->0) {
        solve();
    }
 
    return 0;
}
