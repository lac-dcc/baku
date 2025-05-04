#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif
//By-Ashutosh Kumar Pathak
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
mt19937  rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
#define ll long long
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define pb push_back
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("errorf.in", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> c(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        vector<int> dp(x + 1);
        dp[0] = 1;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= n; j++)
                if (i >= c[j])
                    dp[i] = (dp[i] + dp[i - c[j]]) % mod;
        }
        cout << dp[x];
    }
    return 0;
}
