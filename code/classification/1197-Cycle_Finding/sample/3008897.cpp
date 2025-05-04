#pragma GCC optimize("O3")
#define _USE_MATH_DEFINES
// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <vector>
#include <queue>
#include <climits> // LLONG_MAX
#include <iomanip>
#include <string.h> // strchar (debug)
#include <numeric> // partial sum, iota
using namespace std;
 
 
/*#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
 
typedef tree <
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update >
ordered_set;
#define ofk order_of_key*/
 
 
#ifndef ONLINE_JUDGE
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args> void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " ";
    __f(comma + 1, args...);
}
#else
#define debug(...)
#endif
 
#define go_gadget_go cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define array_size(x) int(sizeof(x) / sizeof(x[0]))
 
#define pb push_back
#define count_binary_ones_i(x) __builtin_popcount(x)
#define count_binary_ones_ll(x) __builtin_popcountll(x)
 
#define str_to_ll(x) atoll(x.c_str());
const ll MOD = 1e9 + 7;
 
ll read()
{
    ll a = 0;
    char b = 1, c;
    do if ((c = getchar()) == 45)b = -1; while (c < 48 || c > 57);
    do a = (a << 3) + (a << 1) + (c & 15); while ((c = getchar()) > 47 && c < 58);
    return a * b;
}
void write(ll x, char c)
{
    if (x < 0)putchar(45), x = -x;
    char a[20], s = 0;
    do a[++s] = x % 10 | 48; while (x /= 10);
    do putchar(a[s]); while (--s);
    putchar(c);
}
/*------- User-defined Functions------*/
struct edges
{
    ll a, b, w;
};
 
void path(ll n, ll x, vector<ll> p) {
    puts("YES");
    for (ll i = 0; i < n; ++i)
        x = p[x];
 
    vector<ll> cycle;
    ll node = x;
    cycle.push_back(node);
 
    do
    {
        node = p[node];
        cycle.push_back(node);
 
    } while (node != x);
 
    for (ll i = cycle.size() - 1; i >= 0; --i)
    {
        write(cycle[i], ' ');
    }
}
/*------------------------------------*/
void solution()
{
    ll n, e;
    n = read();
    e = read();
 
    vector<edges> v(e);
    for (auto && i : v) {
        // ll a, b, w;
        i.a = read();
        i.b = read();
        i.w = read();
        // i.a = a, i.b = b, i.w = w;
    }
 
    vector<ll> d(n + 1), p(n + 1, -1);
    ll x;
    for (ll i = 0; i < n; ++i)
    {
        x = -1;
        for (auto && e : v) {
            if (d[e.b] > d[e.a] + e.w)
            {
                d[e.b] = max(LLONG_MIN, d[e.a] + e.w);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }
 
    if (x == -1) puts("NO");
    else
    {
        path(n, x, p);
    }
 
}
 
/*
 
Code by:
 
▄▄▄█████▓▓█████   ██████  ██▓     █    ██  ███▄ ▄███▓
▓  ██▒ ▓▒▓█   ▀ ▒██    ▒ ▓██▒     ██  ▓██▒▓██▒▀█▀ ██▒
▒ ▓██░ ▒░▒███   ░ ▓██▄   ▒██░    ▓██  ▒██░▓██    ▓██░
░ ▓██▓ ░ ▒▓█  ▄   ▒   ██▒▒██░    ▓▓█  ░██░▒██    ▒██
  ▒██▒ ░ ░▒████▒▒██████▒▒░██████▒▒▒█████▓ ▒██▒   ░██▒
  ▒ ░░   ░░ ▒░ ░▒ ▒▓▒ ▒ ░░ ▒░▓  ░░▒▓▒ ▒ ▒ ░ ▒░   ░  ░
    ░     ░ ░  ░░ ░▒  ░ ░░ ░ ▒  ░░░▒░ ░ ░ ░  ░      ░
  ░         ░   ░  ░  ░    ░ ░    ░░░ ░ ░ ░      ░
            ░  ░      ░      ░  ░   ░            ░
 
*/
 
signed main()
{
    // go_gadget_go;
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
 
    ll  T = 1;
    // cin >> T;
    while (T--)
    {
        solution();
        // if (T) cout << endl;
        if (T) putchar(endl);
    }
 
    return 0;
}
 
 
/*
skipped:
problems) prime path, feasible relations, social networking,
topics) LCA, distance between any two nodes
-------------------------------------------------
try again:
chefrun (codechecf), Round Trip (CSES), Message Round (CSES), Flight Routes (CSES),
bertown roads (codeforces)
*Monsters (CSES) - Hella sht :-) (remember about multi source BFS!)
 
*/
 
/*
NOTES:
----
if Y is subtree of X then:
in of X should be less than Y
out of X sohuld be greater then Y
 
if Y is not a subtree of X then:
in and out of Y will be less or greater than of X
----
SSSP:
1) tree - dfs
2) graph - bfs
----
dfs lexicographical smallest order -> sort adj list of current node by greater<T>() and start from N to 1
 
*/
