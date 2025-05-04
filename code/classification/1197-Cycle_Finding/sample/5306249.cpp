#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";
#define forn(a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define hhh cout << "here" << endl;
#define int long long int
#define ld long double
#define mod1 1000000007
#define mod2 998244353
struct edge
{
    int a, b, cost;
};
const int MAXN = 2502;
const int MAXM = 5002;
const int INF = 1e18;
const int negINF = -1e18;
vector<edge> e(MAXM);
vi d(MAXN, 0);
vi p(MAXN, -1);
void solve()
{
    int n, m;
    cin >> n >> m;
 
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    d[0] = 0;
    int x;
    for (int i = 0; i < n; ++i)
    {
        x = -1;
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = max(-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }
 
    if (x == -1)
        cout << "NO";
    else
    {
        int y = x;
        for (int i = 0; i < n; ++i)
            y = p[y];
 
        vector<int> path;
        for (int cur = y;; cur = p[cur])
        {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());
 
        cout << "YES";
        nl;
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << ' ';
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        nl;
    }
    return 0;
}
