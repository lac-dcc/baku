#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define FAST		    ios_base::sync_with_stdio(false); cin.tie(NULL);
#define prs(n)		    cout << fixed << setprecision(n)
#define ll			    long long
#define db			    double
#define fo(i,m,n)       for(int i = m; i <= n; i++)
#define fob(i,m,n)      for(int i = n; i >= m; i--)
typedef                 pair<int, int> ii;
typedef                 vector<ii> vii;
typedef                 vector<vii> vvii;
typedef                 tree<int, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const                   int _x[] = {-1, 0, 1, 0};
const                   int _y[] = {0, 1, 0, -1};
const                   char _step[] = {'U','R','D','L'};
 
const ll mod=1e9+7, N=1e6 + 7;
 
ll n, a[N], m;
vector <int> gra[N];
bool vis[N];
 
void input()
{
    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
}
 
void dfs(int s)
{
    vis[s] = true;
    for (auto &i:gra[s])
    if (!vis[i]) dfs(i);
}
 
void solve()
{
    int k = 0;
    vector <int> ans;
    fo(i,1,n)
    {
        if (!vis[i])
        {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << ans.size()-1 <<'\n';
    if (ans.size() - 1 == 0) return;
    fo(i,0,ans.size()-2)
        cout << ans[i] << ' ' << ans[i+1] <<'\n';
}
 
int main()
{
    FAST
    //freopen(".INP", "r", stdin);
    //freopen(".OUT", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
