#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#ifdef TOWRIST
    #define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
#else
    #define debug(...);
#endif
 
template <typename T> std::ostream &operator<<(std::ostream &stream, const vector<T> &vec) {for (size_t i = 0; i < vec.size(); i++) { stream << vec[i]; if (i != vec.size() - 1) stream << ' '; }; return stream; } template <typename T> std::istream &operator>>(std::istream &stream, vector<T> &vec) {for (T &x : vec) stream >> x; return stream; } template <typename T, typename U> std::ostream &operator<<(std::ostream &stream, const pair<T, U> &pr) {stream << pr.first << ' ' << pr.second; return stream; } template <typename T, typename U> std::istream &operator>>(std::istream &stream, pair<T, U> &pr) {stream >> pr.first >> pr.second; return stream; } template <typename A, typename B> string to_string(pair<A, B> p); template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p); template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p); string to_string(const string &s) { return '"' + s + '"'; } string to_string(char c) {string s; s += c; return s; } string to_string(const char *s) { return to_string((string)s); } string to_string(bool b) { return (b ? "1" : "0"); } string to_string(vector<bool> v) {bool first = true; string res = "{"; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", "; } first = false; res += to_string(v[i]); } res += "}"; return res; } template <size_t N> string to_string(bitset<N> v) {string res = ""; for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]); } return res; } template <typename A> string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", "; } first = false; res += to_string(x); } res += "}"; return res; } template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; } template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; } template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; } void debug_out() { cout << endl; } template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cout << " " << to_string(H); debug_out(T...); }
 
#define int     long long   
#define all(x)  x.begin(), x.end()
#define double  long double
#define endl    '\n'
#define ff      first
#define ss      second
#define v       vector
 
using pii = pair<int, int>;
const bool multipleTestCases = 0;
const int mod = 1e9 + 7;
 
int power(int x, int n) {
    if(n == 0) return 1;
    if(n % 2 == 1) {
        return (x * power(x, n - 1)) % mod;
    }
    int h = power(x, n / 2);
    return (h * h) % mod;
}
 
int modInv(int x){
    return power(x, mod - 2);
}
 
int sumOfAP(int a, int an) {
    int n = an - a + 1;
    return ((((n % mod) * ((a + an) % mod)) % mod) * modInv(2)) % mod;
}
 
void solve()  {
 
    int n; cin >> n;
    int ans = 0;
 
    int low = 1;
    int high = n;
    while(low <= high) {
        int multiplesCount = n / low;
        ans += (multiplesCount * low) % mod;
        ans %= mod;
 
        if(low == high) {
            break;
        }
        
        int l = low;
        int r = high;
        while(r - l > 1) {
            int m = (l + r) / 2;
            if((n / m) == (n / high)) {
                r = m;
            } else {
                l = m;
            }
        }
 
        ans += ((n / high) * (sumOfAP(r, high))) % mod;
        ans %= mod;
 
        ++low;
        high = r - 1;
    }
 
    cout << ans << endl;
}
 
signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    multipleTestCases and cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
