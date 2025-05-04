#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <iomanip>
#include <cstring>
 
using namespace std;
 
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
 
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T>
//using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define ff first
#define ss second
 
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define add(a, b) (a + b >= MOD ? a + b - MOD : a + b)
#define all(x) (x).begin(), (x).end()
// #define unique(x) sort(all(x)), (x).erase(unique(all(x)), (x).end())
#define tolower(x) transform(all(x), (x).begin(), ::tolower)
#define toupper(x) transform(all(x), (x).begin(), ::toupper)
#define remove_all(x, y) (x).erase(remove(all(x), char(y)), (x).end());
 
#define input(in) freopen(in, "r", stdin)
#define output(out) freopen(out, "w", stdout)
 
const int INF = 2147483647;
const ll LINF = 9223372036854775807;
// const double EPS = 1e-10;
// const double gam = 0.5772156649015328606; //euler's constant
// const double PI = acos(-1.0);
const int dx[8] = {-1, 0, 0, 1, 1, 1, -1, -1};
const int dy[8] = {0, -1, 1, 0, 1, -1, 1, -1};
// const int dxx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
// const int dyy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
const int MOD = 1000000007;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
 
void solve()
{
    int n, x;
    cin >> n >> x;
 
    vector<pii> a;
    for (int i = 1, x; i <= n; i++)
        cin >> x, a.eb(x, i);
 
    sort(all(a));
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1, l = n - 1; k < l; k++)
            {
                while (k < l and a[i].ff + a[j].ff + a[k].ff + a[l].ff > x)
                    l--;
 
                if (k < l and a[i].ff + a[j].ff + a[k].ff + a[l].ff == x)
                    cout << a[i].ss << " " << a[j].ss << " " << a[k].ss << " " << a[l].ss, exit(0);
            }
        }
    }
    cout << "IMPOSSIBLE";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t(1);
    // cin >> t;
    while (t--)
        solve();
 
    return 0;
}
