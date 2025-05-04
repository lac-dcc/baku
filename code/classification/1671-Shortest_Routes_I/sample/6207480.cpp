#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
 
using namespace std;
template <typename... T>
void see(T &...args) { ((cin >> args), ...); }
template <typename... T>
void put(T &&...args) { ((cout << args << " "), ...); }
template <typename... T>
void putl(T &&...args)
{
    ((cout << args << " "), ...);
    cout << '\n';
}
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << "=" << a << ", ";
    err(++it, args...);
}
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
#define L cout << '\n';
#define E cerr << '\n';
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rev(i, a, b) for (int i = a; i > b; --i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define setpr(x) cout << setprecision(x) << fixed
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
        v.push_back(x);         \
    }
#define sees(s, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        s.insert(x);            \
    }
// const ld ep = 0.0000001;
// const ld pi = acos(-1.0);
// const ll md = 1000000007;
 
void solve(){
    int n,m;
    see(n,m);
    vector<vector<pii>> v(n);
    while(m--)
    {
        int x,y,z;see(x,y,z);
        x--,y--;
        v[x].pb({y,z});
    }
    vector<ll> dist(n,1e18);
    dist[0]=0;
    priority_queue<pii,vii,greater<pii>> q;
    vector<bool> vis(n,0);
    q.push({0,0});
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x]=1;
        for(auto y : v[x])
        {
            if(dist[y.first] > dist[x]+y.second)
            {
                dist[y.first] = dist[x]+y.second;
                q.push({dist[y.first],y.first});
            }
        }
    }
    for(auto x : dist)
        cout<<x<<" ";
} 
 
signed main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t tStart = clock();
#endif
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
        // cout<<'\n';
    }
#ifndef ONLINE_JUDGE
    
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
#endif
}