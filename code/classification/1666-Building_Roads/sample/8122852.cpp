#include <bits/stdc++.h>
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
// using namespace __gnu_pbds;
#define rep(i, k, n) for(i = k; i < n; i++)
#define yes_or_no(f) cout << (f ? "YES\n" : "NO\n")
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define AND &&
#define OR ||
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
// #define int long long
// #define float long double
// #define deb(x) cout << #x << " " << x << "\n"
// typedef long int int32;
// typedef unsigned long int uint32;
// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> pii;
#define mod 1000000007
// --------------------------------------------------------------------
 
const int maxN = 1e5;
vii adj(1+maxN);
int dir[4][2] = {{1,0},{0,1},{-1,0}, {0,-1}};
bool visited[1+maxN];
 
void dfs(int i) {
    visited[i] = true;
    for (int x : adj[i]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
};
 
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<int> components;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components.pb(i);
            dfs(i);
        }
    }
    cout << components.size() - 1 << "\n";
    for (int i = 1; i < components.size(); i++) {
        cout << components[i-1] << " " << components[i] << "\n";
    }
}
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int T = 1;
 
    // cin >> T;
	for (int i = 1; i <= T; ++i)
	{
	    solve();
	}
 
	return 0;
}
