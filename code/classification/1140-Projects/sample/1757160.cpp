#include <bits/stdc++.h>
#include <tuple>
using namespace std;
 
#ifdef LOCAL 
string to_string(char a) { return string(1,a); }
string to_string(bool a) { return a ? "1" : "0"; }
string to_string(const char* a) { return (string)a; }
string to_string(string a) { return a; }
string to_string(vector<bool> v) {
	string s = "["; for(unsigned i=0;i<v.size();i++){ s += ((i>0)?" ":"");
    s += char('0'+v[i]); } 	s += "]"; return s; }
template<class A, class B> string to_string(pair<A,B> p);
template<class T> string to_string(T v) {
	bool b = 1; string s = "["; for (const auto& x: v) {
		if (!b) {s += ", ";} b = 0; s += to_string(x); } s += "]"; return s; }
template<class A, class B> string to_string(pair<A,B> p) {
	return "("+to_string(p.first)+", "+to_string(p.second)+")"; }
void dbgf() { cerr << endl; }
template<class H, class... T> void dbgf(H h, T... t) {
	cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
	dbgf(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << " = ", dbgf(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
#define boolout(x) cout<<(x?"YES":"NO")<<endl;
typedef long long ll;
 
const int mod = 1e9+7;
//array<int, 3> a[100005];
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    set<array<ll, 2>> stt;
    ll dp = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    }
    stt.insert({0, 0});
    sort(a.begin(), a.end());
 
    for (int i = 0; i < n; i++) {
        auto it = stt.lower_bound({a[i][1]});
        it--;
        dp = max(dp, (*it)[1]+ (ll)a[i][2]);
        stt.insert({a[i][0], dp});
    }
 
    cout << dp << endl;
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}