#include <bits/stdc++.h>
 
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
 
// typedef tree<int,null_type,less<int>,rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;
//auto x = s.find_by_order(2);s.order_of_key(6);
 
#define fatak                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
 
#define newl cout << "\n"
#define prDouble(x) cout << fixed << setprecision(10) << x
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
 
// Shortcuts for "common" data types in contests
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;
 
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using psi = pair<string, int>;
 
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;
using vpsi = vector<psi>;
 
using si = set<int>;
using msi = map<string, int>;
 
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers
//priority_queue<int> q;
// priority_queue<int,vector<int>,greater<int>> q;
const int mod = 1'000'000'007;
const int N = 3e5;
vi g[N]; bool vis[N];
int a[N];
ll binexp(ll a, ll b);//binary exponentiation
bool comp(pii &a, pii &b); //comparator
void ipgraph(int n);// input graph edgelist
void dfs(int u);
 
/* _______________________________________________________________________________ */
 
void gg() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int grid[1005][1005];
bool visited[1005][1005];
int n,m;
void dfs(int u_x,int u_y){
	if (visited[u_x][u_y]) return;
    visited[u_x][u_y] = true;
    // process node s
    for (int i=0;i<4;i++) {
        int x = u_x+dx[i];
        int y = u_y+dy[i];
        if(0<=x&&x<n&&0<=y&&y<m&&grid[x][y]==0&&!visited[x][y]){
            dfs(x,y);
        }
    }
    return;
}
int main()
{
    fatak;
    int t;
    // cin >> t;
    t=1;
    while (t--)
    {
        
        cin >>n>>m;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char c;
                cin >> c;
                if(c=='#') grid[i][j]=1;
                else grid[i][j]=0;
            }
        }
        // bool visited[n][m];
        int ans{};
        memset(visited,false,sizeof visited);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0&&!visited[i][j]){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
 
/* ________________________________________________________________________________ */
 
ll binexp(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 
bool comp(pii &a, pii &b)
{
    return a.second < b.second;
}
void ipgraph(int m){
	int u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}
 
 
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
