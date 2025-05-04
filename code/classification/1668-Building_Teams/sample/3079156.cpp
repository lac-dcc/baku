#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("fma")*/
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
#define bust ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = INT_MAX;
const int N = 2 * 1e5 + 10;
const ld eps = 1e-9;
const int mod = 998244353;
 
vector < int > g[N];
int d[N];
bool ok = true ;
 
void dfs (int v, int c)
{
    d[v] = c;
    for (int to : g[v]) {
        if (d[to] == -1)
            dfs (to, c ^ 1);
        else {
            if (d[to] == d[v])
                ok = false ;
        }
    }
    return ;
}
 
void solve ()
{
    int n, m;
    cin >> n >> m;
    fill (d, d + N, -1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].pb (b);
        g[b].pb (a);
    }
    for (int i = 1; i <= n; ++i) {
        if (d[i] == -1) dfs (i, 0);
    }
    if (!ok) cout << "IMPOSSIBLE\n";
    else {
        for (int i = 1; i <= n; ++i)
            cout << d[i] + 1 << " ";
        cout << "\n";
    }
    return ;
}
 
int main()
{
    bust
   // freopen ("editors.in", "r", stdin);
   // freopen ("editors.out", "w", stdout);
 
    int t = 1;
    //cin >> t;
    //scanf ("%d", &t);
    while (t--)
        solve ();
    return 0;
}
