//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2")
 
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <array>
#include <stack>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <random>
#include <ctime>
#include <bitset>
#include <valarray>
#include <fstream>
#include <sstream>
#include <unordered_map>
 
using namespace std;
typedef long long ll;
typedef unsigned long long unll;
#define fi first
#define se second
#define double long double
#define int long long
const int mod = 1073676287;
const int MAXN = 2 * 1.e5;
const int INF = 1.e16;
 
vector<vector<int>> adj;
vector<int> col;
 
bool dfs(int v, int p)
{
    if (p == v) col[v] = 1;
    else col[v] = 3 - col[p];
    for (int i = 0; i < adj[v].size(); ++i)
    {
        if (col[adj[v][i]] == col[v]) return 1;
        if (col[adj[v][i]] == 0)
        {
            if (dfs(adj[v][i], v)) return 1;
        }
    }
    return 0;
}
 
void solve()
{
    int n, m, c1, c2;
    cin >> n >> m;
    adj.resize(n);
    col.resize(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> c1 >> c2;
        --c1;
        --c2;
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }
    for (int i = 0; i < n; ++i)
    {
        if (col[i] == 0)
        {
            if (dfs(i, i))
            {
                cout << "IMPOSSIBLE" << '\n';
                return;
            }
        }
    }
    for (int i = 0; i < n; ++i) cout << col[i] << " ";
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, mode = 1;
    if (mode == 1) t = 1;
    else cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }
    return 0;
}
