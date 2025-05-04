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
#include <string>
#include <sstream>
 
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
const int MAXMAXN = 1e6 + 2;
const double EPS = 1e-6;
 
 
///structure ///
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
 
/// vector, pair, tuple ///
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ff first
#define ss second
#define SIZE(name) (int)name.size()
#define ft(x) get<0>(x)
#define st(x) get<1>(x)
#define tt(x) get<2>(x)
 
/// for ///
#define forn(i, n) for (int i = 0; i < n; i++)
#define FOR(i, l, r) for (int i = l; i <= r; i++)
 
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
 
ull mypow(ull a, ull n)
{
    if (n == 0)
        return 1;
    ull tmp = mypow(a, n / 2);
    if (~n & 1)
        return (tmp * tmp) % INF;
    return ((tmp * tmp) % INF) * a % INF;
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ull n; cin >> n;
    ull sum = 0;
    for (ull i = 1; i * i <= n; i++)
    {
        sum += n / i * i;
        sum %= INF;
        ull l = n / (i + 1) + 1;
        ull r = n / i;
        if (l > i)
        {
            //sum += n / l * (l + r) * (r - l + 1) / 2;
            ull c = (l + r) % INF;
            c *= (r - l + 1) % INF;
            c %= INF;
            c *= mypow(2, INF - 2);
            c %= INF;
            sum += n / l * c % INF;
        }
        sum %= INF;
    }
    cout << sum << endl;
    return 0;
}
