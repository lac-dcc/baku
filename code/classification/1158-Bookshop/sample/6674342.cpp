//Template {
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
//IO templates
#define newl "\n"
#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
#define fileIO(x) ifstream fin("(x).in"); ofstream fout("(x).out")
#define interact(n) fflush(stdout); cin >> n; if (n == -1) return 0
#define testcases int t; cin >> t; fun(i, t) solve();
#define vectorIO(n, MikuBondage) fun(j, n) {int i; cin >> i; MikuBondage.pb(i);}
#define vector2IO(n, MikuBondage) fun(j, n) {int i, ii; cin >> i >> ii; MikuBondage.pb(mp(i, ii));}
#define edgeIO(m) fun(i, m) {int a, b; cin >> a >> b; addEdges(a, b);}
#define WeightedEdgeIO(m) fun(i, m) {int a, b, c; cin >> a >> b >> c; addWeightedEdges(a, b, c);}
 
//types
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ld long double
#define str string
 
//vector
#define pb push_back
#define append push_back
 
//pairs
#define mp make_pair
#define p2 pair<int, int>
#define p3 pair<int, p2>
#define m3(x, y, z) mp(x, mp(y, z))
#define ich first
#define ni second.first
#define sanshi second.second
 
//For loops
#define ahegao(i, a, b) for (int i = a; i < b; i++)
#define baka(i, b, a) for (int i = b; i > a; i--)
#define fun(i, n) for (int i = 1; i <= (n); (i)++)
#define fon(i, n) for (int i = 0; i < (n); (i)++)
#define fur(i, n) for (auto i : (n))
#define traverseChildren fur(i, adj[x]) if (i != from)
 
//Sorts
#define sz(a) ((signed) a.size())
#define all(a) a.begin(), a.end()
#define Sort(a) sort((a).begin(), (a).end())
#define rSort(a) sort((a).rbegin(), (a).rend())
#define clamp(x, y) (x) = min((x), (y))
#define CLAMP(x, y) (x) = max((x), (y))
 
//Other stuff
#define elif else if
#define addEdges(a, b) adj[a].pb(b); adj[b].pb(a)
#define addWeightedEdges(a, b, c) adj[a].pb(mp(b, c)); adj[b].pb(mp(a, c))
#define find find_by_order
#define printLength(x) if (x < INF) cout << x << newl; else cout << -1 << newl;
#define printArray(k, a) fun(i, k) cout << a[i] << ' '; cout << newl;
#define printVector(a) fur(i, a) cout << i << ' '; cout << newl;
 
//Constants
const int MOD = 1e9+7;
const int SMALLMOD = 998244353;
const int INF = 2e9+1337;
const ll EXCEED = 2e18+1337;
const ll GRAVITY = 9e18;
 
// #define int ll
//}
 
vector<int> price, numPages;
int n, x;
int dp[100001];
 
signed main() {
    cin >> n >> x;
    vectorIO(n, price);
    vectorIO(n, numPages);
    fon(i, n) {
        baka(j, x, price[i]-1)
        CLAMP(dp[j], dp[j - price[i]] + numPages[i]);
    }
    cout << dp[x];
}
 
 
