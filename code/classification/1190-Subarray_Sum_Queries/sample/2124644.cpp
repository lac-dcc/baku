#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
// using namespace __gnu_pbds;
 
 
typedef long long ll;
typedef unsigned long long ull;
 
/*
typedef
tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
indexed_set;
*/
 
 
const int INF = 1e9 + 7;
const ll INF64 = 1e18 + 7;
const int MAXN = 1e5 + 2;
const int heavy = 447;
 
 
/// vector, pair, tuple ///
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ff first
#define ss second
#define SIZE(name) (int)name.size()
 
/// for ///
#define forn(i, n) for (int i = 0; i<n; i++)
#define FOR(i, l, r) for (int i = l; i<=r; i++)
 
/// iterator ///
#define ALL(name) name.begin(), name.end()
#define RALL(name) name.rbegin(), name.rend()
 
template<typename T> inline T getint()
{
    T val = 0;
    char c;
    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9'))
    {
        neg |= c == '-';
    }
    do
    {
        val = (val * 10) + c - '0';
    }while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val * (neg ? -1 : 1);
}
 
int gcd(int a, int b)
{
    while (a && b)
        a > b ? a %= b : b %= a;
    return a + b;
}
 
struct vertex
{
    ll pref, suf, max_sum, sum;
    vertex()  {};
    vertex(ll pref, ll suf, ll max_sum, ll sum) : pref(pref), suf(suf), max_sum(max_sum), sum(sum) {};
 
};
 
vertex uni(vertex l, vertex r)
{
    vertex v;
    v.max_sum = max(l.suf + r.pref, max(l.max_sum, r.max_sum));
    v.sum = l.sum + r.sum;
    v.pref = max(l.pref, l.sum + r.pref);
    v.suf = max(r.suf, l.suf + r.sum);
    return v;
}
 
int n, q;
int sz = 1;
vector<vertex>tree;
 
void build()
{
    while (sz < n) sz *= 2;
    for (int i = sz; i < sz + n; i++)
    {
        ll a; cin >> a;
        tree[i] = vertex(a, a, a, a);
    }
    for (int i = sz - 1; i > 0; i--)
    {
        tree[i] = uni(tree[2 * i], tree[2 * i + 1]);
    }
}
 
void update(int idx, int x)
{
    idx += sz;
    tree[idx] = vertex(x, x, x, x);
    for (int i = idx / 2; i > 0; i /= 2)
        tree[i] = uni(tree[2 * i], tree[2 * i + 1]);
}
 
int main()
{
    cin >> n >> q;
    tree = vector<vertex>(4 * n, vertex(0, 0, 0, 0));
    build();
    forn(t, q)
    {
        int idx; ll val; cin >> idx >> val;
        update(--idx, val);
        if (tree[1].max_sum < 0)
            cout << 0 << endl;
        else
            cout << tree[1].max_sum << endl;
    }
    return 0;
}
