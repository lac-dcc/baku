/*---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---*/
 
#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b)	for(int i = a; i < (b); ++i)
#define rrep(a, b, c)	for(int a = (b); a > c; --a)
#define each(a, b)		for(auto& a : b)
 
#define sz(x)       (int)(x).size()
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(), (a).rend()
 
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define V vector
#define ar array
#define pi pair<int, int>
#define vi vector<int>
#define pl pair<ll, ll>
#define pct(x) __builtin_popcount(x)
#define rsz resize
#define bk back()
 
constexpr int log2(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x))
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
 
template <class T> bool umin(T& a, const T& b){return b<a?a=b, 1:0;}
template <class T> bool umax(T& a, const T& b){return a<b?a=b, 1:0;}
 
using ll = long long;
using ld = long double;
using str = string;
 
const int inf = (int)1e9 + 5;
const ll infl = (ll)1e18 + 5;
const ld PI = acos((ld)-1);
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
 
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
 
/*---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---XXX---*/
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = rng();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
unordered_map<int, pi, custom_hash> m;
 
void solve(){
	int n, X; cin >> n >> X;
	vi v(n);
	each(x, v) cin >> x;
 
	rep(i, 0, n){
		rep(j, i+1, n){
			int s = v[i] + v[j];
			if(s >= X) continue;
			int rs = X - s;
			auto it = m.find(rs);
			if(it == m.end()) continue;
 
			cout << it->s.f+1 << ' ' << it->s.s+1 << ' ' << i+1 <<' ' << j+1 << '\n';
			return;
		}
 
		rep(j, 0, i){
			int s = v[i] + v[j];
 
			if(s < X){
				m[s] = {i, j};
			}
		}
	}
 
	cout << "IMPOSSIBLE" << '\n';
}
 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
		solve();
}