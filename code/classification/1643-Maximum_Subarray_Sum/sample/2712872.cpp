#include <bits/stdc++.h>
 
using namespace std;
 
void solve();
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef double db;
typedef char ch;
#define pll pair<ll, ll>
#define mpll map<ll, ll>
#define mpch map<ch, ll>
#define vll vector<ll>
#define vpll vector<pll>
#define str string
#define si size()
typedef char ch;
#define be begin()
#define en end()
#define vs vector<string>
#define vc vector<char>
#define ppi pair < int, pair<int, int>
#define minh priority_queue<int, vector<int>, greater<int>>
#define min_pair priority_queue<ppi, vector<ppi>, greater<ppi>>
#define maxh priority_queue<int>
#define max_pair priority_queue<ppi>
#define sll set<ll>
#define loop(i, n) for (int i = 0; i < n; ++i)
#define pi 3.14159265358979323846264338327
#define nope string::npos
#define max2(a, b) ((a < b) ? b : a)
#define max3(a, b, c) max2(max2(a, b), c)
#define min2(a, b) ((a > b) ? b : a)
#define min3(a, b, c) min2(min2(a, b), c)
 
/*..............................................................................................................................
 
                            Ashish Ranjan
 
...............................................................................................................................*/
 
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
 
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
 
/*.......................................................................................................*/
 
int main()
{
 
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
 
    fast();
 
    // int tc;
    // cin >> tc;
    // while (tc--)
    // {
    //     solve();
    //     debug("........");
    // }
 
    solve();
    return 0;
}
 
 
void solve()
{
    ll n,sum=0,ans=INT_MIN;
    cin>>n;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        sum+=x;
        ans=max(ans,sum);
        if(sum<0)
            sum=0;
    }
    cout<<ans<<"\n";
}
 
    