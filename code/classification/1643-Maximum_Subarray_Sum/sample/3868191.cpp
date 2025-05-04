// Vaibhav Goyal
#include <bits/stdc++.h>
using namespace std;
 
// ---------------------------------Policy Based DataStructures----------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
//defining template when all elements are distinct
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//defining template when duplicate elements are also used
template <class T> using omulset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
//  .find_by_order(x) : index of the x element in the set starting from 0
//  .order_of_key(x)  : number of elements strictly smaller than x in the set
// ------------------------------------------------------------------------------------
 
typedef long long ll;
 
// shortforms
#define pb                      push_back
#define ff                      first
#define ss                      second
#define pr(x)                   cout << (x) << '\n';
#define prc(x)                  cout << (x) << ' ';
#define br                      pr("");
#define all(v)                  v.begin(), v.end()
#define int                     long long
#define f(i, N)                 for(int i=0; i < N; i++)
#define F(i, N)                 for(int i=1; i <= N; i++)
#define rep(i, begin, end)      for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define sortv(v)                sort(v.begin(), v.end());
#define rsortv(v)               sort(v.begin(), v.end()); reverse(all(v));
#define read(v)                 for(auto &X_: v) cin >> X_;
#define uniq(A)                 sort(A.begin(),A.end());A.erase(unique(A.begin(),A.end()),A.end());
 
// Bitwise Operators
 
/*
 * Adding lsb to a number
 * x = (x | (x - 1)) + 1
 */
#define CHECK(i, n)             ((n & (1LL << i)) > 0)           // ith bit is set in n
#define ONES(x)                 __builtin_popcountll(x)     // n is unsigned long long
#define LSB(n)                  __builtin_ffsll(n) - 1      // n is unsigned long long
#define tralingzeroes(n)        __builtin_ctzll(n)          // n is unsigned long long
#define leadingzeroes(n)        __builtin_clzll(n)          // n is unsigned long long
#define LSBVAL(n)               (n & ~(n - 1))
 
#define gcd(a, b)               __gcd(a, b)
#define lcm(a, b)               a * b / __gcd(a, b)
 
 
// arrays
using vl = vector<int>;
using vvl = vector<vector<int>>;
using pl = pair<int, int>;
using vpl = vector<pl>;
using vvpl = vector<vector<pl>>;
 
 
// printers
#define pr2(x1, x2) prc(x1)pr(x2)
#define pr3(x1, x2, x3) prc(x1)prc(x2)pr(x3)
#define pr4(x1, x2, x3, x4) prc(x1)prc(x2)prc(x3)pr(x4)
#define show(A) for (auto &i: A) cout << i << " "; cout << '\n';
#define show_(A, n) f(i, n) { prc(A[i]) } br
#ifndef ONLINE_JUDGE
#include "myprettyprint.hpp"
#else
#define dbg(...)
#endif
 
// CONSTANTS
const double eps = 1e-7;
const int inf = 1e18;
const bool POSSIBLE = true;
const bool NOT_POSSIBLE = false;
const vpl movements = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int mod = 1e9 + 7;
const int bits = 32;
const int mxn =  3e7 / 2 + 23423;
 
void addSelf(int &a, int b) { a = (((a % mod) + (b % mod) + mod) % mod); }
#define add(a, b)           ((((a) % mod) + ((b) % mod) + mod) % mod)
void subSelf(int &a, int b) { a = (((a % mod) - (b % mod) + mod) % mod); }
#define sub(a, b)           ((((a) % mod) - ((b) % mod) + mod) % mod)
#define mul(a, b)           ((((a) % mod) * ((b) % mod) + mod) % mod)
void mulSelf(int &a, int b) { a = (((a % mod) * (b % mod) + mod) % mod) ;}
void minSelf(int &a, int b) { a = min(a, b) ;}
void maxSelf(int &a, int b) { a = max(a, b) ;}
 
ll mpow(ll base, ll exp){
    ll res = 1;
    while(exp > 0){
        if(exp&1) res = (res*base)%mod;
        base = (base*base) % mod;
        exp >>= 1;
    }
    return res;
}
int ceilDiv(int a, int b) {
    return (a + b - 1) / b;
}
int MSB(int x) {
    return 64 - leadingzeroes(x) - 1;
//    for (int i = bits; i>=0; --i){
//        if (x & (1LL << i)) {
//            return i;
//        }
//    }
//    return -1;
}
 
// fenwick tree
// promising string (hard)
// k-good
// gcd-guess
// collecting numbers 2
//1566E - Buds Re-hanging,
//1534E - Lost Array,
//1521D - Nastia Plays with a Tree,
//101234I - Tree Game.
// https://codeforces.com/contest/1369/problem/B
//C. Oranges and Apples
 
 
 
 
struct Solve_karde_bhai {
    // variables
    void aabhi_karta_hu_bro() {
//        int n, a, b; cin >> n >> a >> b;
        int n; cin >> n;
        vl A(n); read(A)
        vl pref = A;
        for (int i = 1; i < n; ++i) {
            pref[i] += pref[i - 1];
        }
        multiset<int> ms;
        ms.insert(0);
        int ans = -inf;
        for (int i = 0; i < n; ++i) {
            maxSelf(ans, pref[i] - *ms.begin());
            ms.insert(pref[i]);
        }
        pr(ans)
 
 
 
 
 
 
    }
 
 
};
 
 
 
 
 
 
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
//    cout << setprecision(20);
//    Functions Called
//    seive();
//    factors_seive();
//    calc_fact();
//    precalc();
 
    int tc = 1;
//    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        Solve_karde_bhai solution;
        solution.aabhi_karta_hu_bro();
    }
}
