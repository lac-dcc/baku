/*
Problem Name: Cycle Finding
Problem Link: https://cses.fi/problemset/task/1197
Author:
*/
//----------HEADER----------
#include <bits/stdc++.h>
using namespace std;
 
//----------MACROS----------
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define nl cout << '\n'
#define IOS ios_base::sync_with_stdio(false)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rev(i, a, b) for (int i = a; i > b; --i)
#define sz size()
#define seea(a, x, y)           \
    for (int i = x; i < y; i++) \
    {                           \
        cin >> a[i];            \
    }
#define seev(v, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        v.pb(x);                \
    }
#define sees(s, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        s.insert(x);            \
    }
 
//----------CONSTANTS----------
const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
 
//----------SOLUTION----------
 
struct Edge
{
    int a, b, w;
};
 
void solve()
{
    // variable declaration
    int n, m;
    // variable read
    cin >> n >> m;
 
    vc<Edge> edges(m + n);
 
    Edge e;
    rep(i, 0, m)
    {
        cin >> e.a >> e.b >> e.w;
        edges[i] = e;
    }
    rep(i, m, m + n)
    {
        e.a = 0;
        e.b = i - m + 1;
        e.w = 0;
        edges[i] = e;
        // edges.pb(e);
    }
 
    // n+1 vertices, m+n edges
 
    vi dp(n + 1, inf);
    vi p(n + 1, -1);
    dp[0] = 0;
 
    int any;
    int x;
    rep(i, 0, n + 1)
    {
        any = 0;
        x = -1;
        for (Edge e : edges)
        {
            if (dp[e.a] < inf && dp[e.b] > dp[e.a] + e.w)
            {
                dp[e.b] = min(dp[e.b], dp[e.a] + e.w);
                any = 1;
                p[e.b] = e.a;
                x = e.b;
            }
        }
        if (!any)
            break;
    }
    if (!any)
    {
        // there does not exist any -ve wt cycle??
        cout << "NO";
        return;
    }
 
    // for (int x : dp)
    // {
    //     cout << x << ' ';
    // }
 
    // cout << x << any;
 
    // path construction
    if (x == -1)
    {
        // no cycle
        cout << "NO";
    }
    else
    {
        // cycle exists
        int y = x;
        rep(i, 0, n)
        {
            if (p[y] != 0)
                y = p[y];
        }
        vi path;
 
        for (int x = y;; x = p[x])
        {
            path.push_back(x);
            if (x == y && path.size() > 1)
            {
                break;
            }
        }
 
        reverse(path.begin(), path.end());
 
        cout << "YES" << endl;
        for (int x : path)
            cout << x << " ";
    }
}
 
//----------MAIN----------
signed main()
{
    //	int t; cin>>t; while(t--)
    solve();
}
